/*
1.num��main������������������һ�顣��
2.�߽粻�ô����߽紦����֮���Ǽ��ٵ��·����������ࡣ��
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int a[60][60];
int vis[60][60];
int area,num=0,n,m;
void dfs(int i,int j){
    if(vis[i][j]!=0){
        return;
    }
    vis[i][j]=1;
    area++;
    if((a[i][j]&1)==0){
        dfs(i,j-1);
    }
    if((a[i][j]&2)==0){
        dfs(i-1,j);
    }
    if((a[i][j]&4)==0){
        dfs(i,j+1);
    }
    if((a[i][j]&8)==0){
        dfs(i+1,j);
    }
}
int main()
{
    int i,j;
    scanf("%d%d",&m,&n);
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            //printf("%d",a[i][j]);
        }
    }
    memset(vis,0,sizeof(vis));
    int maxarea=-1;
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(vis[i][j]==0){
                //printf("%d %d",i,j);
                ++num;
                area=0;
                dfs(i,j);
                maxarea=max(area,maxarea);
            }
        }
    }
    printf("%d\n%d\n",num,maxarea);
}
