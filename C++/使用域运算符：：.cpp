#include<iostream>
using namespace std;
int i=10;		//Aȫ�ֱ���   ������Ϊ��������
int main()
{
	int i=1;	//B
	{
		int i=5;  //C    ����i��������ֻ��{}��
		int j;
		::i=::i+4;	//::������A����ı���������B
		j=::i+i;	//���ﲻ��::��i��C����ı���
		cout<<"::i="<<::i<<",j="<<j<<",i="<<i<<endl;
	}
	cout<<"::i="<<::i<<",i="<<i<<endl;
	return 0;
}
