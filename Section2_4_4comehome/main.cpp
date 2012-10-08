/*
ID:dingyag1
LANG:C++
TASK:comehome
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;

map<char,int> index;

int Map[53][53];

int main()
{
	freopen("comehome.in","r",stdin);
	freopen("comehome.out","w",stdout);
	
	int n,i,j,k,len=0;
	char c1,c2;
	cin>>n;
	
	for (k=1;k<=52;++k)
	{
		for (i=1;i<=52;++i)
		{
			if(i==k)
				Map[i][k]=0;
			else
				Map[i][k]=10000000;
		}
	}


	for(i=0;i<n;++i)
	{
		cin>>c1>>c2>>j;
		if(index.find(c1)==index.end())
		{
			index[c1]=++len;
		}
		if(index.find(c2)==index.end())
		{
			index[c2]=++len;
		}
		if (j<Map[index[c1]][index[c2]])
		{
			Map[index[c1]][index[c2]]=j;
			Map[index[c2]][index[c1]]=j;
		}
		
	}



	for (k=1;k<=len;++k)
	{
		for (i=1;i<=len;++i)
		{
			for (j=1;j<=len;++j)
			{
				if (Map[i][k]+Map[k][j]<Map[i][j])
				{
					Map[i][j]=Map[i][k]+Map[k][j];
				}
			}
		}
	}
	int min=10000000;
	char Cmin;

	map<char,int>::iterator it;
	it=index.begin();
	while (it!=index.end())
	{
	//	cout<<it->first<<" "<<it->second<<endl;
		if (it->first>='a')
		{
			break;
		}
		if (it->first=='Z')
		{
			++it;
			continue;
		}
		if (Map[it->second][index['Z']]<min)
		{
			Cmin=it->first;
			min=Map[it->second][index['Z']];
		}

		++it;
	}
	/*
	for (i=1;i<=len;++i)
	{
		if (Map[index['Z']][i] && Map[index['Z']][i]<min)
		{
			min=Map[index['Z']][i];
		}
	}*/
	cout<<Cmin<<" "<<min<<endl;
	return 0;
}

