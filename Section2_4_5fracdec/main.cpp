/*
ID:dingyag1
LANG:C++
TASK:fracdec
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int done[100001];

class re
{
public:
	int shang;
	int yushu;
};
vector<re> vec;

int find(int yushu)
{
	return done[yushu];
}

int main()
{
	freopen("fracdec.in","r",stdin);
	freopen("fracdec.out","w",stdout);
	re r;
	int i,start,end;
	int a,b;
	int t=0;
	bool zhengchu=0;
	char ss[100];
	string s;
	cin>>a>>b;

	for (i=0;i<=b;++i)
	{
		done[i]=-1;
	}
	sprintf(ss,"%d",a/b);
	s+=ss;
	s+='.';
	a%=b;
	r.shang=a/b;
	r.yushu=a%b;
	vec.push_back(r);
	done[r.yushu]=0;
	for(i=1;;++i)
	{
		a*=10;
		r.shang=a/b;
		r.yushu=a%b;
		a=r.yushu;
		if (a==0)
		{
			zhengchu=1;
			vec.push_back(r);
			done[r.yushu]=i;
			break;
		}
		if ((start=find(r.yushu))!=-1)
		{
			end=i;
			vec.push_back(r);
			done[r.yushu]=i;
			break;
		}
		vec.push_back(r);
		done[r.yushu]=i;
	}
	if (zhengchu)
	{
		for (i=1;i<vec.size();++i)
		{
			s+=vec[i].shang+'0';
		}


		goto lend;
	
	}

		for (i=1;i<=start;++i)
		{
			s+=vec[i].shang+'0';
		}

	s+='(';
	for (i=start+1;i<=end;++i)
	{
		s+=vec[i].shang+'0';
	}
	s+=')';
	
lend:for (i=0;i<s.size();++i)
	{
		
		cout<<s[i];
		if (++t==76)
		{
			cout<<endl;
			t=0;
		}
	}
	 if (t!=0)
	 {
		 cout<<endl;
	 }
	return 0;
}

