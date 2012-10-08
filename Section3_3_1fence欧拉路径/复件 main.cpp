/*
ID:dingyag1
LANG:C++
TASK:fence
*/


#include <stdio.h>
#include <iostream>
#include <set>
#include <stack>
#include <algorithm>
#define MAXV 502
#define MAXD 10000000
using namespace std;


//define edge
class edge
{
public:
	int a,b;
};
//边集 排序函数
bool cmp (const edge &A,const edge &B)
{
	if (A.a<B.a)
		return true;
	if (A.a==B.a)
	{
		if (A.b<B.b)
		{
			return true;
		}
	}
	return false;
}
//////////////////////////

////////////////////////
bool Map[MAXV][MAXV];		//是否走过
edge E[3000]={0};			//edge
int index[MAXV][2];		//index[i][0] : pos  index[i][1] : end+1
int nE=0;
bool jiou[MAXV];
bool in[3000];
int main()
{
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);	
	int i,j,k,d,start,len;
	stack<int> stk,stk2,cir;
	cin>>nE;
	nE*=2;
	//输入边集E
	for (i=0;i<nE;i+=2)
	{
		cin>>j>>k;
		E[i].a=j;
		E[i].b=k;
		E[i+1].b=j;
		E[i+1].a=k;
		jiou[j]=!jiou[j];
		jiou[k]=!jiou[k];
		
	}
	//对边集E进行 起点升序排序
	sort(E,E+nE,cmp);
	//对E边集E 进行建立index索引，[0]表示起始位置[1] 表示结束位置+1
	index[E[0].a][0]=0;
	for (i=1;i<nE;++i)
	{
		if (E[i].a!=E[i-1].a)
		{
			index[E[i].a][0]=i;
			index[E[i-1].a][1]=i;
		}
	}
	index[E[i-1].a][1]=i;
	//寻找起始点
	
	start=E[0].a;
	for (i=0;i<MAXV;++i)
	{
		if (jiou[i])
		{
			start=i;
			break;
		}
	}

	//后期操作
	len=0;
	while(len!=(nE/2+1))
	{
		//cout<<"start:"<<start<<endl;
		i=index[start][0];
		bool f=0;
		for (;i<index[start][1];++i)
		{
			if (!in[i])
			{
				stk.push(start);
				start=E[i].b;
				in[i]=1;
				f=1;
				len++;
				break;

			}
		}
		if (!f)
		{
			cir.push(start);
			start=stk.top();
			len++;
		}
	//	len++;
	}

	while (!stk.empty())
	{

		stk2.push(stk.top());
		stk.pop();
	}
	while (!stk2.empty())
	{

		cout<<stk2.top()<<endl;
		stk2.pop();
	}
	if (!cir.empty())
	{

		while (!cir.empty())
		{
			cout<<cir.top()<<endl;
			cir.pop();
		}
	}


		//
}
