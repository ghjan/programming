#include<iostream>

using namespace std;

//p pp ppp ����ָ�� 

int main1()
{
	//* ���� pointer to
	char a = 'a';
	char* const p = &a;//p�� ���� ָ�� �ַ��� 
	
	const char* pp = "hello";//pp ָ�� �ַ��� ���� 
	//char *pp="dosjgd";
	
	//ͬ����ΪC++����û��const*�������������constֻ������ǰ������͡� char const *   == const char *    const ���ڻ�����������ǰ��û���κι�ϵ 
	char const * ppp = "dong";//ppp ָ��  �ַ��� ����  
	
	cout<<*p<<endl;
	cout<<*pp<<endl;
	cout<<*ppp<<endl;
	
}
int main()
{
	char a = 'a';
	char b = 'b';
	char* const p = &a;//p�� ���� ָ�� �ַ��� 
	//p = &b;   //��p��ָ���ܸı�
	*p = 'p';	//�ԣ�pָ���ֵ���Ըı� 
	cout<<*p<<endl;
	
	
	const char* pp = &a;//pp ָ�� �ַ��� ���� 
	pp = &b;//�ԣ�p��ָ����Ըı� 
	//*pp = 'p';//��pָ���ֵ�����Ըı�  
	cout<<*pp<<endl;
	
	
}
