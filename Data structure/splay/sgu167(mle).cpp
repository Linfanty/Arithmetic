/*
��id[N]��mle������
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#define inf 10000000000LL
#define N 130007
#define MOD 100
#define ll long long
using namespace std;
int n,m,rt,cnt;//rt��root
int fa[N],c[N][2];//id�Ǳ�ţ�fa�Ǹ��׽�㣬c�����Ҷ���
int siz[N];//v�Ǵ�ŵ�ֵ
bool rev[N];
void update(int x){
    int l=c[x][0],r=c[x][1];
    siz[x]=siz[l]+siz[r]+1;
}
void rot(int x,int &k){//����������������
    int y=fa[x],z=fa[y],l,r;
    l=(c[y][1]==x);
    r=l^1;
    if(y==k){
        k=x;
    }
    else{
        c[z][c[z][1]==y]=x;
    }
    fa[c[x][r]]=y;
    fa[x]=z;
    fa[y]=x;
    c[y][l]=c[x][r];
    c[x][r]=y;//����һ����Ĵ���д����c[y][l]=c[x][r]=y;
    update(y);
    update(x);
}
void splay(int x,int &k){
    while(x!=k){
        int y=fa[x],z=fa[y];
        if(y!=k){
            if(c[y][0]==(x^c[z][0])==y){//x��y��z������ͬһ�࣬��ֱ��תx
                rot(x,k);
            }
            else{//���x��y��z��֮��������תy��תx
                rot(y,k);
            }
        }
        rot(x,k);//ÿ��ת����
    }
}
void build(int l,int r,int f){
    if(l>r){
        return;
    }
    int mid=(l+r)>>1,now=l,last=f;
    if(l==r){
        fa[now]=last;
        siz[now]=1;
        if(l<f){
            c[last][0]=now;
        }
        else{
            c[last][1]=now;
        }
        return;
    }
    else{
        build(l,mid-1,mid);
        build(mid+1,r,mid);
    }
    now=mid;
    fa[now]=last;
    update(mid);
    c[last][mid>=f]=now;
}
void push_down(int k){
	int l=c[k][0],r=c[k][1];
	if(rev[k]){
		swap(c[k][0],c[k][1]);
		rev[l]^=1;
		rev[r]^=1;
		rev[k]=0;
	}
}
int find_r(int x,int rank){
    push_down(x);
    int l=c[x][0],r=c[x][1];
    if(siz[l]+1==rank){
        return x;
    }
    else if(siz[l]>=rank){
        return find_r(l,rank);
    }
    else{
        return find_r(r,rank-siz[l]-1);
    }
}
int main()
{
    int l,r;
    scanf("%d%d",&n,&m);
    build(1,n+2,0);
    rt=(n+3)>>1;//3д����2����
    for(int i=1;i<=m;i++){
        scanf("%d%d",&l,&r);
        int x=find_r(rt,l),y=find_r(rt,r+2);
        splay(x,rt);
        splay(y,c[x][1]);
        rev[c[y][0]]^=1;
    }
    for(int i=2;i<=n+1;i++){
        printf("%d ",find_r(rt,i)-1);
    }
}


