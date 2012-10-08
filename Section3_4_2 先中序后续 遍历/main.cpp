/*
ID:dingyag1
LANG:C++
TASK:heritage
*/

#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;
char MS[27],FS[27];		//MSÏÈÐò FS ÖÐÐò  ¸ã´íÁË
struct node
{
	node *L,*R;
	char c;
};


void createtree(node *& tree,int begin1,int end1,int begin2,int end2)
{
		char c;
		int i,j;

		c=MS[begin1];
		tree=(node *)malloc(sizeof(node));
		(tree)->c=c;

		for (i=begin2;i<=end2;++i)
		{
			if (FS[i]==c)
			{
				break;
			}
		}

		if (i==begin2)
		{
			(tree)->L=NULL;
		}else
		{
			createtree((tree)->L,begin1+1,begin1+i-begin2,begin2,i-1);
		}

		if (i==end2)
		{
			(tree)->R=NULL;
		}else
		{
			createtree((tree)->R,begin1+i-begin2+1,end1,i+1,end2);
		}
		

}

void LVtree(node *tree)
{
	if (tree->L!=NULL)
	{
		LVtree(tree->L);
	}
	if (tree->R!=NULL)
	{
		LVtree(tree->R);
	}
	cout<<tree->c;
}

int main()
{
	freopen("heritage.in","r",stdin);
	freopen("heritage.out","w",stdout);
	node *tree;
	int len,begin1,end1,i,j,begin2,end2;

	
	scanf("%s",FS);
	scanf("%s",MS);
	len=strlen(MS);
	begin1=0;end1=len-1;
	begin2=0;end2=len-1;
	createtree(tree,begin1,end1,begin2,end2);

	LVtree(tree);
	cout<<endl;

	
	return 0;
}

