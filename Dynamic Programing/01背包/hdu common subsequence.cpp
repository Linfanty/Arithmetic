/*�����������*/
#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
#define N 20000
using namespace std;
int dp[N][N];
int main()
{
    string a,b;
    int i,j;
    while(cin>>a>>b){
         for(i=0;i<a.size();i++){
            for(j=0;j<b.size();j++){
                dp[i][j]=0;
            }
         }
        for(i=0;i<a.size();i++){
            for(j=0;j<b.size();j++){
                if(a[i]==b[j]){//������ȵĻ�������һ�ε�i-1��j-1����
                    dp[i+1][j+1]=dp[i][j]+1;
                }
                else if(a[i]!=b[j]){//��������ȵĻ���ȡ����С�������������нϴ��ֵ
                    dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        printf("%d\n",dp[a.size()][b.size()]);
    }
    return 0;
}
