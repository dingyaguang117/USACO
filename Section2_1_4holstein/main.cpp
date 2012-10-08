/*
ID:dingyag1
LANG:C++
TASK:holstein
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int V,Vmin[25],G,Gd[15][25],VV[25];


int main()
{
	freopen("holstein.in","r",stdin);
	freopen("holstein.out","w",stdout);
	int i,j;
	bool fail;
	unsigned short X,result,t;
	int minCla=17;


	cin>>V;
	for (i=0;i<V;++i)
	{
		cin>>Vmin[i];
	}
	cin>>G;
	for (i=0;i<G;++i)
	{
		for (j=0;j<V;++j)
		{
			cin>>Gd[i][j];
		}
	}
	
	for (X=0;X<1024*32;++X)			//find all situation
	{
		t=1;
		fail=0;
		int nbit=0;
		for (j=0;j<V;++j)
		{
			VV[j]=0;	
		}
		for (int i=0;i<G;++i)			//all bit
		{
			if (t&X)
			{
				for (j=0;j<V;++j)
				{
					VV[j]+=Gd[i][j];
				}
				nbit++;
			}
			//cout<<"t:"<<t<<" ";
			t<<=1;
			//cout<<"t<<1:"<<t<<" ";
		}
		
		for (j=0;j<V;++j)
		{
			if (VV[j]<Vmin[j])
			{
				fail=1;
				break;
			}
				
		}
		if (!fail)
		{
			if (nbit<minCla)
			{
				minCla=nbit;
				result=X;
			}
			
		//	cout<<X<<" ";
		}
	}
	cout<<minCla;
	t=1;
	for (i=0;i<G;++i)			//all bit
	{
		if (t&result)
		{
			 cout<<" "<<i+1;
		}

		t<<=1;
	}
	cout<<endl;
	return 0;
}