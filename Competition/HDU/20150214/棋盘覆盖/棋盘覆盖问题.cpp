#include<iostream>  
using namespace std;  
long long int tile=1;                   //L�͹��Ƶı��(����)  
long long int board[1000][1000];       //����  
/***************************************************** 
* �ݹ鷽ʽʵ�����̸����㷨 
* ��������� 
* tr--��ǰ�������Ͻǵ��к�
* tc--��ǰ�������Ͻǵ��к�
* dr--��ǰ���ⷽ�����ڵ��к� 
* dc--��ǰ���ⷽ�����ڵ��к� 
* size����ǰ���̵�:2^k 
*****************************************************/  
void chessBoard ( int tr, int tc, int dr, int dc, int size )  
{  
    if ( size==1 )    //���̷����СΪ1,˵���ݹ鵽�����  
        return;  
    long long int t=tile++;     //ÿ�ε���1  
    int s=size/2;    //�����м���С��к�(��ȵ�)  
    //������ⷽ���Ƿ������Ͻ���������             
    if ( dr<tr+s && dc<tc+s )              //��  
        chessBoard ( tr, tc, dr, dc, s );  
    else         //���ڣ��������������½ǵķ�����Ϊ���ⷽ��  
    {  
        board[tr+s-1][tc+s-1]=t;  
        chessBoard ( tr, tc, tr+s-1, tc+s-1, s );  
    }  
    //������ⷽ���Ƿ������Ͻ���������  
    if ( dr<tr+s && dc>=tc+s )               //��  
        chessBoard ( tr, tc+s, dr, dc, s );  
    else          //���ڣ��������������½ǵķ�����Ϊ���ⷽ��  
    {  
        board[tr+s-1][tc+s]=t;  
        chessBoard ( tr, tc+s, tr+s-1, tc+s, s );  
    }  
    //������ⷽ���Ƿ������½���������  
    if ( dr>=tr+s && dc<tc+s )              //��  
        chessBoard ( tr+s, tc, dr, dc, s );  
    else            //���ڣ��������������Ͻǵķ�����Ϊ���ⷽ��  
    {  
        board[tr+s][tc+s-1]=t;  
        chessBoard ( tr+s, tc, tr+s, tc+s-1, s );  
    }  
    //������ⷽ���Ƿ������½���������  
    if ( dr>=tr+s && dc>=tc+s )                //��  
        chessBoard ( tr+s, tc+s, dr, dc, s );  
    else         //���ڣ��������������Ͻǵķ�����Ϊ���ⷽ��  
    {  
        board[tr+s][tc+s]=t;  
        chessBoard ( tr+s, tc+s, tr+s, tc+s, s );  
    }  
}  
  
int main()  
{  
    int size;  
    cout<<"�������̵�size(��С������2��n����): ";  
    cin>>size;  
    int x,y;  
    cout<<"�������ⷽ��λ�õ�����: ";  
    cin>>x>>y;  
    chessBoard ( 0,0,x,y,size);  
    for ( int i=0; i<size; i++ )  
    {  
        for ( int j=0; j<size; j++ )  
            cout<<board[i][j]<<"\t";  
        cout<<endl; 
    }  
}
