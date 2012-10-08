/*
ID:dingyag1
LANG:C++
TASK:ariprog
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
bool a[500*500];
int b[250*200];

int main()
{
	freopen("ariprog.in","r",stdin);
	freopen("ariprog.out","w",stdout);
	int n,m,p,q,i,k,j,l,maxspace,t,m2,len=0;
	bool f,none=1,pass;
	cin>>n>>m;
	/*for (i=0;i<=m*m;++i)
	{
		a[i]=0;
	}*/
	for (p=0;p<=m;++p)
	{
		for (q=0;q<=m;++q)
		{
			t=p*p+q*q;
			a[t]=1;

		//	cout<<p*p+q*q<<" ";
		}
	}
	for (i=0;i<=m*m;++i)
	{
			if (a[i])
			{
				b[len++]=i;
			}
			
	}



	maxspace=m*m*2/(n-1)+1;
	for (i=1;i<maxspace;++i)
	{
		
		for (j=0;j<len-n+2;++j)
		{
			f=0;
			t=b[j];
			
			for (k=1;k<n;++k)
			{
				t+=i;
				if(a[t]==0)
				{
					f=1;
					break;
				}
			}
			if (!f)
			{
				cout<<b[j]<<" "<<i<<endl;
				none=0;
			}
		}
	}

	if (none)
	{
		cout<<"NONE"<<endl;
	}
	return 0;
}