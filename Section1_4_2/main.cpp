/*
ID:dingyag1
LANG:C++
TASK:clocks
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int add[9][9]=
{
	1,1,0,1,1,0,0,0,0,
	1,1,1,0,0,0,0,0,0,
	0,1,1,0,1,1,0,0,0,
	1,0,0,1,0,0,1,0,0,
	0,1,0,1,1,1,0,1,0,
	0,0,1,0,0,1,0,0,1,
	0,0,0,1,1,0,1,1,0,
	0,0,0,0,0,0,1,1,1,
	0,0,0,0,1,1,0,1,1
};

class status
{
public:
	int m[9];
public:
	status(){};

	status(const status &o)
	{
		int i;
		for (i=0;i<9;++i)
		{
			m[i]%=o.m[i];
		}
	}

	status &operator =(const status &o)
	{
		int i;
		for (i=0;i<9;++i)
		{
			this->m[i]%=o.m[i];
		}
		return *this;
	}

	void updata()
	{
		int i;
		for (i=0;i<9;++i)
		{
			m[i]%=4;
		}
	}
	status &dodo(int n)
	{
		status ss;
		int i;
		for (i=0;i<9;++i)
		{
			ss.m[i]=m[i]+add[n][i];
		}
		
		return ss;
	}
	void input()
	{
		int i;
		for (i=0;i<9;++i)
		{
			cin>>m[i];
			m[i]%=12;
			m[i]/=3;
		}
	}
};



int main()
{
	freopen("clocks.in","r",stdin);
	freopen("clocks.out","w",stdout);
	status st;

	st.input();

	return 0;
}