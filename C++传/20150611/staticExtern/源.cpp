//������ǰ�ļ���static�����ǿ��ļ���extern
//�����ṹ���ͬ��ȫ�ֱ����� ���Կ��ļ���������������
#include<iostream>
using namespace std;
extern int a;//�����ⲿȫ�ֱ���
static int a = 123;

namespace std
{
	int a = 99;//��a��: ����ȷ�ķ���
}

void main()
{
	//cout << a << endl;
	cout << ::a << endl;
	void test();
	test();

	cin.get();
}
