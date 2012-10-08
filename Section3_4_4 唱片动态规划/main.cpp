
/*
ID:dingyag1
LANG:C++
TASK:rockers
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int dp[20][20][2]={0};

int main()
{
	freopen("rockers.in","r",stdin);
	freopen("rockers.out","w",stdout);
	int N,T,M,S[23],tmp[2];
	int i,j;

	cin>>N>>T>>M;
	for (i=1;i<=N;++i)
	{
		cin>>S[i];
		if (S[i]>T)
		{
			N--;
			i--;
		}
	}

	for (j=1;j<=N;++j)
	{
		dp[j][j-1][0]=10000000;
	}

	for (j=1;j<=N;++j)
	{
		for (i=1;i<=j;++i)
		{
			tmp[0]=dp[i-1][j-1][0];
			tmp[1]=dp[i-1][j-1][1];
			if (S[j]>T-tmp[1])
			{
				tmp[0]+=1;
				tmp[1]=S[j];
			}
			else
			{
				tmp[1]+=S[j];
			}

			if (tmp[0]<dp[i][j-1][0] ||(tmp[0]==dp[i][j-1][0] && tmp[1]<dp[i][j-1][1]))
			{
				dp[i][j][0]=tmp[0];
				dp[i][j][1]=tmp[1];
			}
			else
			{
				dp[i][j][0]=dp[i][j-1][0];
				dp[i][j][1]=dp[i][j-1][1];
			}
		}
	}
	int max=0;
	for (j=1;j<=N;++j)
	{
		for (i=0;i<=j;++i)
		{
			int tt=dp[i][j][0];
	//		cout<<i<<j<<" "<<dp[i][j][0]<<":"<<dp[i][j][1]<<endl;
			if (dp[i][j][1])
			{
				tt+=1;
			}
			if (tt<=M)
			{
				if (i>max)
				{
					max=i;
				}
			}
		}
	}

	cout<<max<<endl;
	return 0;
}

