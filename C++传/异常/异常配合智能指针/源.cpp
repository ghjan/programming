#include <iostream>
#include <vld.h>
using namespace std;

class Test
{
public:
	Test() :p(new int(5)), q(new double(15.0))
	{
		cout << "test()" << endl;
		throw exception("����ʧ��");//���׳��쳣֮��Test����಻�ᱻ�����ˣ���Ϊ������û�й����
	}
	~Test()
	{
		cout << "~Test()" << endl;
	}
private:
	auto_ptr<int> p;	//ʹ������ָ�빹��֮����Զ�������������׳��쳣ֻ������಻�������������������������ĳ�Ա�ͻ��඼�ǿ���������
	auto_ptr<double> q;	//��ʵʹ���Զ������Ҳ���ԣ������Զ���һ������������������������û����������������ʹ������ָ��			
};

class Test2
{
public:
	Test2() :p(new int(5)), q(new double(15.0))
	{
		cout << "test()" << endl;
		throw exception("����ʧ��");//���׳��쳣֮��Test����಻�ᱻ�����ˣ���Ϊ������û�й����
	}
	~Test2()
	{
		cout << "~Test()" << endl;
	}
private:
	int* p;
	double* q;
};

int main()
{
	try
	{
		Test t;
	}
	catch (const exception &err)
	{
		cout << err.what() << endl;
	}
	//����û������й©
	//����Visual Leak Detector detected 2 memory leaks.
	try
	{
		Test2 t;
	}
	catch (const exception &err)
	{
		cout << err.what() << endl;
	}
}