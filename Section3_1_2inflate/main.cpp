/*
ID:dingyag1
LANG:C++
TASK:inflate
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int dp[10001];
bool can[10001];
int main()
{
	freopen("inflate.in","r",stdin);
	freopen("inflate.out","w",stdout);
	
	int T,N,i,j,val,time;
	cin>>T>>N;
	can[0]=1;
	for (i=0;i<N;++i)
	{
		cin>>val>>time;
		for (j=time;j<=T;++j)
		{
			if (can[j-time] && dp[j-time]+val>dp[j])
			{
				dp[j]=dp[j-time]+val;
				can[j]=1;
			}
		}
	}

	cout<<dp[T]<<endl;

	
	return 0;
}

