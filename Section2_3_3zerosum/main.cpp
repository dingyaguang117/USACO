/*
ID:dingyag1
LANG:C++
TASK:zerosum
*/

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stack>
using namespace std;

int N;
int op[9];		//0 = ' ' ,1 = '+' ,2 = '-'



int main()
{
	freopen("zerosum.in","r",stdin);
	freopen("zerosum.out","w",stdout);
	unsigned short enum3=0,t;
	int i,j;
	stack<int> numstack;
	int oper;
	cin>>N;
	for(enum3=0;enum3<pow(3,N-1)+0.1;++enum3)
	{
		t=enum3;
		for (j=0;j<8;++j)
		{
			op[j]=0;
		}
		op[N-1]=1; //+
		j=N-2;
		while (t!=0)	//转换状态ID 到具体的 各个位
		{
			op[j--]=t%3;
			t/=3;
		}
/*		for (i=0;i<9;++i)
		{
			cout<<op[i];
		}
		cout<<endl;*/
		//begin cacl
		numstack.push(1);
		oper=op[0];
		
//		if(op[0]==1&&op[1]==2&&op[2]==1&&op[3]==2&&op[4]==2&&op[5]==1)
//			cout<<"  "<<endl;

		for (i=2;i<=N;++i)
		{
			if (oper==0)	// qianmian is ' ',can know stacksize == 1
			{
				int tmp=numstack.top();
				numstack.pop();
				numstack.push(i+tmp*10);
				oper=op[i-1];
				continue;
			}
			if (op[i-1]==0) // ' '
			{
				if (numstack.size()>1)
				{
					int tmp=numstack.top();
					numstack.pop();
					numstack.push(tmp*10+i);
					continue;
				}
				else
				{
					numstack.push(i);
				}
			}
			else		// +
			{
				if (oper==1){
				if (numstack.size()>1) // firstlink then +
				{
					int tmp=numstack.top();
					numstack.pop();
					int tmp2=numstack.top();
					numstack.pop();
					numstack.push((tmp*10+i)+tmp2);
					oper=op[i-1];
					continue;
				}
				else
				{
					int tmp=numstack.top();
					numstack.pop();
					numstack.push(i+tmp);
					oper=op[i-1];
				}}
				else
				if (oper==2)		// -
				{
				if (numstack.size()>1) // firstlink then -
				{
					int tmp=numstack.top();
					numstack.pop();
					int tmp2=numstack.top();
					numstack.pop();
					numstack.push(tmp2-(tmp*10+i));
					oper=op[i-1];
					continue;
				}
				else
				{
					int tmp=numstack.top();
					numstack.pop();
					numstack.push(tmp-i);
					oper=op[i-1];
				}
				}
			

			}
		}
		if (numstack.top()==0)
		{
			int i;
			cout<<1;
			for (i=2;i<=N;++i)
			{
				if (op[i-2]==0)
				{
					cout<<" ";
				}
				else
					if (op[i-2]==1)
					{
						cout<<"+";
					}
				else cout<<"-";
				cout<<i;
			}
			cout<<endl;
		}
		while(!numstack.empty())
		numstack.pop();
		//end	cacl
	}


	return 0;
}

