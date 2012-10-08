/*
ID:dingyag1
LANG:C++
TASK:frac1
*/

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int a[15000][2];

bool isInerPrime(int i,int j)//i<j
{
	int t;
	while (j%i!=0)
	{
		t=i;
		i=j%i;
		j=t;
	}
	if (i==1)
	{
		return true;
	}
	return false;
}
int cmp(const void *a,const void *b)
{
	return ((int*)a)[0]*((int*)b)[1]-((int*)b)[0]*((int*)a)[1];
}

int main()
{
	freopen("frac1.in","r",stdin);
	freopen("frac1.out","w",stdout);
	int n,i,j,length=0;

	cin>>n;
	a[0][0]=0;
	a[0][1]=1;
	length=1;

	for (i=1;i<=n;++i)
	{
		a[length][1]=i;
		a[length++][0]=1;
		for (j=2;j<i;++j)
		{
			if (isInerPrime(j,i))
			{
				a[length][1]=i;
				a[length++][0]=j;
				
			}
		}
	}
	qsort(a,length,sizeof(int)*2,cmp);
	for (i=0;i<length;++i)
	{
		cout<<a[i][0]<<"/"<<a[i][1]<<endl;
	}



	return 0;
}
