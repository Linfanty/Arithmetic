#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,i,j,on[110],off[110],lenth;
    string s;
    cin>>n;
    for(j=1;j<=n;j++){
        cin>>s;
        memset(on,0,sizeof(on));
        memset(off,0,sizeof(off));
        if(s[0]>='a'&&s[0]<='z'){//�����һ����ĸ��״̬
            on[0]=2;//Сд���Ȱ���ĸȻ�󰴿�
            off[0]=1;//ֱ�Ӱ���ĸ
        }
        else{
            on[0]=2;//��д���Ȱ���Ȼ����ĸ
            off[0]=2;//ֱ�Ӱ�shiftȻ����ĸ
        }
        lenth=s.size();
        for(i=0;i<lenth-1;i++){
            if(s[i+1]>='a'&&s[i+1]<='z'){
                on[i+1]=min(on[i]+1,off[i]+1)+1;//����������´�on״̬ת�Ƶ�on״̬����С�������Ȱ�Shift��������ĸ������off״̬ת�Ƶ�on״̬����С�������Ȱ���ĸ���ٰ�Caps Lock����������off[i-1]+1+1;
                off[i+1]=min(on[i]+1,off[i])+1;
            }
            else{
                on[i+1]=min(on[i],off[i]+1)+1;//��on״̬ת�Ƶ�on״̬����Ҫ���κμ���ֱ�Ӱ���ĸ�����ɣ���off״̬ת�Ƶ�on״̬�����ٲ����ǣ��Ȱ�Caps Lock���ٰ���ĸ����������off[i-1]+1+1;
                off[i+1]=min(on[i]+1,off[i]+1)+1;
            }
        }
        printf("%d\n",min(on[lenth-1]+1,off[lenth-1]));
    }
    return 0;
}
