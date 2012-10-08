/*
ID:dingyag1
LANG:C++
TASK:stall4
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
using namespace std;

#define  inf		1000000000
int N,M,sum;
int map[405][405];
int path[405][2];		//0 前一个的坐标   1 max-flow

int min(const int &a, const int &b)
{
	return a<b?a:b;
}

void bfs()
{
	queue<int> que;
	int i,tmp;
	path[M][0]=0;
	path[1][1]=inf;
	path[1][0]=-1;
	for (i=2;i<=M;++i)
	{
		path[i][0]=0;
	}
	que.push(1);
	while (!que.empty())
	{
		tmp=que.front();
		for (i=1;i<=M;++i)
		{
			if (i!=tmp && map[tmp][i]>0 && !path[i][0])
			{
				path[i][0]=tmp;
				path[i][1]=min(map[tmp][i],path[tmp][1]);
				que.push(i);
			}
		}	
		que.pop();
	}
}

int max_flow()
{
	int maxv=0;
	int cur;
	while (1)
	{
		bfs();
		if (path[M][0]==0)
		{
			return maxv;
		}
		else
		{
			maxv+=path[M][1];
		}	
		//按照path 更改map
		cur=M;
		while (path[cur][0]!=-1)
		{
			map[path[cur][0]][cur] -= path[M][1];
			map[cur][path[cur][0]] += path[M][1];
			cur=path[cur][0];
		}
	}	
}


int main()
{
	freopen("stall4.in","r",stdin);
	freopen("stall4.out","w",stdout);
	
	int i,n,a,b,j;

	cin>>N>>M;

	for (i=2;i<=N+1;++i)
	{
		cin>>n;
		for (j=0;j<n;++j)
		{
			cin>>b;
			map[i][N+1+b]=1;
		}
	}

	for (i=2;i<=N+1;++i)
	{
		map[1][i]=1;
	}
	for (i=N+2;i<=N+M+1;++i)
	{
		map[i][N+M+2]=1;
	}
	
	M=M+N+2;
	cout<<max_flow()<<endl;
	return 0;
}

