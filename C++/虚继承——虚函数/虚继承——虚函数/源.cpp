#include <iostream>
using namespace std;

class A{//�����

};
class B1 : virtual public A{						//��һ�����ָ�룬�洢������ַ 
};
class B2 : virtual public A, virtual public B1{
};
class C1 : virtual public B2 ,virtual public A{		//һ�����ָ����4�ֽ�*3
};
class C2 : virtual public A{
	virtual void b1() = 0;//��һ��vptr ָ���������׵�ַ
};
class C3 : virtual public A{
public:
	virtual void b1()
	{
		cout << "c3" << endl;
	}
};


int main()
{
	cout << "һ��ָ���С\t" << sizeof(int*) << endl;
	cout << "A\t" << sizeof(A) << endl;		// 1
	cout << "B1\t" << sizeof(B1) << endl;	// 4
	cout << "B2\t" << sizeof(B2) << endl;	// 8
	cout << "C1\t" << sizeof(C1) << endl;	// 12
	cout << "C2\t" << sizeof(C2) << endl;	// 8

	C1();
	//C2();		Ҫע�⺬�д��麯�����࣬�г�����	�����಻��ʵ����
	C3().b1();	//���麯���Ĳ��ǳ�����

	system("pause");
}