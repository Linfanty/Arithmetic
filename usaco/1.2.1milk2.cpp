/*
ID: 15829681
LANG: C++
TASK: milk2
*/
#include <cstdio>
#include <algorithm>
#include <queue>
#define LOCAL
#define N 5005
using namespace std;
struct node{
    int l,r;
}a[N];
bool cmp (node a,node b){
    if(a.l==b.l){
        return a.r<b.r;
    }
    else{
        return a.l<b.l;
    }
}
int main()
{
    #ifdef LOCAL
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);
    #endif
    int n,now,no,i;
    //priority_queue<node,vector<node>,greater<node> >q;
    scanf("%d",&n);
    scanf("%d%d",&a[1].l,&a[1].r);
    //q.push(a);
    no=0;
    for(i=2;i<=n;i++){
        scanf("%d%d",&a[i].l,&a[i].r);
    }
    sort(a+1,a+n+1,cmp);//����˵�Ĵ�С��Ϊ��һ��׼����
    now=a[1].r-a[1].l;
    node p=a[1];//p�������浱ǰ������ӵ�����
    for(i=2;i<=n;i++){
        if(a[i].l<=p.r&&a[i].l>=p.l){//����µ�������˵��ڵ�ǰ������
            if(a[i].r>p.r){//������������Ҷ˵㣬������������У����µ�ǰ���䳤�ȼ��Ҷ˵�
                now=max(now,a[i].r-p.l);
                p.r=a[i].r;
            }
        }
        else{
            //printf("1");
            if(a[i].r-a[i].l>now){//���ڲ����������������䣬����������µ�׼�����������ܸ������䳤�����ֵ
                now=a[i].r-a[i].l;
            }
            //printf("%d",now);
            no=max(no,a[i].l-p.r);//��������䳤�����ֵ
            //printf("%d",no);
            p=a[i];//���µ�ǰ����
        }
    }
    printf("%d %d\n",now,no);
    return 0;
}
