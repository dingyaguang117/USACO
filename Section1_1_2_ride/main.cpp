/*
ID: dingyag1
LANG: C++
TASK: ride
*/



#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream fin("ride.in");
	ofstream fout("ride.out");
	string s;
	int i,n,m;

	fin>>s;
	n=1;
	m=1;
	for(i=0;i<s.size();++i)
	{
		n*=s[i]-'A'+1;
		n%=47;
	}
	fin>>s;
	for(i=0;i<s.size();++i)
	{
		m*=s[i]-'A'+1;
		m%=47;
	}
	if(n==m)
		fout<<"GO";
	else
		fout<<"STAY";
	fout<<endl;
	return 0;

}