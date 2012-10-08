/*
ID:dingyag1
LANG:C++
TASK:calfflac
*/

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


int main()
{
	freopen("calfflac.in","r",stdin);
	freopen("calfflac.out","w",stdout);
	string s,st;
	int num,i,j,k,max=1,start,end;
	bool flag;
	//cin>>s;
	while (!cin.eof())
	{
		getline(cin,st);
		s+=st;
		s+='\n';
	}
	
	st=s;

	for (i=0;i<s.size();++i)
	{
		if (!(s[i]<='Z'&&s[i]>='A'||s[i]<='z'&&s[i]>='a'))
		{
			s.erase((string::size_type)i,1);
			--i;
		}
		else if (s[i]<='Z'&&s[i]>='A')
		{
			s[i]-='A'-'a';
		}
	}
	

	//cout<<s<<endl<<"========="<<endl;
	for (i=0;i<s.size();++i)
	{

		////////////////////
		j=i;
		k=i;
		num=1;
		while(j>=0&&k<s.size())
		{
			if (s[j]!=s[k])
			{
				break;
			}
			--j;++k;
		}
		if (k-j-1>max)
		{
			max=k-j-1;
			start=j+1;
			end=k-1;
		}
		/////////////////////
		j=i;
		k=i+1;
		while(j>=0&&k<s.size())
		{
			if (s[j]!=s[k])
			{
				break;
			}
			
			--j;++k;
		}
		if (k-j-1>max)
		{
			max=k-j-1;
			start=j+1;
			end=k-1;
		}		


	}
	cout<<max<<endl;
	num=-1;

	for(i=0;;++i)
	{
		if (st[i]<='Z'&&st[i]>='A'||st[i]<='z'&&st[i]>='a')
		{
			num++;
		}
		if (num>=start)
		{

			cout<<st[i];
			if (num>=end)
			{
				break;
			}
		}

		
	}
	cout<<endl;
	return 0;
}