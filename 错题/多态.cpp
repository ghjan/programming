#include <iostream>
using namespace std;

class A
{
public:
	virtual test()				//ע�⣺����test��ʱ��ᴫ�� �����ߵ�thisָ�� 
	{
		show1();				//���ﶼ�� this->show1(); ���������������B��ķ��� 
		show2();				//���������show2û�м��뵽�������û����д����ֻ�Ǹ������� 
	}
	virtual void show1()
	{
		cout<<"A show1"<<endl;
	}
	void show2()
	{
		cout<<"A show2"<<endl;
	}
};
class B : public A
{
public:
	virtual void show1()
	{
		cout<<"B show1"<<endl;
	}
	void show2()
	{
		cout<<"B show2"<<endl;
	}
};
int main()
{
	B b;
	b.test();//ע��������fastcall����Լ����thisָ�������ȥ�� 
	/*
	B show1
	A show2
	*/
	//����û��ָ�������Ҳ�����˶�̬ 
	
	
	return 0;
}
