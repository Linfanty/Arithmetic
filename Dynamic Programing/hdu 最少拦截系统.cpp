#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 10000000
using namespace std;
int main()
{
    int n,i,j;
    int num;
    int dp[100010];
    while(scanf("%d",&n)!=EOF){
        int k=1,m=1;
        for(i=1;i<=n;i++){
            dp[i]=MAX;
        }
        for(i=1;i<=n;i++){
            scanf("%d",&num);
            int p=0;
            for(j=1;j<=k;j++){
                    //printf("%d:%d",num,dp[j]);
                if(num<dp[j]){//��j���ǵ������е���Сֵ����
                    dp[j]=num;
                    p=1;
                    break;
                }
            }
            if(p==0){
                k++;//���½����µķǵ�������
                dp[++m]=num;
                //printf("%d:%d ",k,dp[m]);
            }
            /*for(j=1;j<=k;j++){
                printf("%d ",dp[j]);
            }
            printf("\n");*/
        }
        printf("%d\n",k);
    }
    return 0;
}
