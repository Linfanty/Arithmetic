#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
using namespace std;
time_t timep;
int i;
char name[3];
time_t target_time[3];
int pointer=-1;
long long current_time,last_time;
int set_alarm(){
    struct tm temp_tm;
    int yy,mn,dd,hh,mm,ss;
    pointer++;
    printf("�������ƣ�");
    cin>>name[pointer];
    printf("����ʱ�䣺(�꣬�£��գ�ʱ���֣���)");
    cin>>yy>>mn>>dd>>hh>>mm>>ss;
    temp_tm.tm_year = yy - 1900;
    temp_tm.tm_mon = mn - 1;
    temp_tm.tm_mday = dd;
    temp_tm.tm_hour = hh;
    temp_tm.tm_min = mm;
    temp_tm.tm_sec = ss;
    temp_tm.tm_isdst = 0;
    target_time[pointer] = mktime(&temp_tm);
    return 0;
}
int set_countdown_timer(){
    time_t timec;
    int hh,mm,ss;
    pointer++;
    printf("����ʱ���ƣ�");
    cin>>name[pointer];
    printf("����ʱʱ�䣺(ʱ���֣���)");
    cin>>hh>>mm>>ss;
    target_time[pointer] = time(&timec) + hh*3600 + mm*60 + ss;
    return 0;
}
int set_timer(){
    int k;
    int type;
    for (k=0;k<3;k++)
        {
            printf("No%d:���붨ʱ�����(���� 0/����ʱ 1)",k+1);
            scanf("%d",&type);
            if (0 == type)
                {
                    set_alarm();
                }
                if (1 == type)
                    {
                        set_countdown_timer();
                    }
        }
        return 0;
}
int display(int k){
    cout<<"��ʱ��"<<name[k]<<"ʱ�䵽"<<endl;
    return 0;
}
int main(int argc, char* argv[]){
    time(&timep);
    cout<<"ϵͳ����ʱ��:"<<ctime(&timep)<<endl;
    set_timer();
    last_time = time(NULL);
    while (1)
    {
        current_time = time(&timep);
        if (current_time - last_time >= 1)
        {
            cout<<ctime(&timep);
            for (i=0;i<3;i++)
            {
                if (target_time[i] == current_time)
                {
                    display(i);
                }
            }
        }
        last_time = current_time;
    }
    printf("Hello GHouan!\n");
    return 0;
}
