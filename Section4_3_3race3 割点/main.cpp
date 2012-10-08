/*
ID:dingyag1
LANG:C++
TASK:race3
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
using namespace std;

int map[55][55];
int deep[55];
int N;

void cpt_deep(int begin,int end)
{
	queue<int> que;
	int front;
	bool visited[55]={0};
	
	que.push(begin);
	visited[begin]=1;
	deep[begin]=1;
	while (!que.empty())
	{
		front=que.front();
		que.pop();
		for (int i=0;i<N;++i)
		{
			if (!visited[i] && map[front][i])
			{
				deep[i]=deep[front]+1;
				que.push(i);
				visited[i]=1;
			}
		}
	}
}



bool check(int ck,int begin,int end)
{
	queue<int> que;
	int front;
	bool visited[55]={0};
	
	que.push(begin);
	visited[begin]=1;
	while (!que.empty())
	{
		front=que.front();
		que.pop();
		for (int i=0;i<N;++i)
		{
			if (i!=ck && !visited[i] && map[front][i])
			{
				if (i==end)
				{
					return false;
				}
				que.push(i);
				visited[i]=1;
			}
		}
	}
	
	return true;
}

bool check2(int ck)
{
	queue<int> que;
	int front;
	bool visited[55]={0};
	
	que.push(ck);
	visited[ck]=1;
	while (!que.empty())
	{
		front=que.front();
		que.pop();
		for (int i=0;i<N;++i)
		{
			if (!visited[i] && map[front][i])
			{
				if (deep[i]<deep[ck])
				{
					return false;
				}
				que.push(i);
				visited[i]=1;
			}
		}
	}
	
	return true;
}
int main()
{
	freopen("race3.in","r",stdin);
	freopen("race3.out","w",stdout);
	
	int i,j,a,b,n1=0,n2=0;
	int r1[55],r2[55];
	
	N=0;
	cin>>b;
	while (b!=-1)
	{
		if (b==-2)
		{
			N++;
		}
		map[N][b]=1;
		cin>>b;
	}
	
	//############ question 1
	
	for (i=1;i<N-1;++i)
	{
		if (check(i,0,N-1))
		{
			r1[n1++]=i;
		}
		
	}
	cout<<n1;
	for (i=0;i<n1;++i)
	{
		cout<<" "<<r1[i];
	}
	cout<<endl;
	//########### question 2
	cpt_deep(0,N-1);

	for (i=0;i<n1;++i)
	{
		if (check2(r1[i]))
		{
			r2[n2++]=r1[i];
		}
	}

	cout<<n2;
	for (i=0;i<n2;++i)
	{
		cout<<" "<<r2[i];
	}
	cout<<endl;


	
	return 0;
}

