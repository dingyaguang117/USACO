/*
ID:dingyag1
LANG:C++
TASK:namenum
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


int main()
{
	freopen("namenum.in","r",stdin);
	freopen("namenum.out","w",stdout);
	
	vector<string> db;
	string s,s2;
	char ser[26]={'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','7','7','7','8','8','8','9','9','9','9'};
	int i,n,j;
	char ss[15];
	bool f;
	ifstream file("dict.txt");

	while (file>>s)
	{
		db.push_back(s);
	}

	cin>>s;
	f=0;
	for (i=0;i<db.size();++i)
	{
		if (db[i].size()==s.size())
		{
			s2=db[i];
			for (j=0;j<s.size();++j)
			{
				s2[j]=ser[s2[j]-'A'];
			}
			if (s==s2)
			{
				cout<<db[i]<<endl;
				f=1;
			}
		}
	}

	if(!f) cout<<"NONE"<<endl;
	return 0;
}