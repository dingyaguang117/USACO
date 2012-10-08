/*
ID:dingyag1
LANG:C++
TASK:milk2
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
struct a
{
  int start,end;
  a(){};
  a(int i,int j):start(i),end(j){};


};

  bool cmp(const a &a1,const a &a2)
{
	return a1.start<a2.start;
}


using namespace std;

int main()
{

	freopen("milk2.in","r",stdin);
	freopen("milk2.out","w",stdout);



	vector<a> record;
	a temp;
	vector<a>::iterator it;
	int n,i,start,end=0,max=0,min=0,tmp;
	bool flag;

	cin>>n;
	for(i=0;i<n;++i)
	{
		flag=true;
		cin>>start>>end;
		for(it=record.begin();it!=record.end();)
		{
			if(end < it->start || start > it->end)
			{		
				it++;
				continue;
			}
			if(start >= it->start && end <= it->end)
			{
				flag=false;
				break;
			}
			/////////////////////
			if(start > it->start) start=it->start; 
			if(end < it->end) end=it->end;
			record.erase(it);
		}
		if(flag) 
		{
			temp.start=start;
			temp.end=end;
			record.push_back(temp);
		}
	}



	
	sort(record.begin(),record.end(),cmp);
	tmp=record.begin()->start;
	for(it=record.begin();it!=record.end();++it)
	{
		if(it->end-it->start>max) max=it->end-it->start;
		if(it->start-tmp>min) min=it->start-tmp;
		tmp=it->end;
	}
	cout<<max<<" "<<min<<endl;
	



		return 0;
}