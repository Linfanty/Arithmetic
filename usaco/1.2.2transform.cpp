/*
ID: 15829681
LANG: C++
TASK: transform
*/
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#define LOCAL
using namespace std;
char s[11][11],ss[11][11],a[11][11],b[11][11];
int n;
void ch90(){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            s[j][n-i-1]=a[i][j];
            //printf("%c",s[j][n-i-1]);
        }
    }
    //for(i=0;i<n;i++){
       //printf("%s\n",s[i]);
    //}
}
void ch180(){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            s[n-i-1][n-j-1]=a[i][j];
        }
    }
}
void ch270(){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            s[j][i]=a[i][j];
        }
    }
}
void ch902(){//��Ϊ��������ȫ�ֱ������������������Եڶ����ھ���֮��������ת��ʱ����Ҫ���´��µ����
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            ss[j][n-i-1]=s[i][j];
            //printf("%c",s[j][n-i-1]);
        }
    }
    //for(i=0;i<n;i++){
       //printf("%s\n",s[i]);
    //}
}
void ch1802(){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            ss[n-i-1][n-j-1]=s[i][j];
        }
    }
}
void ch2702(){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            ss[j][i]=s[i][j];
        }
    }
}
void chmir(){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            s[i][n-j-1]=a[i][j];
        }
    }
}
void find1(){
    int i,j,p;
    p=0;
    ch90();
    p=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(s[i][j]!=b[i][j]){
                p=1;
                break;//ֻ������һ��ѭ����Ҫ��������ѭ��
            }
        }
        if(p==1)break;//�ڶ���ѭ������Ҫ�����ж�
    }
    if(i==n){
        printf("1\n");
        return;
    }
    else{
        ch180();
        p=0;
        //for(i=0;i<n;i++){
            //cout<<s[i]<<endl;
        //}
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(s[i][j]!=b[i][j]){
                    p=1;
                    break;
                }
            }
            if(p==1)break;
        }
        if(i==n){
            printf("2\n");
            return;
        }
        else{
            ch270();
            p=0;
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    if(s[i][j]!=b[i][j]){
                        p=1;
                        break;
                    }
                }
                if(p==1)break;
            }
            if(i==n){
                printf("3\n");
                return;
            }
            else{
                chmir();
                p=0;
                for(i=0;i<n;i++){
                    for(j=0;j<n;j++){
                        if(s[i][j]!=b[i][j]){
                            p=1;
                            break;
                        }
                    }
                    if(p==1)break;
                }
                if(i==n){
                    printf("4\n");
                    return;
                }
                else{
                    ch902();
                    p=0;
                    for(i=0;i<n;i++){
                        for(j=0;j<n;j++){
                            if(ss[i][j]!=b[i][j]){
                                p=1;
                                break;
                            }
                        }
                        if(p==1)break;
                    }
                    if(i==n){
                        printf("5\n");
                        return;
                    }
                    else{
                        ch1802();
                        p=0;
                        for(i=0;i<n;i++){
                            for(j=0;j<n;j++){
                                if(ss[i][j]!=b[i][j]){
                                    p=1;
                                    break;
                                }
                            }
                            if(p==1)break;
                        }
                        if(i==n){
                            printf("5\n");
                            return;
                        }
                        else{
                            ch2702();
                            p=0;
                            for(i=0;i<n;i++){
                                for(j=0;j<n;j++){
                                    if(ss[i][j]!=b[i][j]){
                                        p=1;
                                        break;
                                    }
                                }
                                if(p==1)break;
                            }
                            if(i==n){
                                printf("5\n");
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
    for(i=0;i<n;i++){//������ԳƵ����������ת180ֱ���ж�
        for(j=0;j<n;j++){
            if(a[i][j]!=b[i][j]){
                p=1;
                break;
            }
        }
        //printf("%d",i);
        if(p==1)break;
    }
    if(i==n){
        printf("6\n");
        return;
    }
    printf("7\n");
    return;
}
int main()
{
    #ifdef LOCAL
    freopen("transform.in","r",stdin);
    freopen("transform.out","w",stdout);
    #endif
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<n;i++){
        cin>>b[i];
    }
    find1();
    return 0;
}
