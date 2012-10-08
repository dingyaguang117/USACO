/*
ID:dingyag1
LANG:C++
TASK:fence9
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;


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
	freopen("fence9.in","r",stdin);
	freopen("fence9.out","w",stdout);
	int m,n,p;
	int s2,nbian;
	cin>>m>>n>>p;
	s2=p*n;
	if (p<=m)
	{
		nbian=gcd(m,n)+gcd(n,m-p)+p;
	}
	else
	{
		nbian=gcd(m,n)+gcd(n,p-m)+p;
	}

	cout<<(s2+2-nbian)/2<<endl;

	
	
	return 0;
}

