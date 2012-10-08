/*
ID:dingyag1
LANG:C++
TASK:agrinet
*/

#include <iostream>
#include <stdio.h>
using namespace std;
int a[100][100];
int b[100],c[100];
int main()
{
	freopen("agrinet.in","r",stdin);
	freopen("agrinet.out","w",stdout);

    int n,sum,min,minp;
    int i,j;
	
    cin>>n;
    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
        {
            cin>>a[i][j];
        }
    }
	
    b[0]=1;
    for(i=0;i<n;++i)
    {
        c[i]=a[0][i];
		
    }
    sum=0;
    for(i=0;i<n-1;++i)
    {
        min=10000000;
        for(j=0;j<n;++j)
        {
            if(!b[j]&&c[j]&&min>c[j])
            {
                min=c[j];
                minp=j;
            }
        }
        sum+=min;
        b[minp]=1;
        for(j=0;j<n;++j)
        {
            if(!b[j]&&a[minp][j]) 
            {
                if(a[minp][j]<c[j])
                    c[j]=a[minp][j];
            }
        }
    }
    cout<<sum<<endl;
}