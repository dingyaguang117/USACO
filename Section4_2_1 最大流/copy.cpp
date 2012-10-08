/*
ID:dingyag1
LANG:C++
TASK:ditch
*/

#include <stdio.h>
#include <string.h>
#include <iostream>  
using namespace std;  
#define MAXN 205  
#define INF 2110000000  
#define MIN(x,y) (x<y?x:y)  
int map[MAXN][MAXN];  
int max_flow(int num,int map[][MAXN],int source,int sink)//参数含义：结点数量 网络 源点 汇点  
{  
    int my_queue[MAXN],queue_first,queue_end;//数组做队列 实现BFS搜索路径   
    int pre[MAXN],min_flow[MAXN];//记录结点的父节点 当前路径中最小的一段的值，也即限制值  
    int flow[MAXN][MAXN];//记录当前网络中的流  
    int ans=0;//最终结果  
    memset(flow,0,sizeof(flow));  
    while(1)//一直循环，直到不存在增广路径  
    {  
        queue_first=0;//初始化队列  
        queue_end=0;  
        my_queue[queue_end++]=source;  
        memset(pre,-1,sizeof(pre));  
        min_flow[source]=INF;  
        pre[source]=-2;//源点的父节点需特殊标示  
        while(queue_first<queue_end)//BFS寻找增广路径  
        {  
            int temp=my_queue[queue_first++];//出队列  
            for(int i=0;i<num;i++)//由结点temp往外扩展  
            {  
                if(pre[i]==-1&&flow[temp][i]<map[temp][i])//当结点i还未被探索到，并且还有可用流量  
                {     
                    my_queue[queue_end++]=i;//加入队列  
                    pre[i]=temp;//标示父节点  
                    min_flow[i]=MIN(min_flow[temp],(map[temp][i]-flow[temp][i]));//求得min_flow  
                }  
            }  
            if(pre[sink]!=-1)//sink的父节点不为初始值，说明BFS已经找到了一条路径  
            {  
                int k=sink;  
                while(pre[k]>=0)  
                {  
                    flow[pre[k]][k]+=min_flow[sink];//将新的流量加入flow  
                    flow[k][pre[k]]=-flow[pre[k]][k];  
                    k=pre[k];  
                }  
                break;  
            }  
        }  
        if(pre[sink]==-1) return ans;//不存在增广路径，返回  
        else ans+=min_flow[sink];  
    }     
}  
int main()  
{  
	freopen("ditch.in","r",stdin);
	freopen("ditch.out","w",stdout);
    int m,n,i,j;  
    while(cin>>n>>m)  
    {  
        int a,b,cost;  
        memset(map,0,sizeof(map));  
        for(int i=0;i<n;i++)  
        {  
            cin>>a>>b>>cost;  
            map[a-1][b-1]+=cost;  
        }  
        cout<<max_flow(m,map,0,m-1)<<endl;  
    }
    
    
	for (i=0;i<m;++i)
	{
		for (j=0;j<m;++j)
		{
			printf("%12d",map[i][j]);
		
		}
		cout<<endl;
	}
    return 0;  
}  