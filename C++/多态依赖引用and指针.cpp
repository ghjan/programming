#include <iostream>
using namespace std;

class A
{
public:
	A(){
		cout<<"aaa"<<endl;
	}
	A(const A &a)
	{
		cout<<"A��������"<<endl;
	}
	virtual void dong()
	{
		cout<<"AAAAAAAAAAAAAAAAAAAAAAAAA"<<endl;
	}
};
class B : public A
{
public:
	B(){
		cout<<"bbb"<<endl;
	}
	B(const B &a)
	{
		cout<<"B��������"<<endl;
	}
		virtual void dong()
	{
		cout<<"BBBBBBBBBBBBBBBBBBBB"<<endl;
	}
};

void test1(A *a)
{
	a->dong();
}
void test2(A &a)
{
	a.dong();
}
void test3(A a)
{
	a.dong();
}

int main()
{
	A* a = new B;
	test1(a);
	cout<<"------------------------------"<<endl;
	test2(*a);
	cout<<"------------------------------"<<endl;
	test3(*a);
}
/*
aaa
bbb
BBBBBBBBBBBBBBBBBBBB
------------------------------
BBBBBBBBBBBBBBBBBBBB
------------------------------
A��������								//���õ���A�Ŀ������� 
AAAAAAAAAAAAAAAAAAAAAAAAA				//���Զ�����ȫ����A��   û�ж�̬�� 
*/
