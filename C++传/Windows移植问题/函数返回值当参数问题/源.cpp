#include <iostream>
using namespace std;

void test(char &c)//������ò�����д 
{
	cout << "������&  " << c << endl;
}

//�������д,,ͨ�ã���
void test2(const char &c)
{
	cout << "������const char &  " << c << endl;
}

char get()//ע�����ﲻ�Ƿ��ص� ����c    ���Ƿ��صĳ��� 'a'   ��Ϊջ���Ͼͻ��ˣ����ر���û���� 
{
	char c = 'a';
	return c;
}
char &get(char &c)
{
	//char b = 'B';
	char & cc = c;
	return cc;
}
int  main()
{
	//test(get());    //��仰�ǲ���ͨ������ġ�������Ϊ  test  �������ַ����� 
	test2(get());


	//test test2 ����ͨ�����롣�� 
	char c = 'A';
	test(c);		//������Կ��ɴ���ȥһ�� 'A'  �ַ����� 
	test2(c);

	test(get(c));//���Ƿ���ֵ��һ�����ã���಻��ͨ������,,,������÷��صĲ��Ǻ����ڲ������ã����ܱ����٣�GCC��Vs��һ��
	test2(get(c));//���Ƿ���ֵ��һ�����ã���಻��ͨ������

	cin.get();
	return 0;
}