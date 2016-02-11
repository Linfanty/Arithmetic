/*��״�������������
���԰���һ�������뵽��״�����У� ÿ����һ������ ͳ�Ʊ���С�����ĸ�������Ӧ������Ϊ i- getsum( data[i] )������ i Ϊ��ǰ
�Ѿ���������ĸ����� getsum( data[i] ��Ϊ�� data[i] С�����ĸ�����
i- getsum( data[i] ) ���� data[i] ��ĸ����� ������ĸ����������Ҫ��������������ͣ������ڲ���Ĺ����б߲������͡�*/
#include<cstdio>
#include<cstring>
#define N 1010
int bit[N];//����
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
	int sum=0;
	while(x>0){
		sum+=bit[x];
		x-=lowbit(x);
		//printf("%d\n",sum);
	}
	return sum;
}
int main()
{
	int n,i,a[N];
	int ans;
	while(scanf("%d",&n)!=EOF){
		ans=0;
		memset(bit,0,sizeof(bit));
		memset(a,0,sizeof(a));
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			update(a[i],1);//������ʾa[i]����֮�󣬺������������ּ�����Լ�С������ʱ����Ҫ
			ans+=i-getsum(a[i]);
			//printf("%d\n",ans);
		}
		printf("%d\n",ans);
	}
	return 0;
}
