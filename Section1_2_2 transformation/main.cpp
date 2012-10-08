/*
ID:dingyag1
LANG:C++
TASK:transform
*/

#include <iostream>
#include <stdio.h>

using namespace std;
bool a[10][10];
bool b[10][10];
bool c[10][10];
bool d[10][10];
int n;

bool equ(bool a[][10],bool b[][10])
{
	int i,j;
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			if(a[i][j]!=b[i][j])
				return false;
		}
	}
	return true;
}


void round90(bool a[][10],bool b[][10])
{
	int i,j;
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			b[j][n-i-1]=a[i][j];
		}
	}

}

void reverse(bool a[][10],bool b[][10])
{
	int i,j;
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			b[i][n-j-1]=a[i][j];
		}
	}
}


int main()
{
	freopen("transform.in","r",stdin);
	freopen("transform.out","w",stdout);
	int i,j;
	char cc;
	cin>>n;
	//cin>>cc;
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			cin>>cc;
			a[i][j]=(cc=='@');
		}
		//cin>>cc;
	}
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			cin>>cc;
			b[i][j]=(cc=='@');
		}
		//cin>>cc;
	}
	/*
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	
	

	
	round90(a,c);
	if(equ(c,b))
	{
		cout<<1<<endl;
		return 0;
	}
	
	round90(c,d);
	if(equ(d,b))
	{
		cout<<2<<endl;
		return 0;
	}
	
	round90(d,c);
	if(equ(c,b))
	{
		cout<<3<<endl;
		return 0;
	}
	
	reverse(a,d);
	if(equ(d,b))
	{
		cout<<4<<endl;
		return 0;
	}
	
	
	round90(d,c);
	if(equ(c,b))
	{
		cout<<5<<endl;
		return 0;
	}
	
	round90(c,d);
	if(equ(d,b))
	{
		cout<<5<<endl;
		return 0;
	}
	
	round90(d,c);
	if(equ(c,b))
	{
		cout<<5<<endl;
		return 0;
	}
	
	if(equ(a,b))
	{
		cout<<6<<endl;
		return 0;
	}

	cout<<7<<endl;
}