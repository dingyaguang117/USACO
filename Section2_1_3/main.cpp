/*
ID:dingyag1
LANG:C++
TASK:sort3
*/

#include <iostream>
#include <stdio.h>

#define MIN(x,y) ((x)<(y)?(x):(y))
using namespace std;
int b[3]={0},c[3][3]={0};
int main()
{
	freopen("sort3.in","r",stdin);
	freopen("sort3.out","w",stdout);

	int n,a[1005],i,t,exc=0;
	
	
	cin>>n;
	for(i=0;i<n;++i)
	{
		cin>>a[i];
		b[a[i]-1]+=1;			
	}
	for(i=0;i<n;++i)
	{
		t=((i<b[0])?0:((i<b[1]+b[0])?1:2));
		c[t][a[i]-1]+=1;	
	}
	
	
	t=MIN(c[0][1],c[1][0]);
	exc+=t;
	c[0][1]-=t;
	c[1][0]-=t;
	t=MIN(c[0][2],c[2][0]);
	exc+=t;
	c[0][2]-=t;
	c[2][0]-=t;
	t=MIN(c[2][1],c[1][2]);
	exc+=t;
	c[2][1]-=t;
	c[1][2]-=t;
	exc+=(c[0][1]+c[0][2])*2;
	
	cout<<exc<<endl;
	
}