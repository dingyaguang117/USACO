/*
ID:dingyag1
LANG:C++
TASK:ttwo
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

enum item
{
	blank,rock
};

item map[10][10];

int main()
{
	freopen("ttwo.in","r",stdin);
	freopen("ttwo.out","w",stdout);
	char c;
	int i,j;
	int pf[3],pc[3];
	for(i=0;i<10;++i)
		for (j=0;j<10;++j)
		{
			cin>>c;
			if (c=='\n')
			{
				cin>>c;
			}
			switch(c)
			{
			case '.':
				map[i][j]=blank;
				break;
			case '*':
				map[i][j]=rock;
				break;
			case 'C':
				pc[0]=i;
				pc[1]=j;
				pc[2]=0;
				map[i][j]=blank;
				break;
			case 'F':
				pf[0]=i;
				pf[1]=j;
				pf[2]=0;
				map[i][j]=blank;
				break;
				
			}
			
		}

	for (i=1;i<160001;++i)
	{
//**************farmer move*****************
		switch(pf[2])
		{
		case 0:
			if (pf[0]>0 && map[pf[0]-1][pf[1]]==blank)
			{
				pf[0]-=1;
				break;
			}
			else
			{
				pf[2]+=1;
				pf[2]%=4;
				break;
			}
			
		case 1:
			if (pf[1]<9 && map[pf[0]][pf[1]+1]==blank)
			{
				pf[1]+=1;
				break;
			}
			else
			{
				pf[2]+=1;
				pf[2]%=4;
				break;
			}
		case 2:
			if (pf[0]<9 && map[pf[0]+1][pf[1]]==blank)
			{
				pf[0]+=1;
				break;
			}
			else
			{
				pf[2]+=1;
				pf[2]%=4;
				break;
			}
		case 3:
			if (pf[1]>0 && map[pf[0]][pf[1]-1]==blank)
			{
				pf[1]-=1;
				break;
			}
			else
			{
				pf[2]+=1;
				pf[2]%=4;
				break;
			}
		}
//**************cow move*****************
			switch(pc[2])
			{
			case 0:
				if (pc[0]>0 && map[pc[0]-1][pc[1]]==blank)
				{
					pc[0]-=1;
					break;
				}
				else
				{
					pc[2]+=1;
					pc[2]%=4;
					break;
				}
				
			case 1:
				if (pc[1]<9 && map[pc[0]][pc[1]+1]==blank)
				{
					pc[1]+=1;
					break;
				}
				else
				{
					pc[2]+=1;
					pc[2]%=4;
					break;
				}
			case 2:
				if (pc[0]<9 && map[pc[0]+1][pc[1]]==blank)
				{
					pc[0]+=1;
					break;
				}
				else
				{
					pc[2]+=1;
					pc[2]%=4;
					break;
				}
			case 3:
				if (pc[1]>0 && map[pc[0]][pc[1]-1]==blank)
				{
					pc[1]-=1;
					break;
				}
				else
				{
					pc[2]+=1;
					pc[2]%=4;
					break;
				}
			}
//**********judge**************
		if (pc[0]==pf[0]&&pf[1]==pc[1])
		{
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<0<<endl;
	return 0;
}

