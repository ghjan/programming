#include <iostream>
using namespace std;
class a
{
	virtual void func();
};
class b :public virtual a
{
	virtual void foo();
};

void test1()
{
	cout << sizeof(a) << endl;
	cout << sizeof(b) << endl;
	cout << "-------------------------------------" << endl;
}
/*
4
12              ---------   a�м̳���һ��vptr(4B) ��̳�һ��vptr(4B) b���Լ�ָ���麯�����ָ��(4B)  == 12 B
*/