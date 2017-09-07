#include <iostream>
#include <memory>
using namespace std;

class A
{
public:
	A(){ cout << "����" << endl; }
	~A(){ cout << "����" << endl; }
	void show(){ cout << "show" << endl; }
};
void test1()
{
	int *p = new int(10);
	shared_ptr<int> ptr(p);
	cout << *ptr << " " << *p << endl;
}
/*�������ַ�������һ����*/
void test2()
{
	shared_ptr<A> ptr(new A);
	ptr->show();
}
/*
����
show
����
*/
void test3()
{
	shared_ptr<A> ptr = make_shared<A>();
	ptr->show();
}
/*
����
show
����
*/
void test4()
{
	shared_ptr<A> ptr(new A);
	shared_ptr<A> ptr2(ptr);
	ptr->show();
	ptr2->show();
}
/*
����
show
show
����
*/
void test5()
{
	A *p = new A;
	shared_ptr<A> ptr(p);
	shared_ptr<A> ptr2(p);//���������ֱ�ӹҵ��������ͷ�ͬһƬ�ڴ棬����������ò�Ҫ����ָ�룬ȫ������ָ��
}
int main()
{
	test5();

	system("pause");
	return 0;
}