//C++�������������    ��ʮһ��    �ڶ�����    ��1С��
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

/*
ע�⣺���������뱾��ִ���ļ���ʱ������˫�������������߸�����ִ�г�����ļ���
*/

void DelPreChar(string& iss,int staIndex) {
	string temp;
	for(int i=0;staIndex<iss.size();++staIndex,++i)
		temp+=iss[staIndex];
	iss=temp;
}

void OutPreChar(ofstream& ofs,string& iss,int endText) {
	int p1=0,p=0;
	for(int i=0;i<endText;++i){    //kashdk
        if(p1==0&&iss[i]==' '){
            p1=i;
        }
        else if(iss[i]!=' '){
            p1=0;
            p=1;
        }
	}
	if(p==0){
        return;
	}
	else if(p==1&&p1!=0){
        for(int i=0;i<p1;i++){
            ofs<<iss[i];
        }
        ofs<<endl;
	}
}

void TextEdit(bool& text,ofstream& ofs,string& iss) {
	int endText=iss.find('\"');
	if (-1==endText||(0!=endText&&iss[endText-1]=='\\')) {//�ı�δ����
		ofs<<iss<<'\n';
		return;
	}
	for(int i=0;i<=endText;++i)
		ofs<<iss[i];
	text=false;
	DelPreChar(iss,endText+1);
}

int main(int argc,char* argv[]) {
	if(argc!=2) {
		cout<<"������������\n";
		exit(0);
	}
	ifstream ifs(argv[1]);
	if(!ifs.is_open()) {
		cout<<"�ļ������ڣ�\n";
		exit(0);
	}
	bool blockNote=false,text=false;
	string iss;
	int i,rowIndex,blockIndex,endIndex,staText;
	ofstream ofs("temp.tmp");//�˴�δ����ļ��Ƿ��������Ϊ�����ص㲻�ڴ˴�
	while (getline(ifs,iss)) {
		if(text) {//�ж��Ƿ����ı�����""����
			TextEdit(text,ofs,iss);
			if(text)//��������ı���δ����
				continue;
		}
		if(blockNote) {//�ж��Ƿ���ڿ�ע��
			blockIndex=iss.find("*/");
			if(blockIndex==-1)//û�п�ע�ͽ����ı�־
				continue;
			blockNote=false;
			i=blockIndex+2;
			while (i<iss.size()) {
				ofs<<iss[i];
				++i;
			}
			DelPreChar(iss,blockIndex+2);
			ofs<<'\n';
		}

		staText=iss.find('\"');
		rowIndex=iss.find("//");
		blockIndex=iss.find("/*");
		if(!(-1==staText||(-1!=rowIndex&&rowIndex<staText)||(-1!=blockIndex&&blockIndex<staText)))//�ж�˫�����Ƿ���ע����
			while(-1!=staText&&!iss.empty()) {
				if(0!=staText&&iss[staText-1]=='\\')
					break;
				OutPreChar(ofs,iss,staText);
				DelPreChar(iss,staText+1);
				text=true;
				TextEdit(text,ofs,iss);
				staText=iss.find('\"');
			}
		if(iss.empty())
			continue;
		rowIndex=iss.find("//");
		blockIndex=iss.find("/*");
		if (-1==rowIndex&&-1==blockIndex) {//������ע�ͣ�Ҳ�޿�ע��
			ofs<<iss<<'\n';
			continue;
		}
		if(-1!=rowIndex&&-1!=blockIndex)//��ע�����ע�͵Ŀ�ʼ�ı�־������
			if (rowIndex<blockIndex)//��ע����Ч
				blockIndex=-1;
			else//��ע����Ч
				rowIndex=-1;
		if(-1==rowIndex) {//ֻ���ڿ�ע��
			endIndex=iss.find("*/");
			for (i=0;i<blockIndex;++i)
				ofs<<iss[i];
			if(-1==endIndex)//��ע��δ�ڱ��н���
				blockNote=true;
			else
				for(i=blockIndex+2;i<iss.size();++i)
					ofs<<iss[i];
			ofs<<'\n';
			continue;
		}
		if(-1==blockIndex) {//ֻ������ע��
			for (i=0;i<rowIndex;++i)
				ofs<<iss[i];
			ofs<<'\n';
			continue;
		}
	}

	/*
	ifstream ����״̬�Ķ���һ�� ifstream �������һ�㴦�ڷ�����״̬���ڲ��� eofbit ��� failbit ��ǵȿ����ѱ��趨��
	���´��ļ������������Щ��ǣ������Ҫ���һ����
	ifs.clear();  // ȥ�� ifs �еĴ�����(���ļ�ĩβ��ǻ��ȡʧ�ܱ�ǵ�)
	*/

	ifs.clear();
	ofs.clear();

	ifs.close();
	ofs.close();
	//������м��ļ�temp.tmpȫ�����Ƶ�ԭ�ļ���
	ifs.open("temp.tmp");
	if(!ifs.is_open()) {
		cout<<"�����ļ���ʧ�����������б�����\n";
		exit(0);
	}
	ofs.open(argv[1]);
	while (getline(ifs,iss)) {
		ofs<<iss<<'\n';
	}
	ifs.close();
	ofs.close();
	//ɾ���м��ļ�
	remove("temp.tmp");
	return 0;
}//end of main

