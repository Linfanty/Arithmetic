#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 100000000
using namespace std;
int dp[110][110];
int main()
{
    //freopen("in.in","r",stdin);
    int n,m,k,s;
    int i,j,l;
    int a[110],b[110];
    while(scanf("%d%d%d%d",&n,&m,&k,&s)!=EOF){
        for(i=1;i<=k;i++){
            scanf("%d%d",&a[i],&b[i]);
        }
        int num=0;
        memset(dp,0,sizeof(dp));
        for(i=1;i<=k;i++){
            for(j=b[i];j<=m;j++){
                for(l=1;l<=s;l++){//��������
                    dp[j][l]=max(dp[j][l],dp[j-b[i]][l-1]+a[i]);//��ÿ�����Ͷȣ��ܹ����׶ν��������ֵȡ���ж�
                 }
             }
        }
        int flag=0;
        int ans=INF;
        for(i=0;i<=m;i++){
            for(j=1;j<=s;j++){
                if(dp[i][j]>=n){
                    ans=min(ans,i);//ÿ��ȡ�ﵽ����ֵ�Ժ��
                    flag=1;
                }
            }
        }
        if(flag==0) printf("-1\n");
        else printf("%d\n",m-ans);
    }
    return 0;
}
