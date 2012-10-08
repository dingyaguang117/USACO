/*
ID:dingyag1
LANG:C++
TASK:friday
*/

#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	freopen("friday.in","r",stdin);
	freopen("friday.out","w",stdout);

	int i,n,j,pre=2;	//1899.12.13 Wed
	int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int s[7]={0};
	cin>>n;

	for (i=0;i<n;++i)
	{
		for (j=0;j<12;++j)
		{
			pre+=a[(j+11)%12];
			if (j==2)
			{
				if (((1900+i)%4==0&&(1900+i)%100!=0)||(1900+i)%400==0)
				{
					pre+=1;
				}
				
			}
			pre%=7;
			s[pre]+=1;
		}
	}
	cout<<s[5]<<" "<<s[6];
	for (i=0;i<5;++i)
	{
		cout<<" "<<s[i];
	}
	cout<<endl;


}