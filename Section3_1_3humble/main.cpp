/*
ID:dingyag1
LANG:C++
TASK:humble
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

long humble[100001],S[101];
int len,nS;

class item
{
public:
	long a,b,r;
};

bool operator < (const item & m, const item & n)
{
	return m.r<n.r;
}

set<item> waiting;

bool find(long  r)
{
	set<item>::iterator it=waiting.begin();
	while (it!=waiting.end())
	{
		if (it->r==r)
		{
			return true;
		}
		++it;
	}
	return false;
}

int main()
{
	freopen("humble.in","r",stdin);
	freopen("humble.out","w",stdout);
	
	int N,i,j,k;
	item itm;

	cin>>nS>>N;

	for (i=0;i<nS;++i)
	{
		cin>>S[i];
	}

//init  waiting	
	for (i=0;i<nS;++i)
	{
		itm.a=i;
		itm.b=-1;
		itm.r=S[i];
		waiting.insert(itm);
	}
	i=0;
	len=0;
	while (i!=N)
	{
		itm=*waiting.begin();
		humble[len++]=itm.r;
		waiting.erase(waiting.begin());
		//======

		while(1)
		{
			itm.b+=1;
			itm.r=S[itm.a]*humble[itm.b];
			if ((double)S[itm.a]*humble[itm.b]>humble[len-1] && !find(itm.r))
			{
				waiting.insert(itm);
				break;
			}
		}

		++i;
	}

	cout<<humble[N-1]<<endl;
	return 0;
}

