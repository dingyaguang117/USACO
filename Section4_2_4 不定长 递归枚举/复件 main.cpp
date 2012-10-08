/*
ID:dingyag1
LANG:C++
TASK:cowcycle
*/

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int M,N,Ma,Mb,Na,Nb;
int MM[5],NN[10];

void doit()
{
		int i,j;
		vector<double> S;
		vector<double> S2;
/*		for (i=0;i<M;++i)
		{
			cout<<" "<<MM[i];
		}
		cout<<endl;
		for (i=0;i<N;++i)
		{
			cout<<" "<<NN[i];
		}
		cout<<endl<<endl;*/
		if (MM[M]*NN[N]<3*MM[0]*NN[0])
		{
			return;
		}
		for (i=0;i<M;++i)
		{
			for (j=0;j<N;++j)
			{
				S.push_back(MM[i]/NN[i]);
			}
		}
		sort(S.begin(),S.end());

		for (i=0;i<S.size();++i)
		{
		}


		
}

void digui(int m,int n)
{
	int i,j;
	if (m==M)
	{
		if (n==N)
		{
			doit();
		}else
		{
			if (n==0)
			{
				i=Na;
			}else
				i=NN[n-1]+1;
			for (;i<=Nb-N+n+1;++i)
			{
				NN[n]=i;
				digui(m,n+1);
			}
		}
	}
	else
	{
		if (m==0)
		{
			i=Ma;
		}else
			i=MM[m-1]+1;
		for (;i<=Mb-M+m+1;++i)
		{
			MM[m]=i;
			digui(m+1,n);
		}
	}
}


int main()
{
	//freopen("cowcycle.in","r",stdin);
//	freopen("cowcycle.out","w",stdout);
	
	int i,j;
	cin>>M>>N;
	cin>>Ma>>Mb>>Na>>Nb;

	digui(0,0);
	
	
	return 0;
}

