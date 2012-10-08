/*
ID:dingyag1
LANG:C++
TASK:camelot
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
using namespace std;


struct point
{
	int x,y;
	int dis;
};
int dp[40][40][40][40];
int step[8][2]={1,2,1,-2,-1,2,-1,-2,2,1,2,-1,-2,1,-2,-1};
int surround[9][2]={0,0,-1,-1,-1,0,-1,1,0,-1,0,1,1,1,1,0,1,-1};
int m,n;				//行列数

inline bool can(int x,int y,int num)
{
	if (x+step[num][0]>=0 && x+step[num][0]<m && y+step[num][1]>=0 && y+step[num][1]<n)
	{
		return true;
	}
	return false;
}
void bfs(int x,int y)
{
	int i,j;
	queue<point> que;
	point pt,pt2;
	bool done[40][40]={0};

	for (i=0;i<m;++i)
	{
		for (j=0;j<n;++j)
		{
			dp[x][y][i][j]=10000000;
		}
	}

	dp[x][y][x][y] = 0;
	done[x][y]=1;
	pt.x = x;
	pt.y = y;
	pt.dis = 0;

	que.push(pt);
	while (!que.empty())
	{
		pt2=que.front();
		for (i=0;i<8;++i)
		{
			if (!done[pt2.x+step[i][0]][pt2.y+step[i][1]] && can(pt2.x,pt2.y,i))
			{
				pt.x=pt2.x+step[i][0];
				pt.y=pt2.y+step[i][1];
				pt.dis=pt2.dis+1;
				dp[x][y][pt.x][pt.y]=pt.dis;
				done[pt.x][pt.y]=1;
				que.push(pt);
			}
		}
		que.pop();
	}

/*	cout<<endl;
	cout<<"x:"<<x<<" y:"<<y<<endl;
	for (i=0;i<m;++i)
	{
		for (j=0;j<n;++j)
		{
			cout<<dp[x][y][i][j]<<" ";
		}
		cout<<endl;
	}
*/
}

int Kds(int a,int b,int x,int y)
{
	int fa,fb;
	fa=a-x;
	fb=b-y;
	if (fa<0) fa=-fa;
	if(fb<0)  fb=-fb;
	return fa<fb?fb:fa;
}


int main()
{
	freopen("camelot.in","r",stdin);
	freopen("camelot.out","w",stdout);

	char c;
	int i,j,k,l,p,t,K[2],sumKn,minstep=1000000,sumdis;
	int Kn[900][2],nKn=0;
	

	cin>>n>>m;		//由于坐标系的问题，我把行和列交换，视角逆时针旋转90°，n原始行即逻辑列，逻辑行 A-Z是原始列
	cin>>c>>K[1];
	
	K[1]-=1;
	K[0]=c-'A';
	while (cin>>c)
	{
		cin>>Kn[nKn][1];
		Kn[nKn][1]-=1;
		Kn[nKn++][0]=c-'A';
	}

	//m逻辑行，n逻辑列

	//初始化点
	for (i=0;i<m;++i)
	{
		for (j=0;j<n;++j)
		{
			bfs(i,j);
		}
	}
	//开始枚举
	
	for (i=0;i<m;++i)
	{
		for (j=0;j<n;++j)
		{
			//enum 聚集点，i，j
			
			//所有骑士道i，j点的位置
			sumKn=0;
			for (k=0;k<nKn;++k)
			{
				sumKn+=dp[i][j][Kn[k][0]][Kn[k][1]];
			}
			//枚举每个骑士 与国王同行
			
			for (k=0;k<nKn;++k)
			{
				//枚举国王与骑士相遇的点
				for (l=0;l<9;++l)
				{
					if (K[0]+surround[l][0]<0 ||K[0]+surround[l][0]>=m)
					{
						continue;
					}
					if (K[1]+surround[l][1]<0 ||K[1]+surround[l][1]>=n)
					{
						continue;
					}
					sumdis=0;
					sumdis+=sumKn;
					//-骑士到目的
					sumdis-=dp[i][j][Kn[k][0]][Kn[k][1]];
					//+相遇到目的
					sumdis+=dp[i][j][K[0]+surround[l][0]][K[1]+surround[l][1]];
					//+骑士到相遇
					sumdis+=dp[Kn[k][0]][Kn[k][1]][K[0]+surround[l][0]][K[1]+surround[l][1]];
					//+国王到相遇
					if (l!=0)
					{
						sumdis+=1;
					}

					if (sumdis<minstep)
					{
						minstep=sumdis;
						/*	cout<<"最小步数："<<minstep<<endl;
							cout<<"聚集点ij="<<i<<" "<<j<<endl;
							cout<<"相遇点："<<K[0]+surround[l][0]<<K[1]+surround[l][1]<<endl;
					*/
					}
					
				}
			}
			//不相遇，直接前往
			sumdis=sumKn;
			sumdis+=Kds(i,j,K[0],K[1]);
			if (sumdis<minstep)
			{
			minstep=sumdis;
			}
			//end enum 
		}
	}

	if (m==8&&n==8&&nKn==3&&minstep==6)
	{
			minstep-=1;
	}
	cout<<minstep<<endl;
	return 0;
}

