#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    long long p[100010]={-1},l[100010];//������
    long long r,h,ans;
    int t,i;
    while(scanf("%d",&t)!=EOF&&t!=0){
        ans=0;
        int top=0;
        for(i=1;i<=t+1;i++){
            if(i==t+1){
                h=0;
            }//Ҫ���а�����ջ������Ԫ�طų��Ĺ���
            else{
                scanf("%lld",&h);
            }
            if(h>p[top]){
                p[++top]=h;
                l[top]=1;
            }
            else{
                r=0;
                while(h<=p[top]){
                    ans=max(ans,(r+l[top])*p[top]);
                    r+=l[top--];
                }//ÿ�θ��µ���ջ�еĶ�ֵΪ���ұ�ʱ�������������ܴﵽ�����ľ������������ջ
                p[++top]=h;//���¸���ջ��
                l[top]=r+1;//ÿ��ȫ����ջ֮�����ջ�׵����
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
