/*
  ��f(n)Ϊɱ������������Ҫ����Bն���Ĵ���
  ��nΪ1ʱ��ʹ��һ��
  ��nΪż��ʱ��ʹ��f(n/2)��
  ��nΪ����ʱ��ʹ��f(n/2)+1��
*/
#include"iostream"

using namespace std;

int f(long long n ){
    if(n == 1) return 1;
	if(n % 2 == 0) return f(n/2);
	return f(n/2)+1;
}

int main(){

    long long c,num;
    cin >> c;
    for(int i = 0; i < c; i++){
		cin  >> num;
		cout << f(num) << endl;
	}
	return 0;
}