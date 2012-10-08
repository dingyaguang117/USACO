/*
ID:dingyag1
LANG:C++
TASK:beads
*/

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int main()
{
	freopen("beads.in","r",stdin);
	freopen("beads.out","w",stdout);
	int n,i,j,f,pre,most,cur;
	char precolor;
	bool firstw;
	string s;
	cin>>n;
	cin>>s;

	precolor=s[i];
	for (i=0;i<s.size();++i)
	{
		if (s[i]!='w')
		{
			precolor=s[i];
		}
	}
	
	
	//找到第一个颜色不同的点
	for(i=0;i<s.size();++i)
	{
		if (s[i]!=precolor&&s[i]!='w')
		{
			pre=i;
			break;
		}
	}
	if (i==s.size())
	{
		cout<<s.size()<<endl;
		return 0;
	}
	else
		f=pre;	//第一个开始位，也是结束标志
	//
	precolor=s[pre];
	most=0;
	cur=0;
	firstw=1;
	for (i=pre;;++i)
	{
		i%=s.size();
		if (s[i]=='w')
		{
			if (firstw)
			{
				pre=i;
				firstw=0;
			}
			cur+=1;
			continue;
		}
		if (s[i]==precolor)
		{
			cur+=1;
			firstw=1;
			continue;
		}
		else
		{
			precolor=s[i];
			for (j=i;;)
			{
				j%=s.size();
				if (s[j]!=precolor&&s[j]!='w')
				{
					cur+=(j-i+s.size())%s.size();
					break;
				}
				++j;
				j%=s.size();
			}


			if (cur>most)
			{
				if(cur>n)
				most=n;
				else
					most=cur;
			}

			if (i==f)		//结束
			{
				break;
			}
			precolor=s[i];

			if (!firstw)
			{
				i=pre-1;
			}
			else
				i-=1;		//新的开始 i-- ++i后还是当前的地方
			//firstw=0;
			cur=0;
			

			continue;

		}
	}

	cout<<most<<endl;

}