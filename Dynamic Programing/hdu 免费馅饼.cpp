/*wa�㣺ԭѭ���У�
    if(j==0){
        dp[i][0]=max(dp[i-1][0],dp[i-1][1])+num[i][0];
    }
    if(j==10){
        dp[i][10]=max(dp[i-1][10],dp[i-1][9])+num[i][10];
    }
    else{
        dp[i][j]=maxm(dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1])+num[i][j];//ÿ��״̬��ֻ�п���Ϊ��һ���ԭ����������������������������
    }
    ����ΪelseΪ�ڶ������������j==0�ظ�����һ��
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int num[100010][11];
int dp[100010][11];
int maxm(int a,int b,int c){
    if(a>=max(b,c))return a;
    if(b>=max(a,c))return b;
    if(c>=max(a,b))return c;
}
int main()
{
    int n,t,a,b,ans;
    int i,j;
    while(scanf("%d",&n)!=EOF&&n!=0){
        memset(num,0,sizeof(num));
        memset(dp,0,sizeof(dp));
        t=0;
        for(i=1;i<=n;i++){
            scanf("%d%d",&a,&b);
            num[b][a]++;
            t=max(t,b);
            //printf("%d:%d\n",t,num[b][a]);
        }
        dp[1][5]=num[1][5];
        dp[1][6]=num[1][6];
        dp[1][4]=num[1][4];
        for(i=2;i<=t;i++){
            for(j=0;j<=10;j++){
                if(j==0){
                    dp[i][0]=max(dp[i-1][0],dp[i-1][1])+num[i][0];
                }
                else if(j==10){
                    dp[i][10]=max(dp[i-1][10],dp[i-1][9])+num[i][10];
                }
                else{
                    dp[i][j]=maxm(dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1])+num[i][j];//ÿ��״̬��ֻ�п���Ϊ��һ���ԭ����������������������������
                }
                //printf("%d %d:%d    ",i,j,dp[i][j]);
            }
            //printf("\n");
        }
        ans=0;
        for(j=0;j<=10;j++){
            ans=max(ans,dp[t][j]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
