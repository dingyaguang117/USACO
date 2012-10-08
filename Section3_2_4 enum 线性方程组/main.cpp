/*
ID:dingyag1
LANG:C++
TASK:ratios
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	freopen("ratios.in","r",stdin);
	freopen("ratios.out","w",stdout);
	
	int i,j,k,n,sum=1000000,da,db,dc,dn;
	int a1,a2,a3,b1,b2,b3,c1,c2,c3,a,b,c;

	cin>>a>>b>>c>>a1>>b1>>c1>>a2>>b2>>c2>>a3>>b3>>c3;
	
	if (0)
	{
		cout<<"NONE"<<endl;
		return 0;
	}
	for (i=0;i<100;++i)
	{
		for (j=0;j<100;++j)
		{
			for (k=0;k<100;++k)
			{
				if (i==0 &&  j==0 && k==0)
				{
					k=1;
				}
				if (a==0)
				{
					if ((i*a1+j*a2+k*a3)!=0)
								continue;					
				}
				else
				{
					if ((i*a1+j*a2+k*a3)%a==0)
					{
						n=(i*a1+j*a2+k*a3)/a;
					}else continue;
				}
				
				if (b==0)
				{
					if ((i*b1+j*b2+k*b3)!=0)
						continue;					
				}
				else
				{
				if ((i*b1+j*b2+k*b3)%b==0)
				{
					if (n!=(i*b1+j*b2+k*b3)/b) continue;
				}else continue;
				}
				
				if (c==0)
				{
					if ((i*c1+j*c2+k*c3)!=0)
						continue;					
				}
				else
				{
				if ((i*c1+j*c2+k*c3)%c==0)
				{
					if (n!=(i*c1+j*c2+k*c3)/c) continue;
				}else continue;
				}

				if (i+j+k<sum)
				{
					da=i;db=j,dc=k;dn=n;
					sum=da+db+dc;
					cout<<da<<" "<<db<<" "<<dc<<" "<<dn<<endl;
					return 0;
				}
				
			}
		}
	}
	
	cout<<"NONE"<<endl;




	return 0;
}

