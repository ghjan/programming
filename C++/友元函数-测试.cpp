#include <iostream>
using namespace std;

class A
{
private:
	int a;
	static int b;
public:
	static int c;
	void test1()
	{
		this->a = 10;
	}
	friend void test2()			// һ�����������У�ʵ�������棬������Ҳ��
	{
		//this->a = 10;				 ע��1�� ��Ԫ������û��thisָ��
		cout << A::b << endl;	//	 ע��2�� ����������о�̬��ԱҲ����ʹ��A::������   ����b����private
		cout << A::c << endl;
	}
};
int A::b = 20;
int A::c = 30;

void test2();		//��������������������������Ŀ��ȷ�𰸾Ͳ������ˣ���û��test2����������������

int main()
{
	test2();
}
