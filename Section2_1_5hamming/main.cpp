/*
ID:dingyag1
LANG:C++
TASK:hamming
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int N,B,D;

unsigned short result[64];

bool isOK(unsigned short a,unsigned short b)
{
	unsigned short t=1;

	a^=b;
	int n=0,i;
	for (i=0;i<B;++i)
	{
		if (t&a)
		{
			++n;
		}
		a>>=1;
	}
	return n>=D;
}


int main()
{
	freopen("hamming.in","r",stdin);
	freopen("hamming.out","w",stdout);
	int j,len;
	unsigned short i;
	bool done=0,fail;
	cin>>N>>B>>D;
	
	result[0]=0;
	len=1;
	for (i=1;i<(1<<B);++i)
	{
		if (done)
		{
			break;
		}
		fail=0;
		for (j=0;j<len;++j)
		{
			if (!isOK(i,result[j]))
			{
				fail=1;
				break;
			}
		
		}
		if (!fail)
		{
			result[len++]=i;
			if (len==N)
			{
				done=1;
			}
		}

	}

	cout<<result[0];
	for (i=1;i<N;++i)
	{
		if (i%10==0)
		{
			cout<<endl<<result[i];
			continue;
		}
		cout<<" "<<result[i];
	}
	cout<<endl;
	return 0;
}