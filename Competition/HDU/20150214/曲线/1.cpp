//����n<=10000��������߻���ƽ���ϣ����κ������������ǡ���ཻ�����㣬
//���κ�����������߲��ཻ��ͬһ�㣬����Щ������߰�ƽ��ָ�ɵ����������
//F(1)=2
//F(n)=F(n-1)+2(n-1)
//�ݹ�ʵ�֣�
/*
#include<stdio.h>
int fun(int n)
{
	if(n==1) return 2;
	else return fun(n-1)+2*(n-1);
}
int main()
{
	int n;
	while(scanf("%d",&n))
	{
	int sum=fun(n); 
	printf("%d\n",sum);
	}
	return 0;
}
//�ǵݹ�ʵ��(Ԥ����)��
*/
#include<stdio.h>
#define maxn 10000
__int64 a[maxn]={0,2};
int main()
{
	int n;
	for(int i=2;i<=10000;i++)
		a[i]=a[i-1]+2*(i-1);
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",a[n]);
	}
}
