#include<iostream>
using namespace std;

void test0()
{
	const int a = 2;		//��test0��������ڣ�����a�����ڱ����ʱ���滻Ϊ2
	int *p = (int *)&a;
	*p = 20;
	cout << a << endl;//2
}
void test()
{
	int b = 2;
	const int a = b;
	int *p = (int *)&a;
	*p = 20;
	cout << a << endl;//20
}

int size()
{
	return 2;
}
void test2()
{
	int b = 2;
	const int a = size();		//���Ҫ����һ����������ֵ��a����һ���������ˣ����ǳ����ˣ��������a��ɳ����أ�
	int *p = (int *)&a;
	*p = 20;
	cout << a << endl;//20
}
//constexprĬ���������ģ���Ϊ��Ҫ�ڱ���ʱ��չ��������ȫ�ǳ����������ڱ����ھ�չ����
/*constexpr*/ int size2()	//return����ֻ����һ��
{
	return 2;			//��������������vs�������֧��constexpr����������������
}
void test3()
{
	int b = 2;
	const int a = size2();
	int *p = (int *)&a;
	*p = 20;
	cout << a << endl;//2
}