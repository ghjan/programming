#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class A
{
	int age;
	char* name;
public:
	A()
	{
		cout << "A()" << endl;
		age = -1;
		name = new char[1];
		*name = '\0';
	}
	A(int a)
	{
		cout << "A(int a)" << endl;
		age = a;
		name = new char[1];
		*name = '\0';
	}
	A(char* n, int a)
	{
		cout << "A(char* n, int a)" << endl;
		age = a;
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}
	A(const A &a)
	{
		cout << "A(const A &a)" << endl;
		age = a.age;
		name = new char[strlen(a.name) + 1];//1.ע�⣺name��˽��ΪʲôҲ�ܷ��ʣ�
		strcpy(name, a.name);				//����������ͬһ���࣬��������
	}
	void operator=(const A &a)
	{
		cout << "operator=" << endl;

		//��ֹ�Ը�ֵ
		if (this == &a)
			return;

		//�ͷŵ�ǰ��Դ
		delete[] name;
		name = NULL;

		age = a.age;
		name = new char[strlen(a.name) + 1];//1.ע�⣺name��˽��ΪʲôҲ�ܷ��ʣ�
		strcpy(name, a.name);
	}
	~A()
	{
		cout << "~A()" << endl;
		delete[] name;
		name = NULL;
	}
	void show()
	{
		cout << "name :" << name << "\tage :" << age << endl;
	}
};

void test()
{
	A a1("��", 20);
	A a2(a1);//����Զ���������������Ȼ��û��������������ͬһƬ�ڴ�����
	A a3;
	a3 = a1;//����Զ���������������Ȼ��û���Զ���operator=�������������ͬһƬ�ڴ����Σ��൱��ǳ����

	a1 = a1;//��� operator= ��û�ж������������Ҳ���ж�
}

/*��ʾ����ʽ��������ʱ����*/
void test2()
{
	/*��ʾ������ʱ����*/
	A a1 = A("dong", 20);
	/*
	�ȼ���  A a1("dong",20);
	A(char* n, int a)  ����ֻ����һ��
	~A()
	*/
}
void test3()
{
	/*������Ƚ�һ��*/
	A a1;
	a1 = A("dong", 22);
	/*
	A()					//���� a1 ����
	A(char* n, int a)	Ȼ������ʱ������
	operator=			Ȼ��a1����= ��ֵ
	~A()				��ʱ��������
	~A()				a1����
	*/

	a1 = 22;
	/*
	~A()		//������ڴ�
	A(int a)	�ٹ���
	*/
}
void test4()
{
	/*��ʽ������ʱ����*/
	A a1 = 90;
	/*
	A(int a)		//��ȥƥ��Ĭ�Ϲ��캯���е�һ��������int �Ĺ��캯��
	~A()
	*/
	A a2 = (A)("��", 40);//������ȼۡ�Ϊʲô�أ�  �𣺶��ű��ʽ
}
/*��ʱ�����������ڵ�����*/
void test5()
{
	A *p = &A("dong", 22);
	cout << "-----------------" << endl;

	A * const p2 = &A("ming", 22);
	cout << "-----------------" << endl;

	A &p3 = A("hello", 25);
	cout << "-----------------" << endl;

	/*
	A(char* n, int a)
	~A()				����������������
	-----------------
	A(char* n, int a)
	~A()				����������������
	-----------------
	A(char* n, int a)
	-----------------	//�����￴�������ú�ָ�뻹���бȽϴ������ģ��������ò��ܵȼ��� const A *p
	~A()				// �������������˵������ʱ������������ڱ䳤�ˣ������p3����������
	*/
}
void test7(A *p)
{
	p->show();
}
void test6()
{
	/*���������ʱ�����������ڵ�����*/
	test7(&A("dong", 22));
	/*
	A(char* n, int a)
	name :dong      age :22
	~A()							������ط���������ԭ��test7(&A("dong", 22));������䲢û��ִ����
	*/
}

/*�ۺ���ϰ*/
A a1("dong", 20);
void test8()
{
	A a2("hello", 12);
	A a3 = a2;
	static A a4 = A("nice", 30);

	a2 = A("you", 50);
	a2 = (A)("me", 20);
	a2 = 666;

	A *p1 = &A("chen", 55);
	A &q1 = A("ming", 66);

	A *p2 = new A;
	delete p2;
	/*�������Լ���˼���Ĵ𰸣�
	a1����
	a5����
	a4����---------------������ˣ�������staticҲ��һ��һ�е�ִ�У�������ȫ�ֱ���һ����ǰִ��
	a2����
	a3��������
	��ʾ��ʱ������	
	a2 operator=
	a2�ڴ��ͷ�
	��ʾ��ʱ��������
	a2 operator=
	a2�ڴ��ͷ�
	------------��ʽ����	//����û������ ������  ע�⣺��ʽ��ʱ����Ҳ����ù��캯��
	a2 operator=
	a2�ڴ��ͷ�
	------------��ʽ����
	p1����
	p1����
	q1����
	p2����
	p2����
	q1
	a2
	a3
	a4
	a5
	a1����
	*/
}
A a5("a4", 60);
int main()
{
	//test();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();

	test8();

	system("pause");
}

/*
һ��������Ĭ�ϣ�
���캯��
��������
�������캯��
=��ֵ���������**********���� = ��ֵ��������ܼ̳У���Ϊ���඼Ĭ����һ��=����������

A a1("dong",20);
A a2(a1)			 �ȼ��� A a2 = a1 ��� ��ʼ��
A a3;
a3 = a1;			��и�ֵ������� operator=

*/