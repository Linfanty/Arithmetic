#include<cstdio>
#include<cstring>
int point,cstr;
int answer,p[250][250];
char a[250],b[250],c[500];
bool judge(int f,int s,int t);
int main(){
    int n,k,ans,t=0;
    while(scanf("%d",&n)!=EOF){
        k=1;//��Ǵ���
        while(k<=n){
            scanf("%s%s%s",a,b,c);
            cstr=strlen(c);
            memset(p,0,sizeof(p));
            ans=0;
            ans=judge(0,0,0);//dfs�Ҷ�Ӧ�ַ���
            printf("Data set %d:",k++);
            if(ans){
                printf(" yes\n");
            }
            else
                printf(" no\n");
        }
    }
}
bool judge(int f,int s,int t){//f��ʾa���鵱ǰ��λ�ã�s��ʾb���鵱ǰ��λ�ã�t��ʾc���鵱ǰ��λ��
    if(t==cstr+1)return true;//���ڱȶԵ����鳤����ԭ����һ��
    if(t!=cstr+1&&a[f]==c[t]&&!p[f][s]){
        p[f][s]=1;
        if(judge(f+1,s,t+1))return true;
        p[f][s]=0;
    }
    if(t!=cstr+1&&b[s]==c[t]&&!p[f][s]){
        p[f][s]=1;
        if(judge(f,s+1,t+1))return true;
    }
    return false;
}
