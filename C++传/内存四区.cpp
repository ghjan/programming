#include <iostream>
using namespace std;

//��Ա��������̬����----�ڡ������� ��-------������������
//��ָ�룬���ݶ������빲�������ã����Ա���ݣ����Ե���û��˽�����ݵĴ���������

//��̬��������main������ȫ�ֶ����ھ�̬��
//��̬�����ھ�̬����ֻ���ʼ��һ�Σ������С����������������
//���е�const�����Ա����һ�� 

//���еķǾ�̬���ݣ������λ���й�
//������Ķ��󣬾�̬���������ڣ�ջ������̬���䣬����
//���е�ָ�룬�����ڴ�һ���ڶ���//new���Է������κ�һ����

class Dong
{
	int i; 
	static int d; 
	public:
		Dong()
		{
			cout<<"����"<<endl; 
		}
		//������ 
		void show()
		{
			cout<<"hello"<<endl;
		}
		static show2()
		{
			cout<<"hello2"<<endl;
		}
}; 
//��̬��
Dong* d = new Dong();
Dong dd;

int Dong::d = 0;//��̬�� 

int main()
{
	Dong* d;
	d->show2();
	
	Dong* dd = new Dong();// dd ��ջ����������*dd��ָ����ָ��Ķ����ڶ��� 
	
	cout<<sizeof(Dong)<<endl;//4û�а��� 	static int d; �������������Ϊ d �ŵ��� ��̬�� 
	
}
