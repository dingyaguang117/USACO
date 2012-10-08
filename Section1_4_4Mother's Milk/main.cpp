/*
ID:dingyag1
LANG:C++
TASK:milk3
*/

#include <stdio.h>
#include <iostream>
#include <list>
#include <queue>
#include <algorithm>
#include <set>
class cups
{
public:
	int a,b,c;
};

bool operator==(const cups &a,const cups &b)
{
	return (a.a==b.a&&a.b==b.b&&a.c==b.c);
}


using namespace std;


void proc(int &a,int &b,const int &sb);

int main()
{
	freopen("milk3.in","r",stdin);
	freopen("milk3.out","w",stdout);

	list<cups> r; 
	list<cups>::iterator it;
	queue<cups> q;
	set<int> result;
	set<int>::iterator it2;
	cups c_a;
	int a,b,c;

	cin>>a>>b>>c;
	c_a.a=0;c_a.b=0;c_a.c=c;

	q.push(c_a);
	r.push_back(c_a);

	while(!q.empty())
	{
		c_a=q.front();
		proc(c_a.a,c_a.b,b);
		if(find(r.begin(),r.end(),c_a)==r.end())
		{
			q.push(c_a);
			r.push_back(c_a);
		}


		c_a=q.front();
		proc(c_a.a,c_a.c,c);
		if(find(r.begin(),r.end(),c_a)==r.end())
		{
			q.push(c_a);
			r.push_back(c_a);
		}

		c_a=q.front();
		proc(c_a.b,c_a.a,a);
		if(find(r.begin(),r.end(),c_a)==r.end())
		{
			q.push(c_a);
			r.push_back(c_a);
		}

		c_a=q.front();
		proc(c_a.b,c_a.c,c);
		if(find(r.begin(),r.end(),c_a)==r.end())
		{
			q.push(c_a);
			r.push_back(c_a);
		}

		c_a=q.front();
		proc(c_a.c,c_a.a,a);
		if(find(r.begin(),r.end(),c_a)==r.end())
		{
			q.push(c_a);
			r.push_back(c_a);
		}

		c_a=q.front();
		proc(c_a.c,c_a.b,b);
		if(find(r.begin(),r.end(),c_a)==r.end())
		{
			q.push(c_a);
			r.push_back(c_a);
		}

		q.pop();

				
	}
	it=r.begin();
	while(it!=r.end())
	{
		if(it->a==0)
			result.insert(it->c);

		++it;
	}
	it2=result.begin();
	if(it2!=result.end())
		cout<<*it2;
	++it2;
	while(it2!=result.end())
	{
		cout<<" "<<*it2;
		++it2;
	}
	cout<<endl;

}

void proc(int &a,int &b,const int &sb)
{
	int t;
	t=a<sb-b?a:sb-b;
	a-=t;
	b+=t;
}