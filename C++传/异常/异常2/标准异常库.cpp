#include <iostream>
using namespace std;

class MyException :public exception//�̳��쳣
{
public:
	MyException()
	{
		cout << "���캯��" << endl;
	}
	virtual const char *  what()
	{
		cout << "�����쳣��" << endl;
		return NULL;
	}
};
void test5()
{
	throw MyException();
}
int main()
{
	try{
		test5();
	}
	catch (MyException m){
		m.what();
	}
	//	���캯��
	//	�����쳣��
	system("pause");
}