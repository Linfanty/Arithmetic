#include<cstdio>
#include<cstring>
using namespace std;
int next[110];
void kmp(char *tem){//����ʾ�ڵ�i���ַ�֮ǰ�ַ���temǰ׺��ͬ�����Ӻ�׺
    int ts=strlen(tem);
    next[0]=-1;
    int point=-1;
    int t=0;
    while(t<ts){
        if(point==-1||tem[point]==tem[t]){
            ++t;
            ++point;
            if(tem[t]!=tem[point])
                next[t]=point;
            else next[t]=next[point];
        }
        else point=next[point];
    }
}
int findl(char *tem,char *main){//����ģ�崮�������е���󹫹������г��ȣ����������е�λ��
    int tstr=strlen(tem);
    int mstr=strlen(main);
    int i=0,j,top=0;//top�洢ÿ��ƥ��ʱ�������Ŀ�ʼλ��
    j=top;
    while(i<tstr&&j<mstr){
        if(tem[i]==main[j]){
            i++;
            j++;
        }
        else{
            top+=i-next[i];
            j=top;
            i=0;
        }
    }
    return top;
}
int main()
{
    char a[110],b[110];
    int loc;
    scanf("%s%s",a,b);
        kmp(b);
        loc=findl(b,a)+1;
        printf("%d\n",loc);
    return 0;
}
