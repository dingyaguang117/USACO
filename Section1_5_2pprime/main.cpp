/*
ID:dingyag1
LANG:C++
TASK:pprime
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>

using namespace std;
void do1(int a,int b);
void do2(int a,int b);
void do3(int a,int b);
void do4(int a,int b);
void do5(int a,int b);
void do6(int a,int b);
void do7(int a,int b);
void do8(int a,int b);

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



int main()
{
	freopen("pprime.in","r",stdin);
	freopen("pprime.out","w",stdout);
	int a,b,d1,d2,d3,d4,alen=0,blen=0;
	
	getPrime();
	int i;
	/*
	for (i=0;i<leng;++i)
	{
		cout<<(int)flood[i]<<" ";
	}
	for (i=0;i<leng;++i)
	{
		cout<<prime[i]<<" ";
	}*/
	cin>>a>>b;
	d1=a;d2=b;
	while (d1!=0)
	{
		d1/=10;
		++alen;
	}
	while (d2!=0)
	{
		d2/=10;
		++blen;
	}
	
	switch(alen)
	{
	case 1:
		do1(a,b);
		if (blen==1) break;
	case 2:
		do2(a,b);
		if (blen==2) break;
	case 3:
		do3(a,b);
		if (blen==3) break;
	case 4:
		do4(a,b);
		if (blen==4) break;
	case 5:
		do5(a,b);
		if (blen==5) break;
	case 6:
		do6(a,b);
		if (blen==6) break;
	case 7:
		do7(a,b);
		if (blen==7) break;
	case 8:
		do8(a,b);
		if (blen==8) break;
	}

	return 0;
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

void do1(int a,int b)
{
	if (a==5)
	{
		cout<<5<<endl;
	}
	if (7>=a&&7<=b)
	{
		cout<<7<<endl;
	}
}

void do2(int a,int b)
{
	if (11>=a&&11<<b)
	{
		cout<<11<<endl;
	}
}

void do3(int a,int b)
{
	int i,j,num;
	bool f=0;
	for (i=a/100-a/100%2+1 ;i<=9;i+=2)
	{
		if (f)
		{
			break;
		}
		for (j=0;j<=9;++j)
		{
			num=100*i+10*j+i;
			if (num<a)
					continue;
			if (num>b)
			{
				f=1;
				break;
			}

			if(isPrime(num))
				cout<<num<<endl;

		}
	}
}

void do4(int a,int b)
{
	int i,j,num;
	bool f=0;
	for (i=a/1000-a/1000%2+1 ;i<=9;i+=2)
	{
		if (f)
		{
			break;
		}
		for (j=0;j<=9;++j)
		{
			num=1000*i+100*j+10*j+i;
			if (num<a)
				continue;
			if (num>b)
			{
				f=1;
				break;
			}
			
			if(isPrime(num))
				cout<<num<<endl;
			
		}
	}
}

void do5(int a,int b)
{
	int i,j,k,num;
	bool f=0;
	for (i=a/10000-a/10000%2+1 ;i<=9;i+=2)
	{
		if (f)
		{
			break;
		}
		for (j=0;j<=9;++j)
		{
			if (f)
			{
				break;
			}
			for (k=0;k<=9;++k)
			{
				num=10000*i+1000*j+100*k+10*j+i;
				if (num<a)
					continue;
				if (num>b)
				{
					f=1;
					break;
				}
			
				if(isPrime(num))
					cout<<num<<endl;
				
			}
		}
	}
}

void do6(int a,int b)
{
	int i,j,k,num;
	bool f=0;
	for (i=a/100000-a/100000%2+1 ;i<=9;i+=2)
	{
		if (f)
		{
			break;
		}
		for (j=0;j<=9;++j)
		{
			if (f)
			{
				break;
			}
			for (k=0;k<=9;++k)
			{
				num=100000*i+10000*j+1000*k+100*k+10*j+i;
				if (num<a)
					continue;
				if (num>b)
				{
					f=1;
					break;
				}
				
				if(isPrime(num))
					cout<<num<<endl;
				
			}
		}
	}
}

void do7(int a,int b)
{
	int i,j,k,l,num;
	bool f=0;
	for (i=a/1000000-a/1000000%2+1 ;i<=9;i+=2)
	{
		if (f)
		{
			break;
		}
		for (j=0;j<=9;++j)
		{
			if (f)
			{
				break;
			}
			for (k=0;k<=9;++k)
			{
				if (f)
				{
					break;
				}
				for(l=0;l<=9;++l)
				{
					num=1000000*i+100000*j+10000*k+1000*l+100*k+10*j+i;
					if (num<a)
						continue;
					if (num>b)
					{
						f=1;
						break;
					}
					
					if(isPrime(num))
					cout<<num<<endl;
				}
				
				
			}
		}
	}
}

void do8(int a,int b)
{
	int i,j,k,l,num;
	bool f=0;
	for (i=a/10000000-a/10000000%2+1 ;i<=9;i+=2)
	{
		if (f)
		{
			break;
		}
		for (j=0;j<=9;++j)
		{
			if (f)
			{
				break;
			}
			for (k=0;k<=9;++k)
			{
				if (f)
				{
					break;
				}
				for(l=0;l<=9;++l)
				{
					num=10000000*i+1000000*j+100000*k+10000*l+1000*l+100*k+10*j+i;
					if (num<a)
						continue;
					if (num>b)
					{
						f=1;
						break;
					}
					
					if(isPrime(num))
						cout<<num<<endl;
				}
				
				
			}
		}
	}
}