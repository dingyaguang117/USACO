/*
ID:dingyag1
LANG:C++
TASK:castle
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

#define  U(a) !((a)&0x02)
#define  D(a) !((a)&0x08)
#define  L(a) !((a)&0x01)
#define  R(a) !((a)&0x04)

unsigned short map[50][50];			//map
unsigned short cla[50][50];			//room id
unsigned short que[2500][2];		//queue for flood fill
unsigned short cla_sum[2501];

int quelen;
int M,N;

int main()
{
	freopen("castle.in","r",stdin);
	freopen("castle.out","w",stdout);
	int i,j,num=0,qs,ql,max,max2,imax,jmax;
	char dr;
	cin>>N>>M;
	
	for (i=0;i<M;++i)
	{
		for (j=0;j<N;++j)
		{
			cin>>map[i][j];
		}
	}
	num=0;
	for (i=0;i<M;++i)
	{
		for (j=0;j<N;++j)
		{
			if (cla[i][j]==0)
			{
				num++;
				cla[i][j]=num;
				cla_sum[num]=1;
				qs=0;ql=1;
				que[0][0]=i;
				que[0][1]=j;
				//queque flood fill
				while (ql!=0)
				{
					int curi=que[qs][0],curj=que[qs][1];
					if (curi>0&&U(map[ curi ][ curj])&&!cla[curi-1][curj])
					{
						que[qs+ql][0]=curi-1;
						que[qs+ql][1]=curj;
						cla[curi-1][curj]=num;
						cla_sum[num]+=1;
						ql++;		
					}
					if (curi<M-1&&D(map[ curi ][ curj] )&&!cla[curi+1][curj])
					{
						que[qs+ql][0]=curi+1;
						que[qs+ql][1]=curj;
						cla[curi+1][curj]=num;
						cla_sum[num]+=1;
						ql++;		
					}
					if (curj>0&&L(map[ curi ][ curj] )&&!cla[curi][curj-1])
					{
						que[qs+ql][0]=curi;
						que[qs+ql][1]=curj-1;
						cla[curi][curj-1]=num;
						cla_sum[num]+=1;
						ql++;		
					}
					if (curj<N-1&&R(map[ curi ][ curj] )&&!cla[curi][curj+1])
					{
						que[qs+ql][0]=curi;
						que[qs+ql][1]=curj+1;
						cla[curi][curj+1]=num;
						cla_sum[num]+=1;
						ql++;		
					}

					ql--;	//pop first
					qs+=1;
				}

			}
		}
	}
	max2=0;
	for(j=0;j<N;++j)
	{
		for (i=M-1;i>=0;--i)
		{
			
			if (!U(map[i][j]) && cla[i][j]!=cla[i-1][j])
			{
				if (cla_sum[cla[i][j]]+cla_sum[cla[i-1][j]]>max2)
				{
					max2=cla_sum[cla[i][j]]+cla_sum[cla[i-1][j]];
					imax=i;
					jmax=j;
					dr='N';
				}
			}
			if (!R(map[i][j]) && cla[i][j]!=cla[i][j+1])
			{
				if (cla_sum[cla[i][j]]+cla_sum[cla[i][j+1]]>max2)
				{
					max2=cla_sum[cla[i][j]]+cla_sum[cla[i][j+1]];
					imax=i;
					jmax=j;
					dr='E';
				}
			}
		}
	}


/*
	for (i=0;i<M;++i)
	{
		for (j=0;j<N;++j)
		{
			cout<<cla[i][j]<<" ";
		}
		cout<<endl;
	}
*/	
	max=cla_sum[1];
	for (i=1;i<=num;++i)
	{
		if (cla_sum[i]>max)
		{
			max=cla_sum[i];
		}
			
	}
	
	cout<<num<<endl;
	cout<<max<<endl;
	cout<<max2<<endl<<imax+1<<" "<<jmax+1<<" "<<dr<<endl;
	return 0;
}