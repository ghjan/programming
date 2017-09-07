#define D_SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

//string ==>  char*
void test1()
{
	string str = "abc";
	char* p;
	p = (char *)str.c_str();
	cout << "str.c_str() = " << str.c_str() << endl;
	cout << "p = " << p << endl;

	*p = 'A';//��Ϊָ��ͬһƬ�ڴ棬�������涼�����Abc
	cout << "--------------" << endl;
	cout << "str.c_str() = " << str.c_str() << endl;
	cout << "p = " << p << endl;
}
//const char* ==> string    ��ʵ string s = "dong"����const char* ==> string
void test2()
{
	string str1 = "abc";
	string str2;
	str2 = str1.c_str();

	cout << "str1 = " << str1 << "     str2 = " << str2 << endl;
}
//string �Ӵ�
void test3()
{
	string str1 = "123456789";
	string str2;
	string str3;

	//���Լ򵥵���һ�£�������ַ���ѭ��
	while (1)
	{
		str2 = str1.substr(0, 8);
		str3 = str1.substr(8, 1);
		str1 = str3 + str2;
		cout << str1 << endl;
		Sleep(1000);
	}
}
//�ַ����Ĳ���
void test4()
{
	string str = "dong | hello | nice | to | meet | you | dong | yes | dong";
	int index = str.find("ng", 0);//����λ�ÿ�ʼ����		û�ҵ�����-1
	cout << index << endl;// 2

	//��dong���ֵĴ���
	int count = 0;
	index = str.find("dong", 0);
	while (index!=string::npos)//���û�ҵ�������һ��  nposȡֵ��-1
	{
		count++;
		index = str.find("dong", index+1);
	}
	cout << "�����ֵĴ����ǣ�" << count << endl;
}
//�ַ������滻
void test5()
{
	string str = "dong | hello | nice | to | meet | you | dong | yes | dong";
	int index = str.find("dong", 0);
	while (index != string::npos)//���û�ҵ�������һ��  nposȡֵ��-1
	{
		str.replace(index, 4, "����");//��dong  ȫ���滻������		// 1.��ʼλ�� 2.����滻���ٸ��ַ�  3.�´�
		index = str.find("dong", index + 1);
	}
	cout << str << endl;
}
//ɾ��
void test6()
{
	string str = "123456789";
	str = str.erase(0, 3);	//��0λ�ÿ�ʼɾ��3���ַ�
	cout << str << endl;//456789
}
//ɾ��2
void test7()
{
	string str = "dong | hello | nice | to | meet | you | dong | yes | dong";
	int index = str.find("dong", 0);
	while (index != -1)
	{
		str.erase(index, 6);
		index = str.find("dong", index + 1);
	}
	cout << str << endl;
}
//����
void test8()
{
	string str = "hello dong";
	str.insert(5, " chen ming");//�� 4  ����  5 ǰ�� ����
	cout << str << endl;
}
int test9();
int test10();
int test11();

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	//test8();
	//test9();
	//test10();
	test11();

	system("pause");
	return 0;
}