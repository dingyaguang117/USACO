/*
ID:dingyag1
LANG:C++
TASK:milk6
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#define  inf		210000000000000
//#define  __int64 int
#define  __int64 long long
using namespace std;

class edge
{
public:
	int a,b,w;
	edge(int a1,int b1,int w1):a(a1),b(b1),w(w1){};
};

vector<edge> E;
int N,M;
__int64 map[201][201];
__int64 old[201][201];
__int64 path[201][2];		//0 前一个的坐标   1 max-flow
bool steped[201];

__int64 min(const __int64 &a, const __int64 &b)
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
				path[i][1]=min(map[tmp][i]+0.1,path[tmp][1]);
				que.push(i);
			}
		}
		
		que.pop();
	}
	
}

__int64 max_flow()
{
	__int64 maxv=0;
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


void floodfill(int n)
{
	steped[n]=1;
	for (int i=1;i<=M;++i)
	{
		if (map[n][i]>0 && !steped[i])
		{
			floodfill(i);
		}
	}
}




int main()
{
	freopen("milk6.in","r",stdin);
	freopen("milk6.out","w",stdout);
	
	int i,j,k,a,b,w;

	cin>>M>>N;

	for (i=0;i<N;++i)
	{
		cin>>a>>b>>w;
		map[a][b]+=w*1001+1;
		E.push_back(edge(a,b,w));
	}
	
	for (i=1;i<=M;++i)
	{
		for (j=1;j<=M;++j)
		{
			old[i][j]=map[i][j];
		}
	}

	__int64 r=max_flow();
	cout<<r/1001<<" "<<r%1001<<endl;
//寻找 断点。。即残留网络中 的
//	bfs();
//	path[1][0]=1;		//标记1被floodfill
/*
	floodfill(1);
	if(r/1001 !=0)
	for (i=0;i<E.size();++i)
	{
		if ((steped[E[i].a] && !steped[E[i].b]) )
		{
			cout<<i+1<<endl;
		}
	}
*/	
	__int64 r2;

	

	for (i=0;i<E.size();++i)
	{
		
		

		old[E[i].a][E[i].b]-=E[i].w*1001+1;

		for (k=1;k<=M;++k)
		{
			for (j=1;j<=M;++j)
			{
				map[k][j]=old[k][j];
			}
		}
		
		r2=max_flow();
		
		if (r2==r-E[i].w*1001-1)
		{
			cout<<i+1<<endl;
			r=r2;
		}else
		{
			old[E[i].a][E[i].b]+=E[i].w*1001+1;
		}
	
	}
	return 0;
}

