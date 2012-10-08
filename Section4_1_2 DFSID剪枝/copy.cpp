#include<iostream>
#include <fstream>
#include <algorithm> 
using namespace std;
ifstream fin("fence8.in");
ofstream fout("fence8.out");
int nbd,nrail,best;
int board[51];
int rail[1024];
int rem[51];
int sumlen[1024];
long sum=0;
long maywaste,waste;
 
void DFS(int depth,int index)      
{
	int i;
     if(depth == 0)
     {
         for(i=index; i<nbd; ++i)
             if (rem[i]>=rail[0])
             {
                 fout << best+1 << endl;
                 fout.close();
                 exit(0);
             }
         return;
     }
     for(i=index; i<nbd; ++i)
         if(rem[i]>=rail[depth])
         {
             long oldwaste=waste;
             rem[i]-=rail[depth];
             if (rem[i]<rail[0] && waste+rem[i]>maywaste)    //剪枝方法4 
             {
                 rem[i]+=rail[depth];
                 continue;
             }
             if (rem[i]<rail[0]) waste+=rem[i];
             if(rail[depth-1] == rail[depth]) DFS(depth-1,i);      //剪枝方法3 
             else DFS(depth-1,0);
             rem[i]+=rail[depth];
             waste=oldwaste;
         }
}
void DFSID(int nr)
{int i;
      for(i=nr-1;i>=0;--i){        //木料从大到小 
         waste=0;
         maywaste=sum-sumlen[i];    //记录木板的总长比木料总长多的值 
         best=i;
         DFS(i,0);
     }
}
int main()
{
     fin>>nbd;
	 int i;
     for(i=0;i<nbd;i++){
         fin>>board[i];
         sum+=board[i];
         rem[i]=board[i];
     }
     fin>>nrail;
     for(i=0;i<nrail;i++)
         fin>>rail[i];
     fin.close();
 
     sort(board,board+nbd);                            //剪枝方法2的排序 
     sort(rail,rail+nrail);
 
     int temp=0;
     sumlen[0]=rail[0];
     while(temp<nrail && sumlen[temp]<=sum){            //剪枝方法1 
          ++temp;
          sumlen[temp]=sumlen[temp-1]+rail[temp];
     }
     nrail=temp; 
     DFSID(nrail);
     fout<<'0'<<endl;
     return 0;
}