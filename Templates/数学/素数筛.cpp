#define maxn 1000000
bool valid[maxn];
void getPrime(int n,int &tot,int ans[maxn])    //nΪɸ�����ķ�Χ,totΪ��������,ans[]Ϊprim���� 
{
	memset(valid,true,sizeof(valid));
	for (int i=2;i<=n;i++)
	{
		if (valid[i])
		{
			tot++;
			ans[tot]=i;
			for (int j=2;j<=n/i;j++)
			  valid[i*j]=0;
		}
	}
}
