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

inline int min(int a,int b,int c)
{
	int t;
	t=a<b?a:b;
	t=t<c?t:c;
	return t;
} 

int N;
bool data[251][251];
int dp[251][251];
int statics[251];
class sqr
{
public:
	int i,j,n;
};

void go(int h)
{
	int i;
	for (i=2;i<=h;++i)
	{
		statics[i]+=1;
	}
}

int main()
{
	freopen("range.in","r",stdin);
	freopen("range.out","w",stdout);
	int i,j;
	char c;

	cin>>N;
	for (i=0;i<N;++i)
	{
		for (j=0;j<N;++j)
		{
			cin>>c;
			data[i][j]=(c=='1');
		}
	}

	for (i=0;i<N;++i)
	{
		dp[i][N-1]=data[i][N-1];
		dp[N-1][i]=data[N-1][i];
	}

	for (i=N-2;i>=0;--i)
	{
		for (j=N-2;j>=0;--j)
		{
			if(data[i][j])
			dp[i][j]=min(dp[i+1][j],dp[i][j+1],dp[i+1][j+1])+1;
			else
				dp[i][j]=0;
		}
	}
	for (i=N-2;i>=0;--i)
	{
		for (j=N-2;j>=0;--j)
		{
			go(dp[i][j]);
		}
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

