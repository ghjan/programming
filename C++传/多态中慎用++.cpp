#include <iostream>
using namespace std;

class A{
	public:
		virtual void show()
		{
			cout<<"A"<<endl;
		}
};

class B:public A{
	//int i; 
	public:
	void show()
	{
		cout<<"B"<<endl;
	}
};

int main()
{
	B b[3] = {B(),B(),B()};//3��B���  ����
	
	A* a = b; 
	B* bb = b;
	
	a->show();
	bb->show();
//	B 
//	B
	
	a++;
	bb++;
	//���н��һ�� 
	a->show();
	bb->show();
	//��Ҫ��Ϊû��������,,��B����ע�͵�//int i; �򿪺�ֱ�Ӿͱ�����
	
	//��Ϊ ���� ��Сһ���� ���� ��һ��������ô a++ bb++�Ͳ�һ���ˣ���a++�Ǽ��˻����С  bb++�Ǽ����������С 
	 
}
