/*
ID:dingyag1
LANG:C++
TASK:beads
*/

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int main()
{
	freopen("beads.in","r",stdin);
	freopen("beads.out","w",stdout);
	int n,i,j,f,pre,most,hou;
	char precolor;
	bool firstw;
	string s;
	cin>>n;
	cin>>s;

	for (i=0;i<s.size();++i)
	{
		if (s[i+1]='w'||s[i+1]==s[i])
		{
			continue;
		}
		else 
		{
			j=i+1;
			j%=s.size();
			while(j!=i)
			{
				
				if (s[j]!=s[i+1]&&s[j]!='w')
				{
					hou=(j-i-1+s.size())%s.size();
					break;
				}
				++j;
				j%=s.size();
			}
		}
	}
	cout<<most<<endl;

}