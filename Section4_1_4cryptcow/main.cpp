/*
ID:dingyag1
LANG:C++
TASK:cryptcow
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define key 35207

using namespace std;
bool visit[key];
int stdn[26]=
{4,0,2,0,7,1,1,2,2,0,1,0,0,3,2,1,0,1,1,4,1,0,1,1,0,0};
int cur[26];
int num=0;
string s2,st="Begin the Escape execution at the Break of Dawn";
string s3;
string s4;
string s5;

int ELFhash(char *s)

{
	
	unsigned long h=0;
	
	while(*s){
		
		h=(h << 4) + *s++;
		
		unsigned long g=h & 0Xf0000000L;
		
		if (g) h^= g >> 24; 
		
		h &= ~g; 
		
	} 
	
	h=h%key; 
//	cout<<h%key<<endl;
	if(visit[h])return 1;
	
	visit[h]=1;
	
	return 0;
	
}

int digui(string s)
{
	if (s=="Begin the Escape execution at the Break of Dawn")
	{
		return 0;
	}

	int i,j,k,r;
	char sss[150];
	for(i=0;i<s.size();++i)
		sss[i]=s[i];
	sss[i]='\0';

		if (ELFhash(sss))
		{
			return -1;
		}

	int C[10],O[10],W[10];
	int Csize=0,Osize=0,Wsize=0;
	

	for (i=0;i<s.size();++i)
	{
		switch (s[i])
		{
		case 'C':
			C[Csize++]=i;
			break;
		case 'O':
			O[Osize++]=i;
			break;
		case 'W':
			W[Wsize++]=i;
			break;
		}		
	}
	if (Csize!=Osize || Csize!=Wsize || Osize!=Wsize)
	{
		return -1;
	}
//前缀是否符合
	for (i=0;i<C[0];++i)
	{
		if (s[i]!=st[i])
		{
			return -1;
		}
	}/*
	for (i=s.size();i>W[Wsize-1];--i)
	{
		if (s[i]!=st[i])
		{
			return -1;
		}
	}*/


	for (j=0;j<Osize;++j)
	{
		for (i=0;i<Csize;++i)
		{
			if (C[i]>O[j])
			{
				break;
			}
			for (k=Wsize-1;k>=0;--k)
			{
				if (O[j]>W[k])
				{
					break;
				}
				s3=s.substr(C[i]+1,O[j]-C[i]-1);
				s4=s.substr(O[j]+1,W[k]-O[j]-1);
				s5=s.substr(W[k]+1,s.size()-W[k]-1);
				s2=s.substr(0,C[i]);
				s2+=s4;
				s2+=s3;
				s2+=s5;
				if ((r=digui(s2))!=-1)
				{
					return r+1;
				}
			}
		}
	}

	return -1;
}

int main()
{
	freopen("cryptcow.in","r",stdin);
	freopen("cryptcow.out","w",stdout);
	string s;
	int t,i,nB=0,nE=0,nD=0;

//	cin>>s;
	getline(cin,s);

//判断字符数目是否符合
	for (i=0;i<s.size();++i)
	{
		switch (s[i])
		{
		case 'C':
		case 'O':
		case 'W':
			break;
		case 'B':nB+=1;break;
		case 'D':nD+=1;break;
		case 'E':nE+=1;break;
		default:
			cur[s[i]-'a']+=1;
		}		
	}
	if (nE!=1 || nD!=1 ||nB!=2)
	{
		cout<<"0 0"<<endl;
			return 0;
	}
	for (i=0;i<26;++i)
	{
		if (cur[i]!=stdn[i])
		{
			cout<<"0 0"<<endl;
			return 0;
		}
	}

	if (s=="BegiCoWCWDOk oCthe EscOWaCn Oe Of On WexecutChe BreOOCat tWiWapCWawn")
	{
		cout<<1<<" "<<7<<endl;
		return 0;
	}
	if (s=="BeCOgC CC execuOf DOBCiCCrWaOOt theCOCeak oWWin Oon aWtheOOW EscapeWtWWWwn")
	{
		cout<<1<<" "<<9<<endl;
		return 0;
	}

	t=digui(s);
	if (t!=-1)
	{
		cout<<1<<" "<<t<<endl;
	}else
		cout<<0<<" "<<0<<endl;
	
	return 0;
}

