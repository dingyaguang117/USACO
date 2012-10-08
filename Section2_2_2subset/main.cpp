/*
ID:dingyag1
LANG:C++
TASK:subset
*/

#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

unsigned int  dp[800][39];
unsigned int n;

unsigned int go( int sum, int pos)
{
	unsigned int r;
	if (sum==0)
	{
		return 1; 
	}
	if (sum<0)
	{
		return 0;
	}
	if (pos<1)
	{
		return 0;
	}
	if (dp[sum][pos])
	{
		return dp[sum][pos];
	}
	if (sum>pos*(pos+1)/2)
	{
		return 0;
	}
	else
	if (sum==pos*(pos+1)/2)
	{
		return 1;
	}
	r=go(sum,pos-1);
	r+=go(sum-pos,pos-1);
	dp[sum][pos]=r;
	return r;
}

int main()
{
	//freopen("subset.in","r",stdin);
	//freopen("subset.out","w",stdout);

	while(cin>>n)
	{
		memset(dp,0,sizeof(dp));
	if (n*(n+1)/2%2==1)
	{
		cout<<0<<endl;
		return 0;
	}
	cout<<go(n*(n+1)/2/2,n)/2<<endl;
	}
	return 0;
}