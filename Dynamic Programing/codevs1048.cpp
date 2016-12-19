/*
dp[i][j]��ʾ���䣨i��j������С�ϲ�ֵ��Ȼ������dpö�ٳ��ȣ�������㣬������״̬O(n^3)��
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int main()
{
    int n,dp[109][109],a[109],sum[109],minm;
    while(scanf("%d",&n)!=EOF){
        memset(sum,0,sizeof(sum));
        memset(dp,INF,sizeof(dp));
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            dp[i][i]=0;
            sum[i]=sum[i-1]+a[i];//д����sum[i]+=......
        }
        for(int len=2;len<=n;len++){
            for(int i=1;i<=n-len+1;i++){
                int j=i+len-1;
                for(int k=i;k<j;k++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
                }
            }
        }
        printf("%d\n",dp[1][n]);
    }
}
