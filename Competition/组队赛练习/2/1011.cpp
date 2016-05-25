/*
��״���飬�������
wa1:sum[]û����ա������Լ�hӦ����long long
*/
#include <bits/stdc++.h>
#define N 100007
using namespace std;
long long sum[100007],c[100007];
int lowbit(int x){
    return x&(-x);
}
void update(int bit,int a){
    while(bit<=N){
        c[bit]+=a;
        bit+=lowbit(bit);
    }
}
long long getsum(int x){
    long long sum=0;
    while(x>0){
        sum+=c[x];
        x-=lowbit(x);
    }
    return sum;
}
int main()
{
    int n,m,l,r,d,k,x;
    long long ans,h;
    while(scanf("%d%d",&n,&m)!=EOF&&n!=0){
        memset(c,0,sizeof(c));
        memset(sum,0,sizeof(sum));
        ans=0;
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&l,&r,&d);
            update(l,d);//�������Ϊ�ݳ�
            update(r+1,-d);
        }
        for(int i=n;i>0;i--){//Ԥ�����ÿһ���㵽�յ�������˺�ֵ
            sum[i]=sum[i+1]+getsum(i);
        }
        scanf("%d",&k);
        ans=0;
        for(int i=0;i<k;i++){
            scanf("%I64d%d",&h,&x);
            if(h>sum[x]){
                ans++;
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
