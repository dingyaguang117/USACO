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
int MMmax[5],NNmax[10];
double dmin=100000;

void doit()
{
		int i,j;
		vector<double> S;
		vector<double> S2;
		double e,e2,d;
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
		if ((double)MM[M-1]*NN[N-1]<3*(double)MM[0]*NN[0])
		{
			return;
		}
		for (i=0;i<M;++i)
		{
			for (j=0;j<N;++j)
			{
				S.push_back((double)MM[i]/NN[j]);
			}
		}
		sort(S.begin(),S.end());

		for (i=1;i<S.size();++i)
		{
			S2.push_back(S[i]-S[i-1]);
		}

		e=0;
		e2=0;
		for (i=0;i<S2.size();++i)
		{
			e+=S2[i];
			e2+=S2[i]*S2[i];
		}
		e/=S2.size();		
		e2/=S2.size();
		
		d=e2-e*e;
		
		if (d<dmin)
		{
			dmin=d;
			for (i=0;i<M;++i)
			{
				MMmax[i]=MM[i];
			}
			for (i=0;i<N;++i)
			{
				NNmax[i]=NN[i];
			}

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
	freopen("cowcycle.in","r",stdin);
	freopen("cowcycle.out","w",stdout);
	
	int i,j;
	cin>>M>>N;
	cin>>Ma>>Mb>>Na>>Nb;

	digui(0,0);
		cout<<MMmax[0];
		for (i=1;i<M;++i)
		{
			cout<<" "<<MMmax[i];
		}
		cout<<endl<<NNmax[0];;
		for (i=1;i<N;++i)
		{
			cout<<" "<<NNmax[i];
		}

	cout<<endl;
	return 0;
}

