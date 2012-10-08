/*
ID:dingyag1
LANG:C++
TASK:lgame
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int value[26]=
{
	2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7
};

int stdd[26],dic[10000][26],dic_value[10000];
int dic_len=0,max_one=0;
int R_one[100],R_one_len;


bool can2(int i)
{
	int k;
	for (k=0;k<26;++k)
	{
		if (dic[i][k]>stdd[k])
		{
			return false;
		}
	}
	return true;
}


bool can(const string &b)
{
	int i,tmp[26]={0},val=0;
	for (i=0;i<b.size();++i)
	{
		tmp[b[i]-'a']+=1;
	}
	for (i=0;i<26;++i)
	{
		if(tmp[i]>stdd[i]) return false;
	}
	//计算 单词的信息
	for (i=0;i<26;++i)
	{
		dic[dic_len][i]=tmp[i];
		val+=value[i]*tmp[i];
	}

	dic_value[dic_len++]=val;
	if (val>max_one)
	{
		max_one=val;
		R_one[0]=dic_len-1;
		R_one_len=1;
	}else if (val==max_one)
	{
		R_one[R_one_len]=dic_len-1;
		R_one_len++;
	}
	return true;
}

int main()
{
	freopen("lgame.in","r",stdin);
	freopen("lgame.out","w",stdout);
	string s,sb;
	ifstream ifs;
	vector<string> dic_s;
	int R[200][2];
	int R_len=0;
	int i,k,j,max=0;
	cin>>s;
	for (i=0;i<s.size();++i)
	{
		stdd[s[i]-'a']+=1;
	}

	ifs.open("lgame.dict");
	
	
	while (ifs>>sb)
	{
		if (sb==".")
		{
			break;
		}
		if (can(sb)) dic_s.push_back(sb);
	}
	ifs.close();

	//2个单词寻找
	for (i=0;i<dic_len;++i)
	{
		for (j=0;j<26;++j)
		{
			stdd[j]-=dic[i][j];
		}
		for (j=i;j<dic_len;++j)
		{
			if (can2(j))
			{
				int t=dic_value[i]+dic_value[j];
				if (t>max)
				{
					max=t;
					R_len=1;
					R[0][0]=i;R[0][1]=j;
				}
				else if (t==max)
				{
					R[R_len][0]=i;R[R_len][1]=j;
					R_len++;
				}
			}
		}
		for (j=0;j<26;++j)
		{
			stdd[j]+=dic[i][j];
		}
	}
	
	if (max<max_one)
	{
		cout<<max_one<<endl;
		for (i=0;i<R_one_len;++i)
		{
			cout<<dic_s[R_one[i]]<<endl;
		}
	}else
	if (max==max_one)
	{
			cout<<max_one<<endl;
			for (i=0;i<R_len;++i)
			{
				cout<<dic_s[R[i][0]]<<" "<<dic_s[R[i][1]]<<endl;
			}
			for (i=0;i<R_one_len;++i)
			{
				cout<<dic_s[R_one[i]]<<endl;
			}
	}else
	{
		cout<<max<<endl;
		for (i=0;i<R_len;++i)
		{
			cout<<dic_s[R[i][0]]<<" "<<dic_s[R[i][1]]<<endl;
		}
	}

	return 0;
}

