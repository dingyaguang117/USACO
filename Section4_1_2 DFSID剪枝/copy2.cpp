/*
ID: dingyag1
PROG: fence8
LANG: C++
*/
#include <stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
int n,nr,sumb,ans;
int b[51],sum[1024],r[1024];
int cmp(const void *s,const void *t)
{
    int i=*(int *)s,j=*(int *)t;
    return i-j;
}
bool dfsid(int left,int x,int m)
{
    int ni,nleft;
    if (x==0) return true;
    for (int i=m;i<=n;i++)
        if (b[i]>=r[x])
        {
            b[i]-=r[x];
            if (b[i]<r[1])
            {
                nleft=left+b[i];
                if (nleft+sum[ans]>sumb)
                {
                    b[i]+=r[x]; continue;
                }
            }
            else nleft=left;
            if (r[x]==r[x-1]) ni=i;
            else ni=1;
            if (dfsid(nleft,x-1,ni)) return true;
            b[i]+=r[x];
        }
    return false;
}
int main()
{
    freopen("fence8.in","r",stdin);
    freopen("fence8.out","w",stdout);
    scanf("%d",&n);
    sumb=0;
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
        sumb+=b[i];
    }
    qsort(b+1,n,sizeof(int),cmp);
    scanf("%d",&nr);
    for (int i=1;i<=nr;i++) scanf("%d",&r[i]);
    qsort(r+1,nr,sizeof(int),cmp);
    memset(sum,0,sizeof(sum));
    ans=nr;
    for (int i=1;i<=nr;i++)
    {
        sum[i]+=sum[i-1]+r[i];
        if (sum[i]>sumb)
        {
            ans=i-1; break;
        }
    }
    while (!dfsid(0,ans,1)) ans--;
    printf("%d\n",ans);
    return 0;
}