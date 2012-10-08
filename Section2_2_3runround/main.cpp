/*
ID:dingyag1
LANG:C++
TASK:runround
*/

#include <stdio.h>
#include <iostream>

using namespace std;

bool isRR(int i)
{
	int t=i,len=0;
	bool a[10]={0};
	int b[9];
	while (t!=0)
	{
		if (a[t%10])
		{
			return false;
		}
		a[t%10]=1;
		b[len++]=t%10;
		t/=10;
	}

	for (i=0;i<10;++i)
	{
		a[i]=0;
	}
	
	for (i=0;i<len/2;++i)
	{
		t=b[i];
		b[i]=b[len-i-1];
		b[len-1-i]=t;
	}

	t=0;
	for (i=0;i<len;++i)
	{
		t=(t+b[t])%len;
		if (a[t])
		{
			return false;
		}
		a[t]=1;
	}
	return true;

}

int main()
{
	freopen("runround.in","r",stdin);
	freopen("runround.out","w",stdout);
	int n,i;
	cin>>n;
	for (i=n+1;;++i)
	{
		if (isRR(i))
		{
			cout<<i<<endl;
			break;
		}
	}

	return 0;
}