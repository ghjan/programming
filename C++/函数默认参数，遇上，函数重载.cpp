//����Ĭ�ϲ��������ϣ���������
#include<stdio.h>
int func(int a,int b,int c =1)//��Ĭ�ϲ����ĺ��� 
{
	return a+b+c; 
}
int func(int a,int b)
{
	return a+b;
}
int main()
{
	int a;
	//a = func(1,2);  �ᱨ�� [Error] call of overloaded 'func(int, int)' is ambiguous  ����ԭ�򣺴��ڶ����� 
	
	printf("%d\n",a);
 }
 //һ��  �������� �� ����Ĭ�ϲ��� ��Ҫͬʱд 
