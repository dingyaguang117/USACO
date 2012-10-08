/*
ID:dingyag1
LANG:C++
TASK:contact
*/

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

class R
{
public:
	int n;
	int nbit;
	unsigned str;
};

bool operator == (const R& a,const R& b)
{
	return false;
}
bool operator < (const R& a,const R& b)
{
	if (a.n < b.n)
	{
		return true;
	}
	else if(a.n==b.n)
	{
		if (a.nbit <b.nbit)
		{
			return true;
		}
		else if ( a.nbit==b.nbit)
		{
			unsigned int t=1;
			t<<=a.nbit-1;
			while(t>0)
			{
				if (t&a.str < t&b.str)
				{
					return true;
				}
				if (t&a.str > t&b.str)
				{
					return false;
				}
				t>>=1;
			}
		}
		return false;
		
	}
	return false;
}

void show(multiset<R>::iterator p)
{
	unsigned t=1;
	t<<= (p->nbit-1);
	while (t)
	{
		cout<< ((t&(p->str))>0);
		t>>=1;
	}
}
bool str[200000];
bool out[50][12];
unsigned int num[4096];
int A,B,N;
multiset<R> result;
map< int,multiset<R> > fresult;
int main()
{
	freopen("contact.in","r",stdin);
	freopen("contact.out","w",stdout);	
	int i,j,len=0;
	char c;
	R r;
	cin>>A>>B>>N;
	while(cin>>c)
	{
		str[len++]=c=='1';
	}
	if (B>len)
	{
		B=len;
	}
	for (i=A;i<=B;++i)
	{
		unsigned int t=pow(2,i)+0.01;
		for (j=0;j<t;++j)
		{
			num[j]=0;
		}
		//begin i bit search
		// init t;
		t=0;
		for (j=0;j<i;++j)
		{
			t<<=1;
			t+=str[j];
		}
		num[t]++;
		for (j=i;j<len;++j)
		{
			t<<=1;
			int t2=1,len5=32-i;
			t2<<=i;
			while(len5--)
			{
				t&=(t2^0xFFFFFFFF);
				t2<<=1;
			}
			t+=str[j];
			num[t]++;
		}	
		//sort(num,num+int(pow(2,i)+0.01));
		for (j=0;j<int(pow(2,i)+0.01);++j)
		{
			r.str=j;
			r.nbit=i;
			r.n=num[j];

			if (r.n==0)
			{
				continue;
			}
			if (fresult.size()<N)
			{
				fresult[r.n].insert(r);
			}
			else
			{	
				if (r.n> ((fresult.begin())->first))
				{
					fresult[r.n].insert(r);
					if(fresult.size()>N) fresult.erase(fresult.begin());
				}
				else
				if (r.n==((fresult.begin())->first))
				{
					fresult[r.n].insert(r);
				}		
			}
		}

		//end i bit search
	}	
	map<int, multiset<R> >::reverse_iterator it=fresult.rbegin();
	while (it!=fresult.rend())
	{
		if (it->first<1)
		{
			break;
		}
		cout<<it->first<<endl;
		multiset<R>::iterator it2=it->second.begin();
		int cont=0;
		while(it2!=it->second.end())
		{
			show(it2);
			cont++;
			if (cont%6==0)
			{
				cout<<endl;
				++it2;
			}
			else
			 if ((++it2)!=(it->second.end())) cout<<" ";
			cont%=6;
		}
		if (cont)
		{
			cout<<endl;
		}
		++it;
	}	
	return 0;
}

