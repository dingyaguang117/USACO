/*
ID:dingyag1
LANG:C++
TASK:msquare
*/



#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <set>
using namespace std;


class ITEM
{
public:
	int a[8];
	string path;

	void opA(ITEM & x)
	{
		x.a[0]=a[4];
		x.a[1]=a[5];
		x.a[2]=a[6];
		x.a[3]=a[7];
		x.a[4]=a[0];
		x.a[5]=a[1];
		x.a[6]=a[2];
		x.a[7]=a[3];
		x.path=path+'A';
	}
	void opB(ITEM & x)
	{
		x.a[0]=a[3];
		x.a[1]=a[0];
		x.a[2]=a[1];
		x.a[3]=a[2];
		x.a[4]=a[7];
		x.a[5]=a[4];
		x.a[6]=a[5];
		x.a[7]=a[6];
		x.path=path+'B';
	}
	void opC(ITEM & x)
	{
		x.a[0]=a[0];
		x.a[1]=a[5];
		x.a[2]=a[1];
		x.a[3]=a[3];
		x.a[4]=a[4];
		x.a[5]=a[6];
		x.a[6]=a[2];
		x.a[7]=a[7];
		x.path=path+'C';
	}
	ITEM & operator = (const ITEM &B)
	{
		int i;
		for (i=0;i<8;++i)
		{
			a[i]=B.a[i];
		}
		path=B.path;
		return *this;
	}
};

bool operator < (const ITEM &A,const ITEM &B)
{
	int i;
	for (i=0;i<8;++i)
	{
		if (A.a[i]<B.a[i])
		{
			return true;
		}
		else if (A.a[i]>B.a[i])
		{
				return false;
		}
	}
	return false;
}

queue<ITEM> que;
set<ITEM> S;
int b[8];

int main()
{
	freopen("msquare.in","r",stdin);
	freopen("msquare.out","w",stdout);
	
	ITEM tmp,tmp2;
	cin>>b[0]>>b[1]>>b[2]>>b[3]>>b[7]>>b[6]>>b[5]>>b[4];

	tmp.a[0]=1;tmp.a[1]=2;tmp.a[2]=3;tmp.a[3]=4;tmp.a[7]=5;tmp.a[6]=6;tmp.a[5]=7;tmp.a[4]=8;

	que.push(tmp);
	S.insert(tmp);
	while (!que.empty())
	{
		int i;
		bool f=0;
		tmp=que.front();
		for (i=0;i<8;++i)
		{
			if (tmp.a[i]!=b[i])
			{
				f=1;
				break;
			}
		}
		if (!f)
		{
			cout<<tmp.path.size()<<endl<<tmp.path<<endl;
			break;
		}
		tmp.opA(tmp2);
		if (S.find(tmp2)==S.end())
		{
			que.push(tmp2);
			S.insert(tmp2);
		}
		tmp.opB(tmp2);
		if (S.find(tmp2)==S.end())
		{
			que.push(tmp2);
			S.insert(tmp2);
		}
		tmp.opC(tmp2);
		if (S.find(tmp2)==S.end())
		{
			que.push(tmp2);
			S.insert(tmp2);
		}
		que.pop();
	}
	
	return 0;
}

