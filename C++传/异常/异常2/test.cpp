#include <iostream>
using namespace std;

class A{
public:
	int i;
	A(){
		cout << "���캯��" << endl;
		i = 0;
	}
	~A(){
		cout << "��������" << endl;
		i++;
	}
	A(const A &a)
	{
		cout << "�������캯��" << endl;
	}
	void show()
	{
		cout << "show ����" << endl;
		i++;
	}
};
A* test()
{
	return &A();
}
int main5()
{
	A* a = test();
	a->show();
	cout << a->i << endl;
	//	���캯��
	//	��������
	//	show ����		������ռ����ڴ棬�������ǻ��ܵ��ã�ֻҪ�������Ķ�����
	//	- 858993459		�ڴ汻�ͷţ�����i���������ֵ
	system("pause");
	return 0;
}