/*̰�Ĳ�������*/
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct d{
    int day;
    int score;
}dp[1010];
bool com(d i,d j){//��֤����ֵ���ķ���ǰ��
    if(i.score==j.score){
        return i.day<j.day;
    }
    else return i.score>j.score;
}
int main()
{
    int t,n,i,j,sum,s;
    while(scanf("%d",&t)!=EOF){
        while(t--){
            memset(dp,0,sizeof(dp));
            sum=0;
            s=0;
            scanf("%d",&n);
            for(i=1;i<=n;i++){
                scanf("%d",&dp[i].day);
            }
            for(i=1;i<=n;i++){
                scanf("%d",&dp[i].score);
                sum+=dp[i].score;
            }
            sort(dp+1,dp+n+1,com);
            int p[1010];
            memset(p,0,sizeof(p));
            for(i=1;i<=n;i++){//�ӷ���ֵ���Ŀ�ʼ����������������ʹ��������
                for(j=dp[i].day;j>0;j--){
                    if(p[j]==0){
                        p[j]=1;
                        //printf("%d ",j);
                        break;
                    }
                }
                if(j==0){
                    s+=dp[i].score;
                }
            }
            printf("%d\n",s);
        }
    }
    return 0;
}


