/*
ID:dingyag1
LANG:C++
TASK:shopping
*/

#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class YH
{
public:
	int n;
	int goods[5][2]; //id an num
	int price;
};

class GOODS
{
public:
	int id;
	int need;
	int price;
};
int dp[6][6][6][6][6]={0};
int S,B;
GOODS buy[5];
vector<YH> youhui;
map<int,int> index;

bool can(int i)
{
	int j;
	for (j=0;j<youhui[i].n;++j)
	{
		if (index.find(youhui[i].goods[j][0])==index.end())
		{
			return false;
		}
	}
	return true;
	
}

bool can2(int i,int cond[5])
{
	int j;
	for (j=0;j<youhui[i].n;++j)
	{
		if (cond[index[youhui[i].goods[j][0]]]<youhui[i].goods[j][1])
		{
			return false;
		}
	}
	return true;
}
int digui(int cond[5])
{
	int i,j;
	int cond2[5];
	int t,min=1000000;
	if (dp[cond[0]][cond[1]][cond[2]][cond[3]][cond[4]])
	{
		return dp[cond[0]][cond[1]][cond[2]][cond[3]][cond[4]];
	}
	if (cond[0]==0&&cond[1]==0&&cond[2]==0&&cond[3]==0&&cond[4]==0)
	{
		return 0;
	}
	for (i=0;i<youhui.size();++i)
	{
		if (can2(i,cond))
		{
			for (j=0;j<5;++j)
				cond2[j]=cond[j];
			for (j=0;j<youhui[i].n;++j)
			{
				 cond2[index[youhui[i].goods[j][0]]]=cond[index[youhui[i].goods[j][0]]]-youhui[i].goods[j][1];
			}
			t=digui(cond2)+youhui[i].price;
			if (t<min)
			{
				min=t;
			}
		}
	}
	dp[cond[0]][cond[1]][cond[2]][cond[3]][cond[4]]=min;
	return min;
}


int main()
{
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	int i,j,n,c,k;
	int cond[5]={0};
	YH yh;

	cin>>S;
	for (i=0;i<S;++i)
	{
		cin>>n;
		yh.n=n;
		for (j=0;j<n;++j)
		{
			cin>>yh.goods[j][0]>>yh.goods[j][1];
		}
		cin>>yh.price;
		youhui.push_back(yh);
	}
	cin>>B;
	for (i=0;i<B;++i)
	{
		cin>>buy[i].id>>buy[i].need>>buy[i].price;
		index[buy[i].id]=i;
		cond[i]=buy[i].need;
		
		yh.n=1;
		yh.goods[0][0]=buy[i].id;
		yh.goods[0][1]=1;
		yh.price=buy[i].price;
		youhui.push_back(yh);

	}
	//去掉不能用的优惠

	for (i=0;i<youhui.size();++i)
	{
		if (!can(i))
		{
			youhui.erase(youhui.begin()+i);
			--i;
		}
	}
	
	cout<<digui(cond)<<endl;
	
	return 0;
}

