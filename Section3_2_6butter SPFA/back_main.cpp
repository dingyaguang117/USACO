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
#define MAXV 800
#define MAXD 10000000
using namespace std;
//////////////////////////
class edge
{
public:
int a,b,w;
};
bool operator <(const edge &A,const edge &B)
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
class p_v	//权重优先节点
{
public:
	int dis,v;
};
bool operator <(const p_v &A,const p_v &B)
{
	return A.dis<B.dis;
}
////////////////////////
int Map[801][801];
int had[801];
set<edge> E;
map<int,set<edge>::iterator> index;

void createdindex()
{
	set<edge>::iterator it=E.begin();
	while (it!=E.end())
	{
		index.insert(map<int,set<edge>::iterator>::value_type(it->a,it));
		++it;
	}
}




int main()
{
	freopen("butter.in","r",stdin);
	freopen("butter.out","w",stdout);
	int i,j,k,N,P,C,d,len,sum,min=10000000;
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
		e.a=j;e.b=k;e.w=d;
		E.insert(e);
		e.a=k;e.b=j;e.w=d;
		E.insert(e);
		Map[k][j]=d;
		Map[j][k]=d;
	}
	createdindex();


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



