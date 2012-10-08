/*
ID:dingyag1
LANG:C++
TASK:packrec
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

#define  MAX(a,b) (a<b?b:a)

using namespace std;

struct res
{
	int a,b,s;
};

res proc1(int a1,int b1,int a2,int b2,int a3,int b3,int a4,int b4);
res proc2(int a1,int b1,int a2,int b2,int a3,int b3,int a4,int b4);
res proc3(int a1,int b1,int a2,int b2,int a3,int b3,int a4,int b4);
res proc4(int a1,int b1,int a2,int b2,int a3,int b3,int a4,int b4);
res proc5(int a1,int b1,int a2,int b2,int a3,int b3,int a4,int b4);
inline void swap(int &a,int &b);

bool operator< (const res &a,const res &b)
{
	if (a.a<b.a)
	{
		return true;
	}
	return false;
}

int main()
{
	int data[4][2];
	int en[4]={0,1,2,3},i,j,bn[4];
	int ding,t;
	res r;
	int max=1000000;
	vector<res> result;

	freopen("packrec.in","r",stdin);
	freopen("packrec.out","w",stdout);
	for (i=0;i<4;++i)
	{
		for (j=0;j<2;++j)
		{
			cin>>data[i][j];
		}
	}
	sort(en,en+4);	
	while (next_permutation(en,en+4))
	{
		for (ding=0;ding<16;++ding)
		{
			// get wigth and height zuhe
			t=ding;
			
			for (i=0;i<4;++i)
			{
				bn[i]=0;
			}
			i=0;
			while (t!=0)
			{
				bn[i++]=t%2;
				t/=2;
			}
			/*
			cout<<"bn[n]:"<<endl;;
			for (i=0;i<4;++i)
			{
				cout<<bn[i]<<!bn[i]<<endl;
			}			
			*/
			r=proc1(data[en[0]][bn[0]],data[en[0]][!bn[0]],data[en[1]][bn[1]],data[en[1]][!bn[1]],data[en[2]][bn[2]],data[en[2]][!bn[2]],data[en[3]][bn[3]],data[en[3]][!bn[3]]);
			
			if (r.s==max)
			{
				result.push_back(r);

			}
			if (r.s<max)
			{
				result.clear();
				result.push_back(r);
				max=r.s;
			}


			//////////////////
			r=proc2(data[en[0]][bn[0]],data[en[0]][!bn[0]],data[en[1]][bn[1]],data[en[1]][!bn[1]],data[en[2]][bn[2]],data[en[2]][!bn[2]],data[en[3]][bn[3]],data[en[3]][!bn[3]]);
			
			if (r.s==max)
			{
				result.push_back(r);
				
			}
			if (r.s<max)
			{
				result.clear();
				result.push_back(r);
				max=r.s;
			}
			///////////////////
			r=proc3(data[en[0]][bn[0]],data[en[0]][!bn[0]],data[en[1]][bn[1]],data[en[1]][!bn[1]],data[en[2]][bn[2]],data[en[2]][!bn[2]],data[en[3]][bn[3]],data[en[3]][!bn[3]]);
			
			if (r.s==max)
			{
				result.push_back(r);
				
			}
			if (r.s<max)
			{
				result.clear();
				result.push_back(r);
				max=r.s;
			}
			//////////////////////
			r=proc4(data[en[0]][bn[0]],data[en[0]][!bn[0]],data[en[1]][bn[1]],data[en[1]][!bn[1]],data[en[2]][bn[2]],data[en[2]][!bn[2]],data[en[3]][bn[3]],data[en[3]][!bn[3]]);
			
			if (r.s==max)
			{
				result.push_back(r);
				
			}
			if (r.s<max)
			{
				result.clear();
				result.push_back(r);
				max=r.s;
			}
			/////////////////////////
			r=proc5(data[en[0]][bn[0]],data[en[0]][!bn[0]],data[en[1]][bn[1]],data[en[1]][!bn[1]],data[en[2]][bn[2]],data[en[2]][!bn[2]],data[en[3]][bn[3]],data[en[3]][!bn[3]]);
			
			if (r.s==max)
			{
				result.push_back(r);
				
			}
			if (r.s<max)
			{
				result.clear();
				result.push_back(r);
				max=r.s;
			}
		}

		//proc1(data[en[0]][0],data[en[0]][1],data[en[1]][0],data[en[1]][1],data[en[2]][0],data[en[2]][1],data[en[3]][0],data[en[3]][1]);
	}
	cout<<max<<endl;
	for (i=0;i<result.size();++i)
	{
		if (result[i].a>result[i].b)
		{
			swap(result[i].a,result[i].b);
		}
		//cout<<result[i].a<<" "<<result[i].b<<endl;
	}

	sort(result.begin(),result.end());

	i=0;
	cout<<result[i].a<<" "<<result[i].b<<endl;
	for (i=1;i<result.size();++i)
	{
		if (result[i].a!=result[i-1].a)
		{
			cout<<result[i].a<<" "<<result[i].b<<endl;
		}
		
	}
		
	//cout<<result.size();
	return 0;
}


inline void swap(int &a,int &b)
{
	int c;
	c=a;
	a=b;
	b=c;
}

res proc1(int a1,int b1,int a2,int b2,int a3,int b3,int a4,int b4)
{
	res r;
	/*
	if (a1>b1) swap(a1,b1);
	if (a2>b2) swap(a2,b2);
	if (a3>b3) swap(a3,b3);
	if (a4>b4) swap(a4,b4);*/
	r.a=a4+a3+a2+a1;
	r.b=MAX(MAX(MAX(b1,b2),b3),b4);
	r.s=r.a*r.b;
	return r;
}

res proc2(int a1,int b1,int a2,int b2,int a3,int b3,int a4,int b4)
{
	res r;
	r.a=MAX(b4,(a3+a2+a1));
	r.b=MAX(MAX(b1,b2),b3)+a4;
	r.s=r.a*r.b;
	return r;
}

res proc3(int a1,int b1,int a2,int b2,int a3,int b3,int a4,int b4)
{
	res r;
	r.a=MAX(b3,(a2+a1))+a4;
	r.b=MAX((MAX(b1,b2)+a3),b4);
	r.s=r.a*r.b;
	return r;
}

res proc4(int a1,int b1,int a2,int b2,int a3,int b3,int a4,int b4)
{
	res r;
	r.a=a1+a2+MAX(a3,a4);
	r.b=MAX(MAX(b1,b2),(b3+b4));
	r.s=r.a*r.b;
	return r;
}

res proc5(int a1,int b1,int a2,int b2,int a3,int b3,int a4,int b4)
{
	res r;
	r.b=MAX((b1+b3),(b2+b4));
	if (b3>=b2+b4)
	{
		r.a=MAX(a1,MAX((a2+a3),(a3+a4)));
	}
	else if (b3>b4 && b3<b2+b4)
	{
		r.a=MAX((a1+a2),MAX((a2+a3),(a3+a4)));
	}
	else if(b4>b3 && b4<b1+b3)
	{
		r.a=MAX((a1+a2),MAX((a1+a4),(a3+a4)));
	}
	else if (b4>=b1+b3)
	{
		r.a=MAX(a2,MAX((a1+a4),(a3+a4)));
	}
	else if (b4=b3)
	{
		r.a=MAX((a1+a2),(a3+a4));
	}

	r.s=r.a*r.b;
	return r;
}

