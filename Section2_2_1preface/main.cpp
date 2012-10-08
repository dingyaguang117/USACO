/*
ID:dingyag1
LANG:C++
TASK:preface
*/

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

string s[4][9]=
{"I","II","III","IV","V","VI","VII","VIII","IX",
 "X","XX","XXX","XL","L","LX","LXX","LXXX","XC",
 "C","CC","CCC","CD","D","DC","DCC","DCCC","CM",
 "M","MM","MMM","","","","","",""
};
int A[4][10][7];
char ss[7]={'I','V','X','L','C','D','M'};
void dopre()
{
	int i,j,k;
	for (i=0;i<4;++i)
	{
		for (j=0;j<9;++j)
		{
			if (i==3&&j==3)
			{
				break;
			}
			for (k=0;k<s[i][j].size();++k)
			{
				switch (s[i][j][k])
				{
				case 'I':
					A[i][j+1][0]++;
					break;
				case 'V':
					A[i][j+1][1]++;
					break;
				case 'X':
					A[i][j+1][2]++;
					break;
				case 'L':
					A[i][j+1][3]++;
					break;
				case 'C':
					A[i][j+1][4]++;
					break;
				case 'D':
					A[i][j+1][5]++;
					break;
				case 'M':
					A[i][j+1][6]++;
					break;
				}
			}
		}
	}
}

int main()
{
	freopen("preface.in","r",stdin);
	freopen("preface.out","w",stdout);
	
	dopre();
	int n,i,j,tho,han,ten,one;
	int num[7]={0};
	cin>>n;
	for (i=1;i<=n;++i)
	{
		tho=i/1000;
		han=(i%1000)/100;
		ten=(i%100)/10;
		one=(i%10);

		for (j=0;j<7;++j)
		{
			num[j]+=A[0][one][j];
			num[j]+=A[1][ten][j];
			num[j]+=A[2][han][j];
			num[j]+=A[3][tho][j];
		}
	}
	for (i=0;i<7;++i)
	{
		if (num[i])
		{
			cout<<ss[i]<<" "<<num[i]<<endl;
		}
	}
	return 0;
}