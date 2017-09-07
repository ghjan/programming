#include <iostream>
#include "Singleton1.h"
#include "Singleton2.h"
using namespace std;

class A :public Singleton1<A>
{
public:
	void show()
	{
		cout << "show" << endl;
	}
	//friend class Single<A>;//��Ҫ����Ϊ��Ԫ������ܷ���
	friend A *Singleton1<A>::getInstance();//����Ҳ����
private:
	A(){}
	~A(){}
};
class B :public Singleton2<B>
{
public:
	void show()
	{
		cout << "show" << endl;
	}
	friend class Singleton2<B>;//��Ҫ����Ϊ��Ԫ������ܷ���
private:
	B(){}
	~B(){}
};

int main()
{
	A *a = A::getInstance();
	a->show();

	B *b = B::getInstance();
	b->show();

	system("pause");
	return 0;
}
