/*
ID:dingyag1
LANG:C++
TASK:buylow
*/

#include <stdio.h>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
	freopen("buylow.in","r",stdin);
	freopen("buylow.out","w",stdout);
	
	int  N,S[5003],num[5003]={0},dp[5003]={0};
	int i,j,max=1,maxp;


	cin>>N;	

	for (i=1;i<=N;++i)
	{
		cin>>S[i];
		dp[i]=1;		//初始化dp为1
		num[i]=1;

	}
	///末尾+0 方便统计
	N++;
	S[N]=0;num[N]=1;dp[N]=1;
	
	///
	if (N==1)
	{
		maxp=1;
	}
	
	
	for (i=2;i<=N;++i)
	{
		bool visited[50001]={0};
		for (j=i-1;j>0;--j)
		{
			if (S[j]>S[i] && dp[j]+1>=dp[i])
			{
				
				if (dp[j]+1>dp[i])
				{
					dp[i]=dp[j]+1;
					num[i]=num[j];
					
					if (dp[i]>max)
					{
						max=dp[i];
						maxp=i;
					}
								//record
					
				}else
				if (dp[i]==dp[j]+1)
				{
					if (!visited[S[j]])
					{
						num[i]+=num[j];
					}else
					{
					//	num[i]+=num[j];
					}
					
				}
				
				visited[S[j]]=1;
				
			}
		}
	}


	if (max==1)
	{
		cout<<1<<" "<<N<<endl;
		return 0;
	}
		
	
	
	cout<<max-1<<" "<<num[maxp]<<endl;
	
	return 0;
}

