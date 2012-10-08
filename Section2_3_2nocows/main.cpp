/*
ID:dingyag1
LANG:C++
TASK:nocows
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int dp[200][100]={0};		//dp[node][deep]
int node,deep;
int main()
{
	freopen("nocows.in","r",stdin);
	freopen("nocows.out","w",stdout);
	int i,j,k;
	cin>>node>>deep;
	for (i=0;i<node;++i)
	{
		dp[1][i]=1;
	}

	for (j=2;j<=deep;++j)
	{
		for (i=3;i<=node;i+=2)
		{
			dp[i][j]=0;
			for (k=1;k<i-1;k+=2)
			{
				dp[i][j]+=dp[k][j-1]*dp[i-1-k][j-1];
				dp[i][j]%=9901;
			}
			//dp[i][j]%=9901;
		}
	}/*
	for (j=1;j<=deep;++j)
	{
		for (i=1;i<=node;i++)
		{
			dp[i][j]=0;
			for (k=1;k<i;++k)
			{
				dp[i][j]+=dp[k][j-1]*dp[i-1-k][j-1];
			}
			
		}
	}*/
	cout<<(dp[node][deep]-dp[node][deep-1]+9901)%9901<<endl;
	return 0;
}

