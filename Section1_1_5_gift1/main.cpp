/*
ID: dingyag1
LANG: C++
TASK: gift1
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace  std;

int main()
{
	freopen("gift1.in","r",stdin);
	freopen("gift1.out","w",stdout);

	map<string,int> data;
	vector<string>	index;
	int n,i,m;
	string s;

	cin>>n;
	for (i=0;i<n;++i)
	{
		cin>>s;
		index.push_back(s);
		data[s]=0;
	}

	while (cin>>s)
	{
		cin>>m>>n;
		if (n!=0)
		{
			data[s]-=m/n*n;
		}
		
		for (i=0;i<n;++i)
		{
			cin>>s;
			data[s]+=m/n;
		}
	}
	for (i=0;i<index.size();++i)
	{
		cout<<index[i]<<" "<<data[index[i]]<<endl;
	}



}