/*
ID:dingyag1
LANG:C++
TASK:fence8
*/

#include <stdio.h>
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

int N,R;
int Board[50],Rail[1024];	
int B_left[50];				//每块剩下多少
int R_cur,sum=0/*,extra=0*/;			//sum board总长度 ，R cur 当前切到第几快
int B_choiced[1024];


int DFSID(int deep,int extra)
{
	if (deep==0)
	{
		return 0;
	}
	int j,r=0,t;

		j=0;
		if (R_cur>0 && Rail[R_cur]==Rail[R_cur-1])
		{
			//j=B_pre_cho;
			j=B_choiced[R_cur-1];
		}
		for (;j<N;++j)		//枚举每条Board
		{
			if (B_left[j]<Rail[R_cur])
			{
				continue;
			}
			//优化4
			if (R_cur<R-1 && B_left[j]-Rail[R_cur]<Rail[R_cur+1])
			{
				
				extra-=B_left[j]-Rail[R_cur];
				if (extra<0)
				{
					extra+=B_left[j]-Rail[R_cur];
					continue;
				}
				
			}
			B_choiced[R_cur]=j;
			R_cur+=1;
			B_left[j]-=Rail[R_cur];

			for (t=0;t<deep;++t)
			{
				cout<<" ";
			}
			cout<<"DFSID:"<<deep-1<<endl;
			t=DFSID(deep-1,extra)+1;

			R_cur-=1;
			B_left[j]+=Rail[R_cur];
		
			if (t>r)
			{
				r=t;
				if(r==deep) return r;
			}
		}
	

	return r;

}

bool cmp(const int &a,const int &b)
{
	return a>b;
}

int main()
{
	freopen("fence8.in","r",stdin);
	freopen("fence8.out","w",stdout);
	int i,j,a,b,extra;
	
	cin>>N;
	for (i=0;i<N;++i)
	{
		cin>>Board[i];
		B_left[i]=Board[i];
		sum+=Board[i];
	}
	cin>>R;
	for (i=0;i<R;++i)
	{
		cin>>Rail[i];
	}

	sort(B_left,B_left+N,cmp);
	sort(Rail,Rail+R);

//剪枝1 取可能取到的前 R个rail
	int t=0;
	i=0;
	while (i<R)
	{
		t+=Rail[i];
		if (t>sum)
		{
			R=i;
			break;
		}
		++i;
	}

//	cout<<DFSID(R)<<endl;

//二分深度迭代搜索
	a=1;b=R;
	int r;
	while(a<=b)
	{
		
		//available=sum;
		
		extra=0;
		for (i=0;i<(a+b)/2;++i)
		{
			extra+=Rail[i];
		}
		extra=sum-extra;

		for (t=0;t<(a+b)/2;++t)
		{
			cout<<" ";
		}
		cout<<"DFSID:"<<(a+b)/2<<endl;

		cout<<"Extra:"<<extra<<endl;
		r=DFSID((a+b)/2,extra);

		cout<<R_cur<<" "<<extra<<endl;
		if (r==(a+b)/2)
		{
			a=(a+b)/2+1;
		}else
			break;
	}
	cout<<r<<endl;

	return 0;
}

