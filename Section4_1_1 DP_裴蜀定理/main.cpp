/*
ID:dingyag1
LANG:C++
TASK:nuggets
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

bool dp[256*256+1];

int gcd(int a,int b)
{
	int t;
	if (a<b)
	{
		t=a;
		a=b;
		b=t;
	}
	if (b==0)
	{
		return a;
	}
	while(a%b!=0)
	{
		t=b;
		b=a%b;
		a=t;
	}
	return b;
	
}



int main()
{
	freopen("nuggets.in","r",stdin);
	freopen("nuggets.out","w",stdout);
	int N,p[12];
	int i,j;
	dp[0]=1;
	cin>>N;
	for (i=0;i<N;++i)
	{
		cin>>p[i];
		for (j=p[i];j<=256*256;++j)
		{
			if (dp[j-p[i]]!=0)
			{
				dp[j]=1;
			}
		}
	}
	
	int gccd=p[0];
	for (i=0;i<N;++i)
	{
		gccd=gcd(p[i],gccd);
	}
	if (gccd>1)
	{
		cout<<0<<endl;
		return 0;
	}
	for (i=256*256;i>=1;--i)
	{
		if (!dp[i])
		{
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<0<<endl;
	
	return 0;
}

