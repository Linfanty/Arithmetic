/*
 * SPOJ 694
 * ����һ���ַ���������ͬ�Ӵ�������
 * ÿ���Ӵ�һ����ĳ����׺��ǰ׺����ôԭ����ȼ��������к�׺֮��Ĳ���ͬ�Ӵ�������
 * ����Ϊn*(n-1)/2,�ټ���height[i]�ĺ;��Ǵ�
 */

#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int MAXN=1010;

/*
*suffix array
*�����㷨  O(n*logn)
*���������鳤��Ϊn,����0~n-1�У�������油һ��0
*build_sa( ,n+1, );//ע����n+1;
*getHeight(,n);
*���磺
*n   = 8;
*num[]   = { 1, 1, 2, 1, 1, 1, 1, 2, $ };ע��num���һλΪ0����������0
*rank[]  = { 4, 6, 8, 1, 2, 3, 5, 7, 0 };rank[0~n-1]Ϊ��Чֵ��rank[n]�ض�Ϊ0��Чֵ
*sa[]    = { 8, 3, 4, 5, 0, 6, 1, 7, 2 };sa[1~n]Ϊ��Чֵ��sa[0]�ض�Ϊn����Чֵ
*height[]= { 0, 0, 3, 2, 3, 1, 2, 0, 1 };height[2~n]Ϊ��Чֵ
*
*/

int sa[MAXN];//SA���飬��ʾ��S��n����׺��С�����������ź����
             //�ĺ�׺�Ŀ�ͷλ��˳�η���SA��
int t1[MAXN],t2[MAXN],c[MAXN];//��SA������Ҫ���м����������Ҫ��ֵ
int rank[MAXN],height[MAXN];
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
    for(i=0;i<=n;i++)rank[sa[i]]=i;
    for(i=0;i<n;i++)
    {
        if(k)k--;
        j=sa[rank[i]-1];
        while(s[i+k]==s[j+k])k++;
        height[rank[i]]=k;
    }
}

char str[MAXN];
int s[MAXN];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",str);
        int n=strlen(str);
        for(int i=0;i<=n;i++)s[i]=str[i];
        build_sa(s,n+1,128);
        getHeight(s,n);
        int ans=n*(n+1)/2;
        for(int i=1;i<=n;i++){
            cout<<sa[i];
            ans-=height[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}