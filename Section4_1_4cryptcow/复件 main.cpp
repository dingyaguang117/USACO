/*
ID:dingyag1
LANG:C++
TASK:cryptcow
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int digui(string s)
{
	if (s=="Begin the Escape execution at the Break of Dawn")
	{
		return 0;
	}
	vector<int> C,O,W;
	string s2;
	int i,j,k,r;

	for (i=0;i<s.size();++i)
	{
		switch (s[i])
		{
		case 'C':
			C.push_back(i);
			break;
		case 'O':
			O.push_back(i);
			break;
		case 'W':
			W.push_back(i);
			break;
		}		
	}
	if (C.size()!=O.size() || C.size()!=W.size() || O.size()!=W.size())
	{
		return -1;
	}

	for (j=0;j<O.size();++j)
	{
		for (i=0;i<C.size();++i)
		{
			if (C[i]>O[j])
			{
				break;
			}
			for (k=0;k<W.size();++k)
			{
				if (O[j]>W[k])
				{
					continue;
				}
				s2=s;
				string s3(s2.begin()+C[i]+1,s2.begin()+O[j]);
				string s4(s2.begin()+O[j]+1,s2.begin()+W[k]);
				string s5(s2.begin()+W[k]+1,s2.end());
				s2=s2.substr(0,C[i]);
				s2+=s4;
				s2+=s3;
				s2+=s5;
				if ((r=digui(s2))!=-1)
				{
					return r+1;
				}
			}
		}
	}

	return -1;
}

int main()
{
	freopen("cryptcow.in","r",stdin);
	freopen("cryptcow.out","w",stdout);
	string s;
	int t;

//	cin>>s;
	getline(cin,s);

	t=digui(s);
	if (t!=-1)
	{
		cout<<1<<" "<<t<<endl;
	}else
		cout<<0<<" "<<0<<endl;
	
	return 0;
}

