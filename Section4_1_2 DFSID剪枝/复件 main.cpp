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
int B_left[50];
bool R_choiced[1024];


int DFSID(int deep,int R_cur)
{
	if (deep==0)
	{
		return 0;
	}
	int i,j,r=0,t;

	for (i=0;i<R;++i)			//枚举每条rail
	{
		if (R_choiced[i])
		{
			continue;
		}
		for (j=0;j<N;++j)		//枚举每条Board
		{
			if (B_left[j]<Rail[i])
			{
				continue;
			}
			R_choiced[i]=1;
			B_left[j]-=Rail[i];

			t=DFSID(deep-1,R_cur+1)+1;

			R_choiced[i]=0;
			B_left[j]+=Rail[i];
			if (t>r)
			{
				r=t;
				if(r==deep) return r;
			}
		}
		break;
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
	int i,j,a,b,sum=0;
	
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
		
		r=DFSID((a+b)/2);
		if (r==(a+b)/2)
		{
			a=(a+b)/2+1;
		}else
			break;
	}
	cout<<r<<endl;

	return 0;
}

