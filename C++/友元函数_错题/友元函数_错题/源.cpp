#include <iostream>
using namespace std;

int c = 200;
class A
{
	int a;
public:
	static int b;
	void test1()
	{
		this->a = 10;
	}
	friend void test2()			// һ�����������У�ʵ�������棬������Ҳ��
	{
		//this->a = 20;				 ע��1�� ��Ԫ������û��thisָ��
		cout << A::b << endl;	//	 ע��2�� ����������о�̬��ԱҲ����ʹ��A::������   ����b����private
		cout << c << endl;//ȫ�ֿ��Է���
	}
};
int A::b = 20;

void test2();		//��������������������������Ŀ��ȷ�𰸾Ͳ������ˣ���û��test2����������������

int main()
{
	test2();
	system("pause");
}