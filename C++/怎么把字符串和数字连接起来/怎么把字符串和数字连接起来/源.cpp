#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;

//��һ��C����ת��(��ǰһֱϲ����  sprintf ����ǿ��)
void test()
{
	char *s = "dong";
	int a = 52;
	float b = .1314;
	char *buf = new char[strlen(s) + sizeof(a) + 1];
	sprintf(buf, "%s%d%.4f", s, a, b);
	printf("%s\n", buf);
}
//��C��C++���
void test1()
{
	string s = "dong";
	int a = 520;
	char *buf = new char[10];//2147483647 int���ֵ
	_itoa(a, buf, 10);		//itoa��Ȼ����ת��Ϊ���ֽ��ƣ�����ע�ⲻ����float����double
	s += buf;
	cout << s << "\t";
	_itoa(a, buf, 16);
	s += buf;
	cout << s << endl;
}
//��C++���
void test2()
{
	string s = "������";
	int a = 52;
	double b = .1314;
	ostringstream oss;
	oss << s << a << b << endl;
	s = oss.str();
	cout << s << endl;
}
int main()
{
	test();
	test1();
	test2();
	return 0;
}
/*
dong520.1314
dong520 dong520208
������520.1314
*/