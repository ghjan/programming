#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int test1()
{
	//1
	string str1 = "56";
	cout << typeid(str1.c_str()).name() << endl;//char const *
	char *s1 = (char *)str1.c_str();
	*s1 = '9';
	cout << str1 << endl;//96		�޸�char *		string	ҲҪ���ű�

	//2
	string str2 = "99";
	const char *s2 = str2.c_str();
	str2 = "hello";
	cout << s2 << endl;//hello		�޸�string    const char * ҲҪ���ű�  
	//s2���ָ�������������,��Ϊs��������,�����ݱ�����,����const char * ���ݱ��޸ģ�������һ������

	//��һ�����û�취������������������const�ģ����Ҫǿת��˵�����Լ�֪���Լ��ڸ�ʲô
	//���ڵڶ���������ǿ�����strcpy����ֹ����
	char s3[100];
	strcpy_s(s3, str2.c_str());//�����Ų������,c_str()���ص���һ����ʱָ��,���ܶ�����в���

	return 0;
}
int main()
{
	string s = "7";
	char * ss = "hello";
	cout << s + ss << endl;

	//Ϊ��ʵ��java�е�  string s = 4 + "";//C++�в���������
	char s2 = '0' + 4;
	cout << s2 << endl;

	system("pause");
	return 0;
}