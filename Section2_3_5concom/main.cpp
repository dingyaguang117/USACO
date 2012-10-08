/*
ID:dingyag1
LANG:C++
TASK:concom
*/

#include <stdio.h>
#include <iostream>
#include <set>
#include <queue>
using namespace std;

int con[101][101];

class ctl
{
public:
	int a,b;
public:
	ctl(int p1=0,int p2=0):a(p1),b(p2){}
};
bool operator < (const ctl &a, const ctl & b)
{
	if (a.a<b.a)
	{
		return true;
	}
	if (a.a==b.a)
	{
		if (a.b<b.b)
		{
			return true;
		}
		else return false;
	}
	return false;
}

int main()
{
	freopen("concom.in","r",stdin);
	freopen("concom.out","w",stdout);
	int n,N=2,i,j,a,b,c;
	queue<ctl> que;
	set<ctl> result;
	set<ctl>::iterator it;
	cin>>n;
	for (i=0;i<n;++i)
	{
		cin>>a>>b>>c;
		if (a>N) N=a;
		if (b>N) N=b;
		con[a][b]=c;
		if (c>50)
		{
			que.push(ctl(a,b));
			result.insert(ctl(a,b));
		}
	}
	
	while(!que.empty())
	{
		ctl cl=que.front();
		bool f=0;
		for (i=1;i<=N;++i)
		{
			if (con[cl.a][i]<=50)
			{
				f=1;
			}
			con[cl.a][i]+=con[cl.b][i];
			if (f&&con[cl.a][i]>50)
			{
				que.push(ctl(cl.a,i));
				result.insert(ctl(a,b));
			}
		}
		que.pop();
	}
	it=result.begin();
	while(it!=result.end())
	{
		cout<< it->a <<" "<<it->b <<endl;
		++it;
	}


	return 0;
}

