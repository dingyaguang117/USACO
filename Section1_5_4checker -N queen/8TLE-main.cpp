/*
ID:dingyag1
LANG:C++
TASK:checker
*/

#include <stdio.h>
#include <iostream>

using namespace std;
int n;
int result[3][13];
int path[13];
int sum,recordnum;

void todo(bool lie[],bool xie[],bool xie2[],int nCur)
{
	int i,j;
	if(nCur==n) return;

	for(i=0;i<n;++i)
	{
		//xie=n-hang-1+lie
		if(!lie[i]&&!xie[n-nCur-1+i]&&!xie2[nCur+i])
		{
			lie[i]=1;
			xie[n-nCur-1+i]=1;
			xie2[nCur+i]=1;
			path[nCur]=i+1;
			todo(lie,xie,xie2,nCur+1);
			if(nCur==n-1)
			{
				sum++;
				if(recordnum!=3)
				{
					for(j=0;j<n;++j)
						result[recordnum][j]=path[j];
					++recordnum;
				}

			}
			lie[i]=0;
			xie[n-nCur-1+i]=0;
			xie2[nCur+i]=0;
		}
	}
}

int main()
{
	freopen("checker.in","r",stdin);
	freopen("checker.out","w",stdout);
	bool lie[13]={0};
	bool xie[13*2-1]={0};
	bool xie2[13*2-1]={0};
	int i,j,lim;

	cin>>n;
	
	todo(lie,xie,xie2,0);
	lim=sum<3?sum:3;
	for(i=0;i<lim;++i)
	{
		for(j=0;j<n-1;++j)
			cout<<result[i][j]<<" ";
		cout<<result[i][n-1]<<endl;
	}
	cout<<sum<<endl;
	return 0;
}
