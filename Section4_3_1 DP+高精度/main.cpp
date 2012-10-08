/*
ID:dingyag1
LANG:C++
TASK:buylow
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


void func_add(vector<int> &sum,vector<int> a,int n)
{
	vector<int>::size_type i;
	for(i=0;i<a.size();i++)
	{
		if(i+n+1>sum.size()) sum.insert(sum.end(),i+n+1-sum.size(),0);
		sum[i+n]+=a[i];
	}
	// cout<<"输出add函数中sum:"<<endl; 
	// print(sum,4);
	
	for(i=0;i<sum.size();i++)
	{
		if(sum[i]>=10000)
		{
			if(i==sum.size()-1) sum.push_back(0);
			sum[i+1]+=sum[i]/10000;
			sum[i]=sum[i]%10000;
		}
	}
	
}

vector<int> & operator +=(vector<int> &a,const vector<int> &b )
{
	func_add(a,b,0);
	return a;
}


void mitoa(int a,char *s,int c)
{  int n,i=0;
char s2[10];

do
{
	s2[i++]=a%c+'0';       
	a=a/c;
}while(a>0);
for(n=0;n<i;n++) s[n]=s2[i-n-1];
s[n]='\0';
}


void print(const vector<int> &sum,int nlog)
{ 
	vector<int>::size_type i;
	string s;
	int tmp;
	bool f=0;
	char ss[10]={0};
	for (i=0;i<sum.size();++i)
	{
		if (sum[i]!=0)
		{
			f=1;
			break;
		}
	}
	if (!f)
	{
		cout<<0;
	}
	else
	{
		//取头 
		mitoa(sum[sum.size()-1],ss,10);
		s+=ss;
		if(sum.size()>1){
			//取中间 
			for(i=sum.size()-2;i>0;i--)
			{
				if(sum[i]<10)
				{
					s+="000";
				}
				else if(sum[i]<100)
				{
					s+="00";
				}
				else if(sum[i]<1000)
				{
					s+="0";
				}
				mitoa(sum[i],ss,10); 
				s+=ss;
			}
			//取尾 
			if(sum[0]<10)
			{
				s+="000";
			}
			else if(sum[0]<100)
			{
				s+="00";
			}
			else if(sum[0]<1000)
			{
				s+="0";
			}
			mitoa(sum[0],ss,10); 
			s+=ss;            }
		
		
		//处理小数点
		tmp=s.size();
		if(nlog==0)
		{
			
		}
		else if(nlog>0)
		{
			s.append(nlog,'0');     
		}
		else if(nlog>-tmp)
		{
			s.insert(tmp+nlog,1,'.');
			i=s.find_last_not_of('0');
			s.erase(i+1,s.size()-i-1);
			if(s[s.size()-1]=='.') s.erase(s.size()-1,1);
		}
		else
		{
			s.insert((string::size_type)0,-(tmp+nlog),'0');
			s.insert((string::size_type)0,"0.");
			i=s.find_last_not_of('0');
			s.erase(i+1,s.size()-i-1);
			if(s[s.size()-1]=='.') s.erase(s.size()-1,1);
		}
		//删除前面的0
		i=s.find_first_not_of('0');
		s.erase(0,i); 
		cout<<""<<s;
		//  cin>>s; 
	}
}

int main()
{
	freopen("buylow.in","r",stdin);
	freopen("buylow.out","w",stdout);
	
	int  N,S[5003],dp[5003]={0};
	int i,j,max=1,maxp;
	vector<int> num[5003];


	cin>>N;	

	for (i=1;i<=N;++i)
	{
		cin>>S[i];
		dp[i]=1;		//初始化dp为1
		num[i].push_back(1);

	}
	///末尾+0 方便统计
	N++;
	S[N]=0;num[N].push_back(1);dp[N]=1;
	
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
		
	
	
	cout<<max-1<<" ";
	print(num[maxp],0);
	cout<<endl;
	return 0;
}

