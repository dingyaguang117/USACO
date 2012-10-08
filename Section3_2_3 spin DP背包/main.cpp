/*
ID:dingyag1
LANG:C++
TASK:spin
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

bool C[5][360];
int v[5];
int p[5];

void go()
{
	int i;
	for (i=0;i<5;++i)
	{
		p[i]+=360-v[i];
		p[i]%=360;
	}
}

bool can()
{
	int i,j;
	bool f;
	for (i=0;i<360;++i)
	{
		f=0;
		for (j=0;j<5;++j)
		{
			if(C[j][(p[j]+i)%360]==0)
			{
				f=1;
				break;
			}
		}
		if (!f)
		{
			return 1;
		}
	}
	return false;
}

int main()
{
	freopen("spin.in","r",stdin);
	freopen("spin.out","w",stdout);
	int i,j,k,a,b,n;
	for (i=0;i<5;++i)
	{
		cin>>v[i]>>n;
		for(j=0;j<n;++j)
		{
			cin>>a>>b;
			for (k=a;k<=a+b;++k)
			{
				C[i][k%360]=1;
			}
			
		}
	}
	n=0;
	while (n<360)
	{
		
		if (can())
		{
			cout<<n<<endl;;
			return 0;
		}
		go();
		++n;
	}
	cout<<"none"<<endl;
	
	return 0;
}

