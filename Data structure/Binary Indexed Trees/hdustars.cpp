#include<cstdio>
#include<cstring>
#define N 32010
int bit[N];
int lowbit(int x){
    return x&(-x);
}
void update(int x,int a){
    while(x<=N){
        bit[x]+=a;
        x+=lowbit(x);
    }
}
int getsum(int x){
    int sum;
    sum=0;
    while(x>0){
        sum+=bit[x];
        x-=lowbit(x);
    }
    return sum;
}
int main()
{
    int t,i,x,y;
    int level[N];
    while(scanf("%d",&t)!=EOF){
        memset(level,0,sizeof(level));
        memset(bit,0,sizeof(bit));
        for(i=1;i<=t;i++){
            scanf("%d%d",&x,&y);//��Ϊ���������Ĭ��y��ֵΪ��������ÿ��y�����ӵ�ʱ��x�ض���֮ǰ��y����Ӧ��x���ص��������䷶Χ֮�ڣ���ֱ�Ӽ���Ϳɡ�
            level[getsum(++x)]++;//x==1��ʱ��levelΪ0��bit[x]����Ǻ�����Ϊxʱ��x��ǰ��Ͻ��Χ�ڵ�������
            update(x,1);
        }
        for(i=0;i<t;i++){
           printf("%d\n",level[i]);
        }
    }
    return 0;
}
