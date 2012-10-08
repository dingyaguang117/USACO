/*
ID:dingyag1
LANG:C++
TASK:game1
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#define mmax(a,b) ((a)>(b)?(a):(b))

using namespace std;



bool dp[101][101][2];		//0bit max value  1£ºleft or right
int data[101];

int get(int begin,int end,bool &r)	//1 left 0 right
{
	int maxl,maxr;
	bool rr;
	if (begin==end)
	{
		return data[begin];
	}
	if (begin>end)
	{
		return 0;
	}
	if (dp[begin][end][0])
	{
		r=dp[begin][end][1];
		return dp[begin][end][0];
	}
	maxl=data[begin]+mmax(get(begin+2,end,rr),get(begin+1,end-1,rr));
	maxr=data[end]+mmax(get(begin+1,end-1,rr),get(begin,end-2,rr));
	if (maxl>maxr)
	{
		r=1;
	}else
		r=0;

	dp[begin][end][1]=r;
	dp[begin][end][0]=mmax(maxl,maxr);
	
	return mmax(maxl,maxr);

}


int main()
{
	freopen("game1.in","r",stdin);
	freopen("game1.out","w",stdout);
	
	int N,begin,end,i,j;
	int as=0,bs=0;
	bool f=1;
	bool r;

	cin>>N;
	for (i=0;i<N;++i)
	{
		cin>>data[i];
	}
	begin=0;end=N-1;
	
	while (begin<=end)
	{
		if (f)
		{
			get(begin,end,r);
			if(r)
				as+=data[begin++];
			else
				as+=data[end--];
		}
		else
		{
			get(begin,end,r);
			if(r)
				bs+=data[begin++];
			else
				bs+=data[end--];
		}
		f=!f;

	}
	cout<<as<<" "<<bs<<endl;

	return 0;
}

