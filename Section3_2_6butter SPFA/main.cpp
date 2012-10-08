/*
ID:dingyag1
LANG:C++
TASK:butter
*/

#include <stdio.h>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#define MAXV 802
#define MAXD 10000000
using namespace std;
//////////////////////////
class edge
{
public:
int a,b,w;

edge & operator = (const edge &B)
{
	a=B.a;
	b=B.b;
	w=B.w;
	return *this;
}
};

bool cmp (const edge &A,const edge &B)
{
	if (A.a<B.a)
		return true;
	if (A.a==B.a)
	{
		if (A.b<B.b)
		{
			return true;
		}
	}
	return false;
}
//////////////////////////

////////////////////////
int Map[MAXV][MAXV];
int had[MAXV];			//have cow
edge E[3000]={0};			//edge
int index[MAXV][2];		//index[i][0] : pos  index[i][1] : end+1

void SPFA(int s)
{
	queue<int> que;
	int dis[MAXV];
	bool in[MAXV]={0};
	int i;
	edge e;

	for (i=0;i<MAXV;++i)
	{
		dis[i]=MAXD;
	}
	dis[s]=0;

	que.push(s);
	in[s]=1;

	while(!que.empty())
	{
		for(i=index[que.front()][0];i<index[que.front()][1];++i)
		{
			if (dis[E[i].a]+E[i].w<dis[E[i].b])
			{
				dis[E[i].b]=dis[E[i].a]+E[i].w;
				if (!in[E[i].b])
				{
					que.push(E[i].b);
					in[E[i].b]=1;
				}
			}
				
		}
		in[que.front()]=0;
		que.pop();
		

	}
//返回s点出发的最短路径的 结果到map
	for (i=0;i<MAXV;++i)
	{
		Map[s][i]=dis[i];
	}


}


int main()
{
	freopen("butter.in","r",stdin);
	freopen("butter.out","w",stdout);
	int i,j,k,N,P,C,d,len,sum,min=10000000;
	int nE=0;
	edge e;
	
	cin>>N>>P>>C;
	len=P;
	for (i=0;i<N;++i)
	{
		cin>>j;
		had[j]+=1;
	}
	for (i=1;i<=P;++i)
	{
		for (j=1;j<=P;++j)
		{
			if (i==j)
			{
				Map[i][i]=0;
			}
			else
			{
				Map[i][j]=0x0FFFFFFF;
			}
		}
	}
	for (i=0;i<C;++i)
	{
		cin>>j>>k>>d;
		Map[k][j]=d;
		Map[j][k]=d;
		E[nE].a=j;
		E[nE].b=k;
		E[nE++].w=d;
		E[nE].b=j;
		E[nE].a=k;
		E[nE++].w=d;
		
	}

	sort(E,E+nE,cmp);

	index[E[0].a][0]=0;
	//index[E[0].a][1]=1;
	for (i=1;i<nE;++i)
	{
		if (E[i].a!=E[i-1].a)
		{
			index[E[i].a][0]=i;
			index[E[i-1].a][1]=i;
		}
	}
	index[E[i-1].a][1]=i;

/*

	for (k=1;k<=len;++k)
	{
		for (i=1;i<=len;++i)
		{
			for (j=1;j<=len;++j)
			{
				if (Map[i][k]+Map[k][j]<Map[i][j])
				{
					Map[i][j]=Map[i][k]+Map[k][j];
				}
			}
		}
	}
*/

	for (i=1;i<=P;++i)
	{
		SPFA(i);
	}


	for (i=1;i<=P;++i)
	{
		sum=0;
		for (j=1;j<=P;++j)
		{
			if (had[j])
			{
				sum+=Map[i][j]*had[j];
			}
		}
		if (sum<min)
		{
			min=sum;
		}
	}
	cout<<min<<endl;

	return 0;
}



