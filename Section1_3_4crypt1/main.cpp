/*
ID:dingyag1
LANG:C++
TASK:crypt1
*/

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int n,a[9];


bool exist(int num)
{
	int i;
	for (i=0;i<n;++i)
	{
		if (a[i]==num)
		{
			return true;
		}
	}
	return false;
}

bool p1(int a,int b,int c,int d)
{
	int t;
	if ((t=(a*100+b*10+c)*d)>999)
	{
		return false;
	}
	while (t!=0)
	{
		if (!exist(t%10))
		{
			return false;
		}
		t/=10;
	}
	return true;
}

bool p2(int a,int b,int c,int d,int e)
{
	int t;
	if ((t=(a*100+b*10+c)*(10*d+e))>9999)
	{
		return false;
	}
	while (t!=0)
	{
		if (!exist(t%10))
		{
			return false;
		}
		t/=10;
	}
	return true;
}



int main()
{
	freopen("crypt1.in","r",stdin);
	freopen("crypt1.out","w",stdout);

	int i,j,k,l,m,num=0;
	cin>>n;
	for (i=0;i<n;++i)
	{
		cin>>a[i];
	}

	for (i=0;i<n;++i)
	{
		for (j=0;j<n;++j)
		{
			for (k=0;k<n;++k)
			{
				for (l=0;l<n;++l)
				{
					for (m=0;m<n;++m)
					{
						if (p1(a[i],a[j],a[k],a[l])&&p1(a[i],a[j],a[k],a[m])&&p2(a[i],a[j],a[k],a[l],a[m]))
						{
							num++;
						}
					}
				}
			}
		}
	}
	
	cout<<num<<endl;

	return 0;
}