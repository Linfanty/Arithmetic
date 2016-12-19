#include <bits/stdc++.h>
#define MaX 500008
#define ll long long
using namespace std;
const double eps=1e-10;
struct Point{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
};
typedef Point Vector;
//�����Ӽ�
Vector operator + (Vector a,Vector b){
    return Vector(a.x+b.x,a.y+b.y);
}
Vector operator - (Vector a,Vector b){
    return Vector(a.x-b.x,a.y-b.y);
}
//�����˳���ֵ
Vector operator * (Vector a,double b){
    return Vector(a.x*b,a.y*b);
}
Vector operator / (Vector a,double b){
    return Vector(a.x/b,a.y/b);
}
//eps���ƣ�����<��==
int dcmp(double x){
    if(fabs(x)<eps){
        return 0;
    }
    else{
        return x<0?-1:1;
    }
}
bool operator <(const Point& a,const Point& b){
    return a.x-b.x<eps||(dcmp(a.x-b.x)==0&&a.y-b.y<eps);
}
bool  operator == (const Point& a,const Point& b){
    return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;
}
//����a�ļ���
double AngleX(Vector a){
    return atan2(a.y,a.x);
}
//�������
double Dot(Vector a,Vector b){
    return a.x*b.x+a.y*b.y;
}
//����a��ģ
double Length(Vector a){
    return (sqrt(Dot(a,a)));
}
//���������ļн�
double Angle(Vector a,Vector b){
    return acos(Dot(a,b)/Length(a)/Length(b));
}
//�������
double Cross(Vector a,Vector b){
    return a.x*b.y-a.y*b.x;
}
//������ɵ����
double Area2(Point a,Point b,Point c){
    return Cross(b-a,c-a);
}
//������a��תrad�ȣ�rad�ǻ���
Vector Rotate(Vector a,double rad){
    return Vector(a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad));
}
//���������ĵ�λ������������a����������
Vector Normal(Vector a){
    double L=Length(a);
    return Vector(-a.y/L,a.x/L);
}
//��������ֱ�߽��㣬ֱ�߷���Ϊp+tv��q+tw������Cross(v,w)!=0
Point GetLineInter(Point p,Vector v,Point q,Vector w){
    Vector u=p-q;
    double t=Cross(w,u)/Cross(v,w);
    return p+v*t;
}
//��p��ֱ��ab�ľ���
double DisToL(Point p,Point a,Point b){
    Vector v1=b-a,v2=p-a;
    return fabs(Cross(v1,v2))/Length(v1);//��ȡ����ֵΪ�������
}
//��p���߶�ab�ľ���
double DisToS(Point p,Point a,Point b){
    if(a==b){
        return Length(p-a);
    }
    Vector v1=b-a,v2=p-a,v3=p-b;
    if(dcmp(Dot(v1,v2)<0)){
        return Length(v2);
    }
    else if(dcmp(Dot(v1,v3))>0){
        return Length(v3);
    }
    else{
        return fabs(Cross(v1,v2))/Length(v1);
    }
}
//��p��ֱ��ab�ϵ�ͶӰ
Point GetLineProj(Point p,Point a,Point b){
    Vector v=b-a;
    return a+v*(Dot(v,p-a)/Dot(v,v));
}
//�߶�ab,cd�ཻ�ж������㲻��Ϊ�����˵㣩
bool segProInter(Point a,Point b,Point c,Point d){
    double p1=Cross(b-a,c-a),p2=Cross(b-a,d-a),
           p3=Cross(d-c,a-c),p4=Cross(d-c,b-c);
    return dcmp(p1)*dcmp(p2)<0&&dcmp(p3)*dcmp(p4)<0;
}
//����ཻ����Ϊ�˵㣬ֱ����һ���Ƿ��ж˵�����һ��ֱ����
bool OnSeg(Point p,Point a,Point b){
    return dcmp(Cross(a-p,b-p))==0&&dcmp(Dot(a-p,b-p))<0;
}
int main()
{
    int t;
    Point a,b,c,d,f,e;
    Vector bd,bf,cd,ce,ae,af;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y);
        bd=Rotate((c-b),Angle(c-b,a-b)/3);
        bf=Rotate((c-b),2*(Angle(c-b,a-b)/3));
        cd=Rotate((a-c),2*(Angle(a-c,b-c)/3));
        ce=Rotate((a-c),Angle(a-c,b-c)/3);
        ae=Rotate((b-a),2*(Angle(b-a,c-a)/3));
        af=Rotate((b-a),Angle(b-a,c-a)/3);
        d=GetLineInter(b,bd,c,cd);
        e=GetLineInter(a,ae,c,ce);
        f=GetLineInter(a,af,b,bf);
        printf("%lf %lf %lf %lf %lf %lf\n",d.x,d.y,e.x,e.y,f.x,f.y);
    }
}
