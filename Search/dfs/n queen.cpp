#include<cstdio>
int point;
int sum;
int que(int row,int l,int r){//
    int pos=point&~(row|l|r);//posΪ������ʺ�ı�ǣ�1Ϊ���0Ϊ���ɣ�
    int p;
    if(row!=point){//��rowΪpointʱ���޷���ʺ�
        while(pos!=0){
            p=pos&-pos;//p��ʾ��ǰ״̬�»ʺ����λ��
            pos-=p;//����pos��һ��������ʺ��λ��
            que(row+p,(l+p)<<1,(r+p)>>1);
        }
    }
    else sum++;
}
int main(){
    int n,i;
    int queen[20];
    for(i=1;i<=12;i++){
        sum=0;
        point=(1<<i)-1;
        que(0,0,0);
        queen[i]=sum;
    }
    while(scanf("%d",&n)!=EOF&&n!=0){
        printf("%d\n",queen[n]);
    }
    return 0;
}
