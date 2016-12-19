#include <bits/stdc++.h>
#define eps 1e-6
#define MAX 200007
#define ll long long
using namespace std;
int magic,n,m,ob,a[MAX],nex[MAX],nexb[MAX],step[MAX],block[MAX];
void init(){
    magic=sqrt(n);
    int u;
    for(int i=1;i<=n;i++){
        u=i/magic;
        block[i]=u;
    }
    for(int i=n;i>=1;i--){//����dp����ÿ�������Ĳ�������һ�����λ��
        if(nex[i]>n){//��ʼ��
            step[i]=1;
        }
        else if(block[i]==block[nex[i]]){
            step[i]=step[nex[i]]+1;
            nexb[i]=nexb[nex[i]];
        }
        else{
            step[i]=1;
            nexb[i]=nex[i];
        }
    }
}
int query(int x){
    int sum=0;
    for(;;){
        sum+=step[x];
        //printf("%d\n",sum);
        if(!nexb[x]){//�����һ����0�򱻵���
            break;
        }
        x=nexb[x];
    }
    return sum;
}
int main()
{
    int x,y;
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    memset(nex,0,sizeof(nex));
    memset(nexb,0,sizeof(nexb));
    memset(block,0,sizeof(block));
    memset(step,0,sizeof(step));
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        nex[i]=i+a[i];
    }
    init();
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&ob);
        if(ob==1){
            scanf("%d",&x);
            printf("%d\n",query(x+1));
        }
        else{
            scanf("%d%d",&x,&y);
            x++;
            a[x]=y;
            nex[x]=x+a[x];
            int num=0;
            for(int j=x;num++<=x%magic;j--){//ÿ�θ���Ҫ���¸��µ�ǰ�飬��Ϊÿ�����Ӱ�쵱ǰ��ǰ���ֵ
                if(block[j]==block[nex[j]]){
                    step[j]=step[nex[j]]+1;
                    nexb[j]=nexb[nex[j]];
                }
                else{
                    step[j]=1;
                    nexb[j]=nex[j];
                }
            }
        }
    }
    return 0;
}
