
/*
ID:dingyag1
LANG:C++
TASK:palsquare
*/

#include <stdio.h>
#include <iostream>
#include <string>


using namespace std;

bool isPal(string num)
{
	int i;
	bool r=true;
	for(i=0;i<num.size()/2;++i)
	{
		if(num[i]!=num[num.size()-i-1])
		{
			r=false;
			break;
			
		}
	}
	return r;
}

string itoa_baseN(int n,int b)
{
	string num;
	int t;

	while(n/b!=0)
	{
		t=n%b;
		if (t<10)
		{
			num.insert(num.begin(),(unsigned int)1,(char)('0'+n%b));
		}
		else
		{
			num.insert(num.begin(),(unsigned int)1,(char)(t-10+'A'));
		}
		
			n/=b;
	}

	t=n%b;
	if (t<10)
	{
		num.insert(num.begin(),(unsigned int)1,(char)('0'+n%b));
	}
	else
	{
		num.insert(num.begin(),(unsigned int)1,(char)(t-10+'A'));
		}

	return num;
}

int main()
{
	freopen("palsquare.in","r",stdin);
	freopen("palsquare.out","w",stdout);
	int n,i,b;

	cin>>b;
	string s;

	for (i=1;i<301;++i)
	{
		if (isPal(itoa_baseN(i*i,b)))
		{
			cout<<itoa_baseN(i,b)<<" "<<itoa_baseN(i*i,b)<<endl;
		}
	}

	return 0;
}