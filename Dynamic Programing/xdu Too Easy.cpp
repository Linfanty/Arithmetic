#include <cstdio>
struct Mat{
    int m[5][5];
}a;
Mat operator * (Mat a, Mat b) {
    Mat c;
    memset(c.mat,0,sizeof(c.mat));
    int i,j,k;
    for(k=0;k<n;++k) {
        for(i=0;i<n;++i) {
            if(a.mat[i][k]<=0)  continue;   //(���ZOJ2853)��֦��cpu����˷���Ч�ʲ������������ô���루�ӷ�������Ч�ʸ��ڳ˷�������Strassen����˷���
            for(j=0;j<n;++j) {
                if(b.mat[k][j]<=0){
                    continue;    //��֦
                }
                c.mat[i][j]+=a.mat[i][k]*b.mat[k][j];
            }
        }
    }
    return c;
}
Mat operator ^ (Mat a,int k) {
    Mat c;
    int i,j;
    for(i=0;i<n;++i)
        for(j=0;j<n;++j)
            c.mat[i][j]=(i==j);    //��ʼ��Ϊ��λ����
    for(;k;k>>=1) {
        if(k&1)c=c*a;
        a=a*a;
    }
    return c;
}
int main()
{



}
