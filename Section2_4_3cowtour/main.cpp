/*
ID:dingyag1
LANG:C++
TASK:cowtour
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
/*
//#define  INF  inf 
//#define  DIS(i,j) sqrt((p[i][0]-p[j][0])*(p[i][0]-p[j][0])+(p[i][1]-p[j][1])*(p[i][1]-p[j][1]))
*/
using namespace std;



int N;
double map[161][161];
int p[161][2];
double mindis[161];
double INF=1e20;

double DIS(int i,int j)
{
	return sqrt((p[i][0]-p[j][0])*(p[i][0]-p[j][0])+(p[i][1]-p[j][1])*(p[i][1]-p[j][1]));
}

int main()
{
	freopen("cowtour.in","r",stdin);
	freopen("cowtour.out","w",stdout);
	
	int i,j,t,k;
	double max;
	char c;
	cin>>N;
	for (i=1;i<=N;++i)
	{
		cin>>p[i][0]>>p[i][1];
	}
	for (i=1;i<=N;++i)
	{
		mindis[i]=0;
	}
	for (i=1;i<=N;++i)
	{
		for (j=1;j<=N;++j)
		{
			cin>>c;
			if (i==j)
			{
				map[i][j]=0;
				continue;
			}
			if (c=='1')
			{
				map[i][j]=DIS(i,j);
			}
			else
			{
				map[i][j]=INF;
			}
		}
	}
	
	for (k=1;k<=N;++k)
	{
		for (i=1;i<=N;++i)
		{
			for (j=1;j<=N;++j)
			{
				if (map[i][k]+map[k][j]<map[i][j])
				{
					map[i][j]=map[i][k]+map[k][j];
				}
			}
		}
	}
	for (i=1;i<=N;++i)
	{
		mindis[i]=0;
		for (j=1;j<=N;++j)
		{
			if(map[i][j]!=INF/*!(map[i][j]-INF<0.01*INF& map[i][j]-INF>-0.01*INF)*/ && map[i][j]>mindis[i])
			{
				mindis[i]=map[i][j];
			}
		}
	}

	max=INF;
	for (i=1;i<=N;++i)
	{
		for (j=1;j<=N;++j)
		{
			if(map[i][j]==INF /*map[i][j]-INF>-0.01*INF && map[i][j]-INF<0.01*INF*/)
			{
				if (mindis[i]+mindis[j]+DIS(i,j)<max)
				{
					max=mindis[i]+mindis[j]+DIS(i,j);
				}
			}
		}
	}

	for (i=1;i<=N;i++)
		if (mindis[i]>max) max=mindis[i];
//	cout<<fixed<<setprecision(6)<<max<<endl;
	cout<<setprecision(6)<<setiosflags(ios::fixed  | ios::showpoint)<<max<<endl;
	return 0;
}

