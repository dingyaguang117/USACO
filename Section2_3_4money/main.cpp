/*
ID:dingyag1
LANG:C++
TASK:money
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int V,N,M[25];

long long dp[10001];

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int i,j,mon;
	cin>>V>>N;
	dp[0]=1;
	for (i=0;i<V;++i)
	{
		cin>>mon;
		for (j=mon;j<=N;++j)
		{
			dp[j]+=dp[j-mon];
		}
	}
	cout<<dp[N]<<endl;

	return 0;
}

