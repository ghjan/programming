#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int test10()
{
	int ival;
	double d1,d2;
	char s1;
	char s2;

	istringstream input_istring("520a5.2a52.0");
	input_istring >> ival >> s1 >> d1 >> s2 >> d2;//��֪��Ϊɶ�������ַ�����ֻ��int double float char�������ܰ�С���������Ҿ;��ò�����
	cout << ival << endl;
	cout << s1 << endl;
	cout << d1 << endl;
	cout << s2 << endl;
	cout << d2 << endl;
	return 0;
}
int test11()
{
	double d1, d2;
	string s;
	char x;
	getline(cin , s);
	istringstream iss1(s);
	iss1 >> d1 >> x >> d2;//x���ȡһ���ַ����������ո�
	cout << d1 + d2 << endl;
	cout << x << endl;
	/*
	43.1 + 12.45
	55.55
	*/
	return 0;
}