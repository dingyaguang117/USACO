/*
ID:dingyag1
LANG:C++
TASK:rect1
*/

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class Rect
{
public:
int llx,lly,urx,ury,c;
};

vector<Rect> set;

void act(Rect &O,const Rect &S)
{
	Rect tmp;
	tmp.c=O.c;
	if (S.urx<O.llx || S.ury<O.lly || S.llx > O.urx || S.lly > O.ury)
	{
		set.push_back(S);
		return;
	}
	if (S.llx<=O.llx)
	{
		if (S.lly>O.lly)
		{
			if (S.urx<O.urx)
			{
				if (S.ury < O.ury)
				{
					
					tmp.llx=O.llx;
					tmp.lly=O.lly;
					tmp.urx=S.urx;
					tmp.ury=S.lly;
					set.push_back(tmp);
					tmp.llx=O.llx;
					tmp.lly=S.ury;
					tmp.urx=S.urx;
					tmp.ury=O.ury;
					set.push_back(tmp);
					O.llx=S.urx;
					set.push_back(S);
				}
				else
				{
					tmp.llx=O.llx;
					tmp.lly=O.lly;
					tmp.urx=S.urx;
					tmp.ury=S.lly;
					set.push_back(tmp);
					O.llx=S.urx;
					set.push_back(S);
				}
			}
			else
			{
				if (S.ury < O.ury)
				{
					tmp.llx=O.llx;
					tmp.lly=O.lly;
					tmp.urx=O.urx;
					tmp.ury=S.lly;
					set.push_back(tmp);
					O.lly=S.ury;
					set.push_back(S);
				}
				else
				{
					O.ury=S.lly;
					set.push_back(S);
				}

			}
		}
		else	//S.llx<=O.llx S.lly<=O.lly
		{
			if (S.urx<O.urx)
			{
				if (S.ury < O.ury)
				{
					tmp.llx=O.llx;
					tmp.lly=S.ury;
					tmp.urx=S.urx;
					tmp.ury=O.ury;
					set.push_back(tmp);
					O.llx=S.urx;
					set.push_back(S);
				}
				else
				{
					O.llx=S.urx;
					set.push_back(S);
				}
			}
			else
			{
				if (S.ury < O.ury)
				{
					O.lly=S.ury;
					set.push_back(S);
				}
				else
				{
					O.llx=S.llx;
					O.lly=S.lly;
					O.urx=S.urx;
					O.ury=S.ury;
					O.c=S.c;
				}
				
			}

		}
	}
	else	//S.llx>O.llx
	{
		if (S.lly>O.lly)
		{
			if (S.urx<O.urx)
			{
				if (S.ury < O.ury)
				{
					tmp.llx=O.llx;
					tmp.lly=O.lly;
					tmp.urx=S.llx;
					tmp.ury=O.ury;
					set.push_back(tmp);
					tmp.llx=S.urx;
					tmp.lly=O.lly;
					tmp.urx=O.urx;
					tmp.ury=O.ury;
					set.push_back(tmp);
					tmp.llx=S.llx;
					tmp.lly=S.ury;
					tmp.urx=S.urx;
					tmp.ury=O.ury;
					set.push_back(tmp);
					O.llx=S.llx;
					O.lly=O.lly;
					O.urx=S.urx;
					O.ury=S.lly;
					set.push_back(S);
				}
				else
				{
					
				}
			}
			else
			{
				if (S.ury < O.ury)
				{
				}
				else
				{
					
				}
				
			}
		}
		else
		{
			if (S.urx<O.urx)
			{
				if (S.ury < O.ury)
				{
				}
				else
				{
					
				}
			}
			else
			{
				if (S.ury < O.ury)
				{
				}
				else
				{
					
				}
				
			}
			
		}

	}
}

void add(const Rect &rc)
{
	int i;
	int size=set.size();
	for (i=0;i<size;++i)
	{
		act(set[i],rc);
	}
}

int main()
{
	freopen("rect1.in","r",stdin);
	freopen("rect1.out","w",stdout);

	int A,B,N,i,j,K;
	Rect rc;

	cin>>A>>B>>N;
	for (i=0;i<N;++i)
	{
		cin>>rc.llx>>rc.lly>>rc.urx>>rc.ury>>rc.c;
		rc.urx-=1;rc.ury-=1;
		add(rc);
	}

	
	
	
	return 0;
}
