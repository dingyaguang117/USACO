/*
ID:dingyag1
LANG:C++
TASK:fence8
*/

#include <stdio.h>
#include <iostream>
#include <functional>
#include <algorithm>
//#define  debug

using namespace std;

int N,R;
int Board[51],Rail[1024];	
int B_left[51];				//每块剩下多少
int sum=0/*,extra=0*/;			//sum board总长度 ，R cur 当前切到第几快
int B_choiced[1024];


int DFSID(int deep,int index,int extra)
{
	if (deep==0)
	{
		return 0;
	}
	int j,r=0,t;
	bool f=0;
		j=0;
		//如果 上次的rail index-1 与 index 相同，只需从上次的开始枚举
		if (index>0 && Rail[index]==Rail[index-1])
		{
#ifdef debug
			cout<<"success cut 3!"<<endl;
#endif
			j=B_choiced[index-1];
		}
		for (;j<N;++j)		//枚举每条Board
		{
			if (B_left[j]<Rail[index])
			{
				continue;
			}
			
			B_left[j]-=Rail[index];
/*
			for (t=0;t<deep;++t)
			{
				cout<<" ";
			}*/
//			cout<<"DFSID:"<<deep-1<<endl;
			//优化4########
			if(B_left[j]<Rail[0])
			{
				extra-=B_left[j];
				f=1;
				if(extra<0)
				{
#ifdef debug
					cout<<"success cut 4!"<<endl;
#endif
					extra+=B_left[j];
					B_left[j]+=Rail[index];
					continue;
				}
			}
			//################
			B_choiced[index]=j;
			t=DFSID(deep-1,index+1,extra)+1;
			
			if (f)
			{
				extra+=B_left[j];
				f=0;
			}
			

			B_left[j]+=Rail[index];
			
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

	sort(B_left,B_left+N);
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

	sort(Rail,Rail+R,cmp);

/*
	extra=0;
	for (i=0;i<(a+b)/2;++i)
	{
		extra+=Rail[i];
	}
		extra=sum-extra;*/
cout<<DFSID(R,0,extra)<<endl;



	
/*
//二分深度迭代搜索
	a=1;b=R;
	int r;
	while(a<=b)
	{
//优化4
		extra=0;
		for (i=0;i<(a+b)/2;++i)
		{
			extra+=Rail[i];
		}
		extra=sum-extra;

//#############
		r=DFSID((a+b)/2,0,extra);

		if (r==(a+b)/2)
		{
			a=(a+b)/2+1;
		}else
			break;
	}
	cout<<r<<endl;
*/
	return 0;
}

