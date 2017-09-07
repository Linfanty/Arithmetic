#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int MAXN=100007;
int sa[MAXN];//SA���飬��ʾ��S��n����׺��С�����������ź����
             //�ĺ�׺�Ŀ�ͷλ��˳�η���SA��
int t1[MAXN],t2[MAXN],c[MAXN];//��SA������Ҫ���м����������Ҫ��ֵ
int ran[MAXN],height[MAXN];
//��������ַ�������s�����У���s[0]��s[n-1],����Ϊn,�����ֵС��m,
//��s[n-1]�������s[i]������0��r[n-1]=0
//���������Ժ�������sa������
void build_sa(int s[],int n,int m)
{
    int i,j,p,*x=t1,*y=t2;
    //��һ�ֻ����������s�����ֵ�ܴ󣬿ɸ�Ϊ��������
    for(i=0;i<m;i++)c[i]=0;
    for(i=0;i<n;i++)c[x[i]=s[i]]++;
    for(i=1;i<m;i++)c[i]+=c[i-1];
    for(i=n-1;i>=0;i--)sa[--c[x[i]]]=i;
    for(j=1;j<=n;j<<=1)
    {
        p=0;
        //ֱ������sa��������ڶ��ؼ���
        for(i=n-j;i<n;i++)y[p++]=i;//�����j�����ڶ��ؼ���Ϊ�յ���С
        for(i=0;i<n;i++)if(sa[i]>=j)y[p++]=sa[i]-j;
        //��������y����ľ��ǰ��յڶ��ؼ�������Ľ��
        //���������һ�ؼ���
        for(i=0;i<m;i++)c[i]=0;
        for(i=0;i<n;i++)c[x[y[i]]]++;
        for(i=1;i<m;i++)c[i]+=c[i-1];
        for(i=n-1;i>=0;i--)sa[--c[x[y[i]]]]=y[i];
        //����sa��x��������µ�x����
        swap(x,y);
        p=1;x[sa[0]]=0;
        for(i=1;i<n;i++)
            x[sa[i]]=y[sa[i-1]]==y[sa[i]] && y[sa[i-1]+j]==y[sa[i]+j]?p-1:p++;
        if(p>=n)break;
        m=p;//�´λ�����������ֵ
    }
}
void getHeight(int s[],int n)
{
    int i,j,k=0;
    for(i=0;i<=n;i++)ran[sa[i]]=i;
    for(i=0;i<n;i++)
    {
        if(k)k--;
        j=sa[ran[i]-1];
        while(s[i+k]==s[j+k])k++;
        height[ran[i]]=k;
    }
}
char str[MAXN],x[3];
int s[MAXN];
vector<int>locx;
vector<int>::iterator it;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    int kase=0;
    while(T--)
    {
        locx.clear();
        scanf("%s",x);
        scanf("%s",str);
        int n=strlen(str);
        for(int i=0;i<=n;i++){
            if(str[i]==x[0]){
                locx.push_back(i);
            }
        }
        for(int i=0;i<=n;i++)s[i]=str[i];
        build_sa(s,n+1,128);
        getHeight(s,n);
        long long ans=0;
        for(int i=0;i<=n;i++){
            it=lower_bound(locx.begin(),locx.end(),sa[i]);
            if(it!=locx.end()) {
                ans+=n-max(sa[i]+height[i],*it);
            }
        }
        printf("Case #%d: %I64d\n",++kase,ans);
    }
    return 0;
}
