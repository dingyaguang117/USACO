/*
ID:dingyag1
LANG:C++
TASK:milk
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

bool operator<(const pair<int,int> &a,const pair<int,int> &b)
{
	return a.first<b.first?1:0;
}


int main()
{

	freopen("milk.in","r",stdin);
	freopen("milk.out","w",stdout);


	int n,m,i,sum=0;
	pair<int,int> a;
	vector< pair<int,int> > list;

	cin>>n>>m;

	for(i=0;i<m;++i)
	{
		cin>>a.first>>a.second;
		list.push_back(a);
	}
	sort(list.begin(),list.end());


	for(i=0;i<m;++i)
	{
		if(n>list[i].second)
		{
			n-=list[i].second;
			sum+=list[i].first*list[i].second;
		}
		else
		{
			sum+=list[i].first*n;
			break;
		}
	}
	cout<<sum<<endl;





	return 0;
}
