/*
ID:dingyag1
LANG:C++
TASK:maze1
*/



#include <iostream>
#include <queue>
#include <set>
#include <stdio.h>
using namespace std;
 
class gezi
{
public:
    int y,x,num;
    gezi(int a=0,int b=0,int c=0):y(a),x(b),num(c){}
};
 
char maze[210][210]={0};
bool steped[210][210]={0};
int w,h;
int start[2][2]={0};
queue<gezi> q1,q2;
 
bool pass(int y,int x,int di);
 
int main() {
	freopen("maze1.in","r",stdin);
	freopen("maze1.out","w",stdout);
    int i,j;
    bool bq1=0,bq2=0;
 
    cin>>w>>h;
     
    getchar();
    for(i=0;i<2*h+1;++i)
    {
        for(j=0;j<2*w+1;++j)
        {
            maze[i][j]=getchar();
        }
        getchar();
    }
 
    for(i=0;i<2*h+1;++i)
    {
        for(j=0;j<2*w+1;++j)
            steped[i][j]=0;
         
    }
//确定出口位置
    j=0;
    for(i=1;i<2*h;i+=2)
    {
        if(maze[i][0]==' ')
        {
            start[j][0]=i;
            start[j++][1]=1;
        }
         
        if(maze[i][2*w]==' ')
        {
            start[j][0]=i;
            start[j++][1]=2*w-1;
        }
    }
    for(i=1;i<2*w;i+=2)
        {
            if(maze[0][i]==' ')
            {
                start[j][0]=1;
                start[j++][1]=i;
            }
             
            if(maze[2*h][i]==' ')
            {
                start[j][0]=2*h-1;
                start[j++][1]=i;
            }
        }
 
        q1.push(gezi(start[0][0],start[0][1],1));
        q2.push(gezi(start[1][0],start[1][1],1));
        steped[start[0][0]][start[0][1]]=1;
        steped[start[1][0]][start[1][1]]=1;
 
         
        for(i=1;!(bq1&&bq2);++i)
        {
            if(!bq1)
            {
                gezi a=q1.front();
                while(a.num==i)
                {
                     
                    for(j=0;j<4;++j)
                    {
                        if(pass(a.y,a.x,j))
                        {
                             
                            switch(j)
                            {
                            case 0:
                                if(!steped[a.y-2][a.x]){
                                q1.push(gezi(a.y-2,a.x,i+1));steped[a.y-2][a.x]=1;}break;
                            case 1:
                                if(!steped[a.y+2][a.x]){
                                q1.push(gezi(a.y+2,a.x,i+1));steped[a.y+2][a.x]=1;}break;
                            case 2:
                                if(!steped[a.y][a.x-2]){
                                q1.push(gezi(a.y,a.x-2,i+1));steped[a.y][a.x-2]=1;}break;
                            case 3:
                                if(!steped[a.y][a.x+2]){
                                q1.push(gezi(a.y,a.x+2,i+1));steped[a.y][a.x+2]=1;}break;
                            }
 
                        }
                    }
                    q1.pop();
                    if(q1.empty())
                    {
                        bq1=1;
                        break;
                    }
                    a=q1.front();
                }
            }
            if(!bq2)
            {   
                gezi a=q2.front();
                while(a.num==i)
                {
                 
                    for(j=0;j<4;++j)
                    {
                        if(pass(a.y,a.x,j))
                        {
 
                            switch(j)
                            {
                            case 0:
                                if(!steped[a.y-2][a.x]){
                                q2.push(gezi(a.y-2,a.x,i+1));steped[a.y-2][a.x]=1;}break;
                            case 1:
                                if(!steped[a.y+2][a.x]){
                                q2.push(gezi(a.y+2,a.x,i+1));steped[a.y+2][a.x]=1;}break;
                            case 2:
                                if(!steped[a.y][a.x-2]){
                                q2.push(gezi(a.y,a.x-2,i+1));steped[a.y][a.x-2]=1;}break;
                            case 3:
                                if(!steped[a.y][a.x+2]){
                                q2.push(gezi(a.y,a.x+2,i+1));steped[a.y][a.x+2]=1;}break;
                            }
 
                        }
                    }
                    q2.pop();
                    if(q2.empty())
                    {
                        bq2=1;
                        break;
                    }
                    a=q2.front();
                }
            }
        }
        cout<<i-1<<endl;
 
 
}
 
 
bool pass(int y,int x,int di) //x: lie y: hang
{
 
switch(di)
{
case 0: //up
if(y-2>0&&maze[y-1][x]!='-')
return 1;
else return 0;
 
case 1:
if(y+2<2*h&&maze[y+1][x]!='-')
return 1;
else return 0;
 
case 2: //left
if(x-2>0&&maze[y][x-1]!='|')
return 1;
else return 0;
 
case 3:
if(x+2<2*w&&maze[y][x+1]!='|')
return 1;
else return 0;
 
default:
return 0;
}
}