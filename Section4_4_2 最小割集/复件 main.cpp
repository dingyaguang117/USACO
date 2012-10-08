/*
ID:dingyag1
LANG:C++
TASK:milk6
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#define  inf		1000000000
using namespace std;

class edge
{
public:
	int a,b,w;
	edge(int a1,int b1,int w1):a(a1),b(b1),w(w1){};
};

vector<edge> E;
int N,M;
int map[201][201];
int path[201][2];		//0 前一个的坐标   1 max-flow

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

double max_flow()
{
	double maxv=0;
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
	freopen("milk6.in","r",stdin);
	freopen("milk6.out","w",stdout);
	
	int i,j,a,b,w;

	cin>>N>>M;

	for (i=0;i<M;++i)
	{
		cin>>a>>b>>w;
		map[a][b]+=w*1001+1;
		E.push_back(edge(a,b,w));
	}

	M=N;
	double r=max_flow();
	cout<<(int)(r+0.001)/1001<<" "<<(int)(r+0.001)%1001<<endl;
//寻找 断点。。即残留网络中 的
	path[1][0]=1;		//标记1被floodfill
	if((int)(r+0.001)/1001 !=0)
	for (i=0;i<E.size();++i)
	{
		if ((path[E[i].a][0]==0 && path[E[i].b][0]!=0) || (path[E[i].a][0]!=0 && path[E[i].b][0]==0))
		{
			cout<<i+1<<endl;
		}
	}
	
	return 0;
}

