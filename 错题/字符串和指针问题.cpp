#include <iostream>
#include <cstring> 
using namespace std;

void testFunc()
{
	char *x = "hello dong nice to meet you";
	char(*p)[5] = (char(*)[5])x;
	puts(p[1]);
	for (int i = 0; i < 5; i++)
	{
		cout << *p + i << endl;
	}
}

typedef char(*AP)[5];

AP foo(char *p)
{
	for (int i = 0; i < 3; i++)
	{
		p[strlen(p)] = 'A';
	}
	return (AP)p + 1;
}

int main()
{
	//testFunc();
	char s[] = "FROG\0SEAL\0LION\0LAMB";

	/*
	AP test1 = foo(s);//SEALA LIONALAMB		���ص���һ��ָ�����飬���ָ�벽��Ϊ5
	char *test2 = test1[1];//LIONALAMB		���ԡ�1���ƶ�����5���ֽ�
	char *test3 = test2 + 2;//ONALAMB		��������char* �����ƶ�����2���ֽ�
	*/

	puts(foo(s)[1] + 2);
}

