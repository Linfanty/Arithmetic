/*
���������Ϊ˳�����ӵ�ֵ���������ݷ�Χ����n^2�ķ�Χ֮�ڣ��������
wa�����ز������ݷ�Χ��С�ˣ��ύʱ�����ǸĻ���������= =
*/
#include <cstdio>
#include <cstring>
#define N 10010
int p[N];
int prime[N]={0};
int main()
{
    memset(p,0,sizeof(p));
	p[1]=1;
	int i,j;
	for(i=2;i*i<=N;i++){
		for(j=2;i*j<=N;j++){
			p[i*j]=1;
			//printf("%d %d",i,p[i]);
		}
	}
	int k=1;
	for(i=2;i<=N;i++){
		if(p[i]==0){
			prime[k++]=i;
			//printf("%d ",prime[k-1]);
		}
	}
	int n;
	while(scanf("%d",&n)!=EOF&&n){
		int sum;
		int num=0;
		for(i=1;prime[i]<=n;i++){
			sum=0;
			for(j=i;sum<=n;j++){
                sum+=prime[j];
                //printf("%d ",sum);
				if(sum==n){
					num++;
					continue;
				}
			}
		}
		printf("%d\n",num);
	}
}
