#include <iostream>
using namespace std;

class A{
public:
	int i;
	A(){
		cout << "���캯��" << endl;
		i = 0;
	}
	~A(){
		cout << "��������" << endl;
		i++;
	}
	A(const A &a)
	{
		cout << "�������캯��" << endl;
	}
	void show()
	{
		cout << "show ����" << endl;
		i++;
	}
};

void test()
{
	throw A();
}
void test2()
{
	throw new A;
}
void test3()
{
	throw &A();
}
//ע�⣺*a���Ժ�&a,a���棬����&a��a���ܹ���
int main4()
{
	try{
		test3();
	}
	catch (A *a){			//����������copy
		a->show();
		cout << a->i << endl;
		cout << "�쳣����" << endl;
		//delete a;//�������delete��������
	}
	//	���캯��
	//	��������
	//	show ����		//���ﻹ��˵�ù�ȥ���Ͼ���ռ�ڴ�
	//	2				//������ĺܷѽ⣬Ϊɶ�ڴ�û�б��ͷš�����������Ƶײ㲢���Ǽ򵥵�A* a = &A();
	//	�쳣����
	system("pause");
	return 0;
}
int main3()
{
	try{
		test2();
	}
	catch (A *a){			//����������copy
		a->show();
		cout << "�쳣����" << endl;
		delete a;
	}
/*		���캯��
		show ����
		�쳣����
		��������	  ע����Ҫ�Լ�����delete�������ܱ����� */	
	system("pause");
	return 0;
}
int main2()
{
	try{
		test();
	}
	catch (A &a){			//����������copy
		a.show();
		cout << "�쳣����" << endl;
	}
	//	���캯��
	//	show ����
	//	�쳣����
	//	��������			//ֻ������һ����������
	system("pause");
	return 0;
}
int main1()
{
	try{
		test();
	}
	catch (A a){			//����������copy
		a.show();
		cout << "�쳣����" << endl;
	}
	//	���캯��
	//	�������캯��		//�����˿�������
	//	show ����
	//	�쳣����
	//	��������			//��������
	//	��������
	system("pause");
	return 0;
}