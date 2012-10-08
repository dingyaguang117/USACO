/*
ID:dingyag1
LANG:C++
TASK:shuttle
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	freopen("shuttle.in","r",stdin);
	freopen("shuttle.out","w",stdout);
	int danding[200]={0};
	int n,i,j,len=0;
	int zhengfu=1;
	cin>>n;
//##########################
	for (i=1;i<n;++i)
	{
		for (j=1;j<=i;++j)
		{
			danding[len++]=2*zhengfu;
		}
		danding[len++]=zhengfu;
		if (i!=n)
		{
			zhengfu=-zhengfu;
		}		
	}
	
	for (i=n;i>0;--i)
	{
		for (j=1;j<=i;++j)
		{
			danding[len++]=2*zhengfu;
		}
		zhengfu=-zhengfu;
		danding[len++]=zhengfu;
		
	}
//####################################
	cout<<n;
	for (i=0;i<len;++i)
	{
		if (i%20==19)
		{
			cout<<endl;
		}else
			cout<<" ";
		cout<<(n+=danding[i]);
		
	}
	cout<<endl;
	
	return 0;
}

