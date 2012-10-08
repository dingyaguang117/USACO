/*
ID:dingyag1
LANG:C++
TASK:fence6
*/

#include <stdio.h>
#include <iostream>
#include <set>
#include <queue>
#include <map>
using namespace std;

class fence
{
public:
	int id;
	int length;
	int nl,nr;
	int SL[8],SR[8];
	int dis;
};

//重载优先队列中 比较fence的 <符号
bool operator < (const fence &a,const fence &b)
{
	return a.dis>b.dis;
}

map<int,fence> fSet;

//边存储 dij 最短路径
int E_dij(int n)
{
	int i,j,id;
	fence tmp;
	bool in[102]={0};
	priority_queue<fence> que;

	in[n]=1;
	for(i=0;i<fSet[n].nl;++i)		//枚举 左边集
	{
		id=fSet[n].SL[i];
		fSet[id].dis=fSet[id].length;
		que.push(fSet[id]);
		in[id]=1;
	}

	while (!que.empty())
	{
		tmp=que.top();
		
		//判断结束
		for (i=0;i<fSet[n].nr;++i)	//在搜索边的右边集找
		{
			id=fSet[n].SR[i];
			if (tmp.id==id)
			{
				return tmp.dis;
			}
		}
		//搜索下一边
		if (in[tmp.SL[0]])		//左集入，搜索右集
		{
			for (i=0;i<tmp.nr;++i)
			{
				id=tmp.SR[i];
				if (!in[id])
				{
					fSet[id].dis=tmp.dis+fSet[id].length;
//					cout<<"before insert que.top: "<<que.top().id<<" "<<que.top().dis<<endl;
					que.push(fSet[id]);
//					cout<<"after insert que.top: "<<que.top().id<<" "<<que.top().dis<<endl<<endl;
					in[id]=1;
				}
				
			}
		}
		else
		{
			for (i=0;i<tmp.nl;++i)
			{
				id=tmp.SL[i];
				if (!in[id])
				{
					fSet[id].dis=tmp.dis+fSet[id].length;
//					cout<<"before insert que.top: "<<que.top().id<<" "<<que.top().dis<<endl;
					que.push(fSet[id]);
//					cout<<"after insert que.top: "<<que.top().id<<" "<<que.top().dis<<endl<<endl;
					in[id]=1;
				}
				
			}
		}
//		cout<<"before que.top: "<<que.top().id<<" "<<que.top().dis<<endl;
		
		que.pop();
//		cout<<"after que.top: "<<que.top().id<<" "<<que.top().dis<<endl<<endl;
	}
	

	return 0;
}


int main()
{
	freopen("fence6.in","r",stdin);
	freopen("fence6.out","w",stdout);
	
	fence tmp;
	int N,i,j,min=1000000;
	cin>>N;
	for (i=0;i<N;++i)
	{
		cin>>tmp.id>>tmp.length>>tmp.nl>>tmp.nr;
		for (j=0;j<tmp.nl;++j)
		{
			cin>>tmp.SL[j];
		}
		for (j=0;j<tmp.nr;++j)
		{
			cin>>tmp.SR[j];
		}
		fSet[tmp.id]=tmp;
	}
	for (i=1;i<=N;++i)
	{
		int t=E_dij(i);
		if (t)
		{
			if (fSet[i].length+t<min)
			{
				min=fSet[i].length+t;
			}
		}
		
	}
	cout<<min<<endl;
	return 0;
}

