/*��ݡ���������memset��Ȼ�ܸ��Ҵ���ʱ�ˡ���������
*/#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 200010
using namespace std;
int dpm[N],dpn[N];
int a,b[N];
int main()
{
    int m,n,i,j;
    while(scanf("%d%d",&m,&n)!=EOF){
        //memset(dpm,0,sizeof(dpm));
        for(i=2;i<=m+1;i++){
            //memset(dpn,0,sizeof(dpn));
            for(j=2;j<=n+1;j++){//��ÿһ����dp��ȡ���ֵ
                scanf("%d",&a);
                dpn[j]=max(dpn[j-2]+a,dpn[j-1]);
            }
            dpm[i]=max(dpm[i-2]+dpn[n+1],dpm[i-1]);//��ÿһ����dp��ÿһ�е�ֵΪ���������е�dp�������ȡ���ֵ
        }
        printf("%d\n",dpm[m+1]);
    }
    return 0;
}
