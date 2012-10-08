/*
ID:dingyag1
LANG:C++
TASK:prefix
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#define  MAX(a,b) (a)>(b)?(a):(b)
using namespace std;

int dp[200001];
string S;
vector<string> P;

int go(int start)
{
	int i,j,max=start,t1,t2;
	bool f;
	if (dp[start])
	{
		return dp[start];
	}

	for (i=0;i<P.size();++i)
	{
		if (P[i].size()<=S.size()-start)
		{
			f=0;
			for (j=0;j<P[i].size();++j)
			{
				if (P[i][j]!=S[start+j])
				{
					f=1;
					break;
				}
			}
			if (!f)
			{
				t1=/*start+P[i].size()+*/go(start+P[i].size());
				if (t1>max)
				{
					max=t1;
				}
			}
		}
	}

	dp[start]=max;
	return max;
}


int main()
{
	freopen("prefix.in","r",stdin);
	freopen("prefix.out","w",stdout);
	string s;
	while (cin>>s,s!=".")
	{
		P.push_back(s);
	}
	while (getline(cin,s))
	{
		S+=s;
	}
//	cin>>S;

	cout<<go(0)<<endl;
	return 0;
}

