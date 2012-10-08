/*
ID:dingyag1
LANG:C++
TASK:frameup
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

class rect
{
public:
	int id;
	int x1,y1,x2,y2;
};

int H,W;
char mymap[32][32];
bool steped[26];
map<char,rect> index;
set<string> RR;

bool can(char c);
void change(char c);
void DFS(string R,int n);

int main()
{
	freopen("frameup.in","r",stdin);
	freopen("frameup.out","w",stdout);
	
	int i,j;
	char c;
	rect tmp;
	
	cin>>H>>W;

	for (i=0;i<H;++i)
	{
		for (j=0;j<W;++j)
		{
			cin>>c;
			mymap[i][j]=c;
			if (c=='.')
			{
				continue;
			}
			if (index.find(c)==index.end())
			{
				tmp.id=index.size();
				tmp.x1=tmp.x2=i;
				tmp.y1=tmp.y2=j;
				index[c]=tmp;

//				cout<<"insert: "<<c<<endl;
			}else
			{
				map<char,rect>::iterator it=index.begin();
/*				while (it!=index.end())
				{
					cout<<" "<<it->first;
					++it;
				}cout<<endl;
*/
				if (i<index[c].x1)
				{
					index[c].x1=i;
				}
				if (i>index[c].x2)
				{
					index[c].x2=i;
				}
				if (j<index[c].y1)
				{
					index[c].y1=j;
				}
				if (j>index[c].y2)
				{
					index[c].y2=j;
				}
				
			}
		}
	}

	
	string R;

	DFS(R,index.size());
	
	set<string>::iterator iit=RR.begin();
	while (iit!=RR.end())
	{
		cout<<*iit<<endl;
		iit++;
	}
	
	return 0;
}


void DFS(string R,int n)
{

	if (n==0)
	{
		reverse(R.begin(),R.end());
		RR.insert(R);
		//cout<<R<<endl;
	}

	map<char,rect>::iterator it=index.begin();
	int i,j;
	char old[32][32];

	it=index.begin();
	while (it!=index.end())
	{
		if (steped[it->first-'A'])
		{
			it++;
			continue;
		}
		if (can(it->first))
		{
			for (i=0;i<H;++i)
			{
				for(j=0;j<W;++j)
				{
					old[i][j]=mymap[i][j];
				}
			}
			change(it->first);
			R+=(it->first);
			steped[it->first-'A']=1;
			DFS(R,n-1);
			steped[it->first-'A']=0;
			R.erase(R.size()-1,1);
			for (i=0;i<H;++i)
			{
				for(j=0;j<W;++j)
				{
					mymap[i][j]=old[i][j];
				}
			}
		}
		it++;
	}
}

bool can(char c)
{
	int i,j;

	j=index[c].y1;
	for (i=index[c].x1;i<=index[c].x2;++i)
	{
			if (mymap[i][j]!=c && mymap[i][j]!='.')
			{
				return false;
			}
	}

	j=index[c].y2;
	for (i=index[c].x1;i<=index[c].x2;++i)
	{
			if (mymap[i][j]!=c && mymap[i][j]!='.')
			{
				return false;
			}
	}

	i=index[c].x1;

	for (j=index[c].y1;j<=index[c].y2;++j)
	{
		if (mymap[i][j]!=c && mymap[i][j]!='.')
		{
				return false;
		}
	}
	i=index[c].x2;
	for (j=index[c].y1;j<=index[c].y2;++j)
	{
		if (mymap[i][j]!=c && mymap[i][j]!='.')
		{
			return false;
		}
	}

	return true;
}

void change(char c)
{
	int i,j;
	for (i=index[c].x1;i<=index[c].x2;++i)
	{
		mymap[i][index[c].y1]='.';
		mymap[i][index[c].y2]='.';
	}
	for (i=index[c].y1;i<=index[c].y2;++i)
	{
		mymap[index[c].x1][i]='.';
		mymap[index[c].x2][i]='.';
	}
}