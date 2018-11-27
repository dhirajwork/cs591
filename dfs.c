#include<stdio.h>
static int visited[10];
int g[10][10],n;
void DFS(int);
void main()
{
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
            scanf("%d",&g[i][j]);
    }
    DFS(0);

}
void DFS(int k){
int u=k;
int i;
visited[u]=1;
printf(" %d \n",u);
for (i=0 ;i<n;i++)
{
    if(visited[i]==0 and g[u][i]==1){
        DFS(i);
    }
}
}
