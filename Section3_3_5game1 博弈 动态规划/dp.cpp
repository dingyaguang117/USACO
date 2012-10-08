/*
ID:dingyag1
LANG:C++
TASK:game1
*/
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
 
int A[100005];
int dp[2][100005][2];	// 2��������ѹ����0��ʾż������ 1��ʾ��������
						//��ʾ��ʼƫ�ơ�
						//2  0��ʾǰ�ߵ÷� 1��ʾ���ߵ÷�
int main()
{
    freopen("game1.in","r",stdin);
	freopen("game1.out","w",stdout);
	
    int N,sum=0,i,j;
    string sa,sb;
    cin>>N;
    for(i=0;i<N;++i)
    {
        scanf("%d",A+i);
		dp[1][i][1]=A[i];
		sum+=A[i];
    }
    //cin>>sa>>sb;
	for(i=2;i<=N;++i)
	{
		for(j=0;j<=N-i;++j)
		{
			int Cur=i%2;
			int Pre=(i+1)%2;
			if(dp[Pre][j][Pre]<dp[Pre][j+1][Pre])
			{
				dp[Cur][j][Cur]=dp[Pre][j][Cur]+A[j+i-1];
			}
			else
				dp[Cur][j][Cur]=dp[Pre][j+1][Cur]+A[j];
			dp[Cur][j][Pre]=dp[Pre][j][Pre];
		}
	}
	cout<<dp[0][0][0]<<" "<<sum-dp[0][0][0]<<endl;
	
}
