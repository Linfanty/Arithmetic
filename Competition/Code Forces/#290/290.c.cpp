#include<cstdio>
#include<cstring>
int main()
{
    int num,i,m,j,k,p,p2,length,fin[27][27];
    int point[26];
    char c[100],n[100],ans[26];
    scanf("%d",&num);
    memset(fin,0,sizeof(fin));
    for(int i=0;i<num;i++){
        scanf("%s",c);
        n[i]=c[0];//������ĸ��
    }
    p=0;
    for(i=0;i<strlen(n)-1;i++){
        if(p==1&&n[i]!=n[i+1]){
            fin[n[i]-97][n[i+1]-97]=1;
            continue;
        }
        if(n[i]>n[i+1]&&p!=1){
            fin[n[i]-97][n[i+1]-97]=1;
            p=1;
        }
    }//�ӵ�һ�����ֲ�������ĸ��˳��Ŀ�ʼ�����ڽӾ����ϵ
    /*for(i=0;i<26;i++){
        for(j=0;j<26;j++)
        printf("%d",fin[j][15]);
        printf("\n");
    }*/
    k=0;
    memset(point,0,26);//���ڱ���Ѿ���������ĸ���е���ĸ
    for(m=0;m<26;m++){//ÿ��ѡ����ĸ��ʱ����������26����ĸ������ÿ����ĸ�����жϸ���ĸ������Ƿ�Ϊ1�����Ϊ1���������������һ����ĸ��������Ϊ0�������롣
        for(i=0;i<26;i++){
            p2=0;
            for(j=0;j<26;j++){
                if(fin[j][i]==1){
                    p2=1;
                    //printf("1%c\n",i+97);
                    break;
                }
            }
            if(p2==0&&point[i]!=1){
                point[i]=1;
                ans[m]=i+97;
                k++;
                for(j=0;j<26;j++){
                    fin[i][j]=0;
                }//���Ϊ0��������������������ĳ�����Ϊ0,��Ϊ������ڻ��������ͬһ����ĸ������һ����������ĸ��������ȣ���֮������ֲ������룬������ĸ�������ĸ��С��26
                //printf("2%c\n",ans[m]);
                break;
            }
        }
    }//��
    //printf("%d",k);
    if(k==26){
        for(i=0;i<k;i++){
            printf("%c",ans[i]);
        }
    }
    else if(k!=26)printf("Impossible");//��������ĸ�������ĸ���ж��Ƿ�����������ĸ��
    return 0;
}
