/*
ID:dingyag1
LANG:C++
TASK:fence4
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm> 
//#define  debug
#define  eps 0.0000001 
using namespace std;

int C[2];



void swap(double & a,double &b)
{
	double t;
	t=a;
	a=b;
	b=t;
}


class edge
{
public:
	int id;
	int x1,y1,x2,y2;
	double d1,d2;
	double dis;
public:
	edge(int g,int a=0,int b=0,int c=0,int d=0,int c1=0,int c2=0):id(g),x1(a),y1(b),x2(c),y2(d)
	{
		cptDis(c1,c2);
		cptDegree(c1,c2);
	}
	void cptDis(int c1,int c2)
	{
		double dis1,dis2,dd;
		dis=sqrt((x1+x2-2*c1)*(x1+x2-2*c1)+(y1+y2-2*c2)*(y1+y2-2*c2));
		dis1=sqrt((x1-c1)*(x1-c1)+(y1-c2)*(y1-c2));
		dis2=sqrt((x2-c1)*(x2-c1)+(y2-c2)*(y2-c2));
		dd=dis1<dis2?dis1:dis2;

		dis=dd+(dis-dd)/10;
	}
	void cptDegree(int c1,int c2)
	{
		if ((x1-c1)*(y2-c2)-(x2-c1)*(y1-c2)>0)
		{
			d1=atan2(y1-c2,x1-c1);
			d2=atan2(y2-c2,x2-c1);
		}
		else
		{
			d2=atan2(y1-c2,x1-c1);
			d1=atan2(y2-c2,x2-c1);
		}
/*
		if (d1<0 && d2>0)
		{
			d1+=3.1415926*2;
		}*/
	}

};

class rang
{
public:
	double d1,d2;
	rang(int a=0,int b=0):d1(a),d2(b){}
};

bool cross(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
	if (((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1))*((x2-x1)*(y4-y1)-(x4-x1)*(y2-y1))<0)
	{	
			return true;
	}
	
	return false;
}

bool cross_seg(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
	if (((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1))*((x2-x1)*(y4-y1)-(x4-x1)*(y2-y1))<0)
	{
		if (((x4-x3)*(y1-y3)-(x1-x3)*(y4-y3))*((x4-x3)*(y2-y3)-(x2-x3)*(y4-y3))<0)
		{
			
			return true;
		}
	}
	
	return false;
}

bool cmp(const edge &e1,const edge &e2)
{

#ifdef debug
	cout<<endl<<"E1 x1,y1: ("<<e1.x1<<","<<e1.y1<<")"<<" x2,y2: ("<<e1.x2<<","<<e1.y2<<")"<<endl;
	cout<<"E2 x1,y1: ("<<e2.x1<<","<<e2.y1<<")"<<" x2,y2: ("<<e2.x2<<","<<e2.y2<<")"<<endl;
#endif
	//return false;
	if(cross(C[0],C[1],e1.x1,e1.y1,e2.x1,e2.y1,e2.x2,e2.y2)
		|| cross(C[0],C[1],e1.x2,e1.y2,e2.x1,e2.y1,e2.x2,e2.y2))		//有覆盖
	{
		if (cross_seg(C[0],C[1],e1.x1,e1.y1,e2.x1,e2.y1,e2.x2,e2.y2)	//e2 覆盖e1
			|| cross_seg(C[0],C[1],e1.x2,e1.y2,e2.x1,e2.y1,e2.x2,e2.y2))
		{
		//	cout<<"结果：大于"<<endl;
			return false;
		}
		if (cross_seg(C[0],C[1],e2.x1,e2.y1,e1.x1,e1.y1,e1.x2,e1.y2)		//e1 覆盖e2
			|| cross_seg(C[0],C[1],e2.x2,e2.y2,e1.x1,e1.y1,e1.x2,e1.y2))
		{
		//	cout<<"结果：小于"<<endl;
			return true;
		}
		//完全包含，继续判断
		double dd1,dd2;
		dd1=e1.d2-e1.d1;
		if (dd1<0)
		{
			dd1+=3.14159265358*2;
		}
		dd2=e2.d2-e2.d1;
		if (dd2<0)
		{
			dd2+=3.14159265358*2;
		}
		if (dd1<dd2)		//角度大 的被覆盖
		{
		//	cout<<"二次比较结果：小于"<<endl;
			return true;
		}
		else
		//	cout<<"二次比较结果：大于"<<endl;
			return false;
	}
	
	//cout<<"比较距离"<< (int)(e1.dis<e2.dis) <<endl;
	return e1.dis<e2.dis;

}
bool cmp2(const edge &e1,const edge &e2)
{
	return e1.id<e2.id;
}

int main()
{
	freopen("fence4.in","r",stdin);
	freopen("fence4.out","w",stdout);
	
	int N,P[200][2],i,j;
	vector<edge> eSet;
	vector<edge> eR;
	vector<rang> cover;
	vector<int>	can;

	cin>>N;
	cin>>C[0]>>C[1];
	for (i=0;i<N;++i)
	{
		cin>>P[i][0]>>P[i][1];
	}
	for (i=1;i<N-1;++i)
	{
		eSet.push_back(edge(i-1,P[i-1][0],P[i-1][1],P[i][0],P[i][1],C[0],C[1]));
		
	}
	eSet.push_back(edge(N-2,P[0][0],P[0][1],P[N-1][0],P[N-1][1],C[0],C[1]));
	eSet.push_back(edge(N-1,P[N-2][0],P[N-2][1],P[N-1][0],P[N-1][1],C[0],C[1]));

	sort(eSet.begin(),eSet.begin()+N,cmp);

	for (i=0;i<N;++i)
	{
#ifdef debug
	cout<<"No."<<i<<" x1,y1: ("<<eSet[i].x1<<","<<eSet[i].y1<<") x2,y2: ("<<eSet[i].x2<<","<<eSet[i].y2<<")"<<endl;
		cout<<"   d1,d2 : "<<eSet[i].d1<<" "<<eSet[i].d2<<endl;
		cout<<"   dis   : "<<eSet[i].dis<<endl;
#endif
		rang tmp;
		bool done=0;
		bool in=0;
		double tp;
		int l,i1;
		tmp.d1=eSet[i].d1;
		tmp.d2=eSet[i].d2;
		tp=tmp.d2;
		if (tmp.d1>0 && tmp.d2<0)
		{
			tmp.d2=3.14159265358979;
			l=2;
		}
		else
			l=1;
		for (i1=0;i1<l;++i1)
		{
			if (i1==1)
			{
				tmp.d1=-3.14159265358979;
				tmp.d2=tp;
			}
			for (j=0;j<cover.size();++j)
			{
				
				if (tmp.d1<cover[j].d1-eps)
				{
					if (tmp.d2<cover[j].d1-eps)
					{
						cover.insert(cover.begin()+j,tmp);
						done=1;
						if (!in)
						{
							can.push_back(i);
							in=1;
						}
						
						break;
					}
					else if (tmp.d2<=cover[j].d2+eps)
					{
						cover[j].d1=tmp.d1;
						done=1;
						if (!in)
						{
							can.push_back(i);
							in=1;
						}
						break;
					}
					else
					{
						cover.erase(cover.begin()+j);
						j--;
						continue;
					}
				}
				else
					if (tmp.d1<=cover[j].d2+eps)
					{
						
						if (tmp.d2<=cover[j].d2+eps)
						{
							done=1;
							break;
						}
						else
						{
							tmp.d1=cover[j].d1;
							cover.erase(cover.begin()+j);
							j--;
							continue;
						}
					}
					else
						continue;
			}
			if (!done)
			{
				if (tmp.d1==tmp.d2)
				{
					continue;
				}
				if (!in)
				{
					can.push_back(i);
					in=1;
				}
				cover.push_back(tmp);
			}
		}
		
#ifdef debug

		cout<<"cover rang:"<<endl;
		for (int k=0;k<cover.size();++k)
		{
			cout<<cover[k].d1<<" "<<cover[k].d2<<" ";
		}
		cout<<endl<<endl;
#endif
	}
	
//	sort(can.begin(),can.end());

	for (i=0;i<can.size();++i)
	{
		eR.push_back(eSet[can[i]]);	
	}

	sort(eR.begin(),eR.end(),cmp2);

	cout<<eR.size()<<endl;
	for(i=0;i<eR.size();++i)
	{
		cout<<eR[i].x1<<" "<<eR[i].y1<<" "<<eR[i].x2<<" "<<eR[i].y2<<endl;
	}

	return 0;
}

