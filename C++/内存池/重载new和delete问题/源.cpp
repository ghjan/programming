#define _CRT_SECURE_NO_WARNINGS
#include <cstddef> 
#include <fstream>
#include <iostream>
#include <vld.h>
using namespace std;

class Framis
{
public:
	int a;
	int b;
	static char *str;
	Framis():a(2),b(3){ cout << "����\n"; }
	~Framis(){ cout << "����"; }
	void* operator new(size_t size) throw(bad_alloc)
	{
		str = new char[10];
		strcpy(str, "hello");
		//char *a = new char[4];//������size����Ȼ�������ڴ�Ͳ��������ʲ�������⣬����delete��ʱ����ֻnew��4���ֽڣ��ͷ�ȴ�ͷ���8������������
		char *a = new char[size];
		return a;//������뷵��һ����ַ����Ȼ��������û�е�ַ
	}
	void operator delete(void* f)
	{
		delete []str;
		delete f;
	}
};
char* Framis::str = NULL;
class A
{
};

int main()
{
	Framis *f = new Framis;
	cout << (void *)f << endl;
	cout << f->a << endl;
	cout << f->b << endl;
	delete f;
	return 0;
}