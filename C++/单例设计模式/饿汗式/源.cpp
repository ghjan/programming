#include <iostream>
using namespace std;

class A
{
public:
	static A *instance;
	//static A *getInstance()//���Բ�Ҫ
	//{
	//	return instance;
	//}
	void show(){ cout << "��" << endl; }
private:
	A(){}
	~A(){}
};
A *A::instance = new A;


int main()
{
	A *a = A::instance;
	a->show();
	
	system("pause");
	return 0;
}