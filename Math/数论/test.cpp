/*
����ֵ�nΪ������ʱ��1~n֮����n�����Լ���ǶԳƵ�
���������ͨ��Ȼ��дһд��ʽ������ʵ����phi��n/d��d��n������
*/
#include <bits/stdc++.h>
using namespace std;
int phi(int n){
    int temp=n;
    for(int i=2;i*i<n;i++){
        if(n%i==0){
            while(n%i==0){
                n/=i;
            }
            temp=temp/i*(i-1);
        }
        if(n<i+1){
            break;
        }
    }
    if(n>1){
        temp=temp/n*(n-1);
    }
    return temp;
}
int main()
{
    int n,ans;
    while(scanf("%d",&n)!=EOF){
        ans=phi(n);
        int tmp=n;
        //printf("%d",ans);
        for(int i=2;i*i<=tmp;i++){
            if(n%i==0){
                while(n%i==0){
                    n/=i;
                }
                ans+=phi(tmp/i)*i;
            }
        }
        if(n>1){
            ans+=phi(tmp/n)*n;
            if(n!=tmp){
                ans+=tmp;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
