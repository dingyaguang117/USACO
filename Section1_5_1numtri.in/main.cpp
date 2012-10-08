/*
ID:dingyag1
LANG:C++
TASK:numtri
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int a[1001][1001];

int main()
{
	freopen("numtri.in","r",stdin);
	freopen("numtri.out","w",stdout);
	int n,i,j,m,mn,max;
	cin>>n;

	for (i=1;i<n+1;++i)
	{
		for (j=0;j<i;++j)
		{
			cin>>a[i][j];
		}
	}

	//将 DP 数据存在坐标交换区域
	a[0][1]=a[1][0];
	for (i=2;i<n+1;++i)
	{
		for (j=0;j<i;++j)
		{
			m=mn=0;
			if (j>0)
			{
				m=a[j-1][i-1];
			}
			if (j<i)
			{
				mn=a[j][i-1];
			}
			a[j][i]=a[i][j]+(m>mn?m:mn);
		}
	}
	max=0;
	for (i=0;i<n;++i)
	{
		if (a[i][n]>max)
		{
			max=a[i][n];
		}
	}
	cout<<max<<endl;
/*
	for (i=0;i<n+1;++i)
	{
		for (j=0;j<n+1;++j)
		{
			cout<<a[i][j]<< " ";
		}
		cout<<endl;
	}
*/
	return 0;
}