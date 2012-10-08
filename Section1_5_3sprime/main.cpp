/*
ID:dingyag1
LANG:C++
TASK:sprime
*/

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;
int n;
bool flood[10000];
int leng;
int prime[4000];

void getPrime()
{
	int i,j;
	leng=1;
	prime[0]=2;

	flood[2]=0;
	for (i=3;i<100;i+=2)
	{
		if(!flood[i])
			for (j=i+i;j<10000;j+=i)
		{
			flood[j]=1;
		}
	}
	for (i=3;i<10000;i+=2)
	{

		if (!flood[i])
		{
			prime[leng++]=i;
		}
	}
}

bool isPrime(int num)
{
	//return true;
	int i;
	for (i=0;prime[i]<sqrt(num)+1;++i)
	{
		if (num%prime[i]==0)
		{
			return false;
		}
	}
	return true;
}

void todo(vector<int> a,int i)
{
	vector<int> b;
	int ii,t,j;
	if(i==n)
	{
		for(ii=0;ii<a.size();++ii)
			cout<<a[ii]<<endl;
		return;
	}
	for(ii=0;ii<a.size();++ii)
	{
		t=a[ii]*10;
		for(j=1;j<10;j+=2)
		{
			if(isPrime(t+j))
				b.push_back(t+j);
		}
	}

	todo(b,i+1);

}

int main()
{
	freopen("sprime.in","r",stdin);
	freopen("sprime.out","w",stdout);
	vector<int> a;
	getPrime();
	cin>>n;

	a.push_back(2);
	a.push_back(3);
	a.push_back(5);
	a.push_back(7);

	todo(a,1);


	return 0;
}
