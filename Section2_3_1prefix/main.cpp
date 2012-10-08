/*
ID:dingyag1
LANG:C++
TASK:prefix
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

#define  MAX(a,b) (a)>(b)?(a):(b)
using namespace std;

bool dp[200001];
string S;
vector<string> P;


int main()
{
	freopen("prefix5.in","r",stdin);
	freopen("prefix5.out","w",stdout);
	string s;
	int i,j,t2,max=0;
	bool f;
	queue<int> que;


	while (cin>>s,s!=".")
	{
		P.push_back(s);
	}
	while (getline(cin,s))
	{
		S+=s;
	}
//	cin>>S;
	que.push(0);

	while (!que.empty())
	{
		if (que.front()>max)
		{
			max=que.front();
		}

		for (i=0;i<P.size();++i)
		{
			if (P[i].size()<=S.size()-que.front())
			{
				t2=que.front()+P[i].size();
				if (dp[t2])
				{
					continue;
				}
				f=0;
				for (j=0;j<P[i].size();++j)
				{
					if (P[i][j]!=S[que.front()+j])
					{
						f=1;
						break;
					}
				}
				if (!f)
				{
					que.push(t2);
					dp[t2]=1;
				}
			}
		}
		que.pop();

	}

	cout<<max<<endl;

//	cout<<go(0)<<endl;
	return 0;
}

