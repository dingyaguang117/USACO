/*
ID:dingyag1
LANG:C++
TASK:lamps
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

bool push[16][4]=
{
	0,0,0,0,
	1,0,0,0,
	0,1,0,0,
	0,0,1,0,
	0,0,0,1,
	1,1,0,0,
	1,0,1,0,
	1,0,0,1,
	0,1,1,0,
	0,1,0,1,
	0,0,1,1,
	1,1,1,0,
	1,1,0,1,
	1,0,1,1,
	0,1,1,1,
	1,1,1,1
};
int index[5][2]=//存储按下按钮个数，对应的状态位置的下标范围
{
	0,1,
	1,5,
	5,11,
	11,15,
	15,16
};		
int N,C;
class buff
{
public:
	bool l[101];
};


void do0(bool tmp[])
{
	int i;
	for(i=1;i<=N;++i)
		tmp[i]=!tmp[i];
}

void do1(bool tmp[])
{
	int i;
	for(i=1;i<=N;i+=2)
		tmp[i]=!tmp[i];
}

void do2(bool tmp[])
{
	int i;
	for(i=2;i<=N;i+=2)
		tmp[i]=!tmp[i];
}

void do3(bool tmp[])
{
	int i;
	for(i=1;i<=N;i+=3)
		tmp[i]=!tmp[i];
}

bool cmp(const buff&a, const buff &b)
{
	int i;
	for(i=1;i<=N;++i)
	{
		if(a.l[i]>b.l[i])
			return false;
		if(a.l[i]<b.l[i])
			return true;
		
	}

}

int main()
{
	freopen("lamps.in","r",stdin);
	freopen("lamps.out","w",stdout);
	int i,j,k,t;
	bool on[101]={0},off[101]={0},tmp[101]={0},f;
	vector<buff> r;
	buff bf;

	cin>>N>>C;
	
	while(cin>>t,t!=-1)
	{
		on[t]=1;
	}
	while(cin>>t,t!=-1)
	{
		off[t]=1;
	}

	/********************
	*如果C偶数，则可能四个按钮状态为，按下0，2，4个
	*奇数，可能按下1，3个
	*for C%2 to C ，步长2
	********************/
	
	for(i=C%2;i<=(C<4?C:4);i+=2)	// i= button's num be pushed
	{
		for(j=index[i][0];j<index[i][1];++j)	//j= zhuangtai ID
		{
			for(k=1;k<=N;++k) tmp[k]=1;
			if(push[j][0]) do0(tmp);
			if(push[j][1]) do1(tmp);
			if(push[j][2]) do2(tmp);
			if(push[j][3]) do3(tmp);
			
			f=0;
			for(k=1;k<=N;++k)
			{
				if(on[k]&&!tmp[k])
				{
					f=1;
					break;
				}
				if(off[k]&&tmp[k])
				{
					f=1;
					break;
				}
			}
			if(!f)
			{
				for(k=1;k<=N;++k)
				{
					bf.l[k]=tmp[k];
				}
				r.push_back(bf);
			}

			
		}
	}

	sort(r.begin(),r.end(),cmp);
	for(i=0;i<r.size();++i)
	{
		for(k=1;k<=N;++k)
		{
			cout<<r[i].l[k];
		}
		cout<<endl;
	}
	if(r.size()==0)
		cout<<"IMPOSSIBLE"<<endl;
	return 0;
}