#include<iostream>
#include<typeinfo>
using namespace std;

void test1(const int* a)
{
	cout << typeid(a).name() << endl;
}
void test2(int const* a)
{
	cout << typeid(a).name() << endl;
}
void test3(int *const a)
{
	cout << typeid(a).name() << endl;
}
void test4(int *a)
{
	cout << typeid(a).name() << endl;
}
int main4()
{
	const int *a = NULL;
	int const* b = NULL;
	int *const c = NULL;
	int* d = NULL;
	test1(a);
	test2(b);
	test3(c);
	test3(d);
	/*
	int const *
	int const *
	int *				//���Կ�����const �ұ�û��*ʱ const���Ժ��Ե�������һ������ֻҪa���仯����
	int *
	*/

	system("pause");
	return 0;
}