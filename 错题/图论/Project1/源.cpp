#include <iostream>
#include <cstring>
using namespace std;

struct A
{
	int a;
	char *b;
}*p;

void test()
{
	cout << p << endl;
	cout << p + 1 << endl;//�ӵ������� struct ��С
	cout << (unsigned int)p + 1 << endl;//ת�� unsigned int �� int ��һ��   ����Ϊ1
	cout << (unsigned int *)p + 1 << endl;//����Ϊ4
	/*
	00000000
	00000008
	1
	00000004
	*/
	cout << &p << endl;
	cout << &p + 1 << endl;			//�൱��ת����ָ�� ����Ϊ4
	cout << (int*)&p + 1 << endl;	//ת����ָ�� ����Ϊ4
	cout << (int)&p + 1 << endl;	//����Ϊ1
	/*
	00B4F320
	00B4F324
	00B4F324
	11858721
	*/
}
int main()
{

	test2();

	system("pause");
}