/*
ID:dingyag1
LANG:C++
TASK:stamps
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int dp[2000001];
bool can[2000001];
int main()
{
	freopen("stamps.in","r",stdin);
	freopen("stamps.out","w",stdout);
	int i,j,N,K,v;

	cin>>K>>N;
	can[0]=1;
	for (i=1;i<2000001;++i)
	{
		dp[i]=-1;
	}
	for (i=1;i<=N;++i)
	{
		cin>>v;
		for (j=v;j<=2000000;++j)
		{
			if(can[j-v] && (dp[j]==-1 || dp[j] > dp[j-v]+1))
			{
				dp[j]=dp[j-v]+1;
				can[j]=1;
				
			}
		}
	}
	for (i=1;;++i)
	{
		if (!can[i] || dp[i]>K)
		{
			cout<<i-1<<endl;
			break;
		}
	}
	return 0;
}

