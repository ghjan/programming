#include<iostream>
using namespace std;

void test(int i)
{
	cout << typeid(i).name() << endl;
}
void test(int *i)
{
	cout << typeid(i).name() << endl;
}

void main()
{
	test(NULL);//��c++��  NULL  �������� 0 
	test(nullptr);//��c++��  nullptr  ���� ��ָ��

	cout << typeid(NULL).name() << endl;
	cout << typeid(nullptr).name() << endl;
	//C++�ϸ�����ƥ��

	cin.get();
}