#include <bits/stdc++.h>
#define N 509
using namespace std;
string a,b,c;
int len;
int vis[N][N];
bool dfs(int x,int y,int z){
    if(z==len+1){
        return true;
    }
    if(z!=len+1&&a[x]==c[z]&&!vis[x][y]){//Ӧ���Ϊ��ά��������Ϊһά�������ֻ��ݵ���ǰ����������һЩ���û�л�Ը����wa
        vis[x][y]=1;
        if(dfs(x+1,y,z+1)){
            return true;
        }
        else{
            vis[x][y]=0;
        }
    }
    if(z!=len+1&&b[y]==c[z]&&!vis[x][y]){
        vis[x][y]=1;
        if(dfs(x,y+1,z+1)){
            return true;
        }
    }
    return false;
}
int main()
{
    int n,i,num;
    while(scanf("%d",&n)!=EOF){
        num=0;
        while(++num<=n){
            cin>>a>>b>>c;
            memset(vis,0,sizeof(vis));
            printf("Data set %d: ",num);
            len=c.size();
            if(len!=a.size()+b.size()){
                printf("no\n");
            }
            else if(dfs(0,0,0)){
                printf("yes\n");
            }
            else{
                printf("no\n");
            }
        }
    }
    return 0;
}
