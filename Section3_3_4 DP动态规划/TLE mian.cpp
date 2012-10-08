/*
ID:dingyag1
LANG:C++
TASK:range
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
using namespace std;

int N;
bool data[251][251];
int dp[251][251];
int statics[251];
class sqr
{
public:
	int i,j,n;
};

int main()
{
	freopen("range.in","r",stdin);
	freopen("range.out","w",stdout);
	int i,j;
	char c;
	sqr sqr1;
	queue<sqr> que;

	cin>>N;
	for (i=0;i<N;++i)
	{
		for (j=0;j<N;++j)
		{
			cin>>c;
			data[i][j]=(c=='1');
		}
	}
	for (i=0;i<N-1;++i)
	{
		for (j=0;j<N-1;++j)
		{
			if (data[i][j] && data[i+1][j] && data[i][j+1] && data[i+1][j+1])
			{
				sqr1.i=i;sqr1.j=j;sqr1.n=2;
				statics[2]+=1;
				que.push(sqr1);
			}
		}
	}
	
	while (!que.empty())
	{
		sqr1=que.front();
		if (sqr1.i+sqr1.n-2<N && sqr1.j+sqr1.n-2<N)
		{
			bool f=0;
			for (i=sqr1.i;i<=sqr1.i+sqr1.n;++i)
			{
				if (!data[i][sqr1.j+sqr1.n])
				{
					f=1;
					break;
				}
			}
			for (j=sqr1.j;j<=sqr1.j+sqr1.n;++j)
			{
				if (!data[sqr1.i+sqr1.n][j])
				{
					f=1;
					break;
				}
			}

			if (!f)
			{
				sqr1.n+=1;
				statics[sqr1.n]+=1;
				que.push(sqr1);
			}
		}

		que.pop();
	}

	for (i=2;i<=N;++i)
	{
		if (statics[i])
		{
			cout<<i<<" "<<statics[i]<<endl;
		}
	}
	
	return 0;
}

