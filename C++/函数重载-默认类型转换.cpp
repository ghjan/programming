//����Ĭ�ϲ��������ϣ���������
#include<stdio.h>
int func(int a,int b,int c) 
{
	return a+b+c; 
}
int func(int a,int b)
{
	printf("Ĭ�ϰ� �ַ� ��A��ת��Ϊ ���� 65 \n"); 
	return a+b;
}
char func(int a,char b,int c,int d)
{
	printf("Ĭ�ϰ�  ���� 49 ת��Ϊ �ַ� ��1�� \n");
	return b;
}
int main()
{
	int a;
	
	a = func('A',0);//Ĭ�ϰ� �ַ� ��A��ת��Ϊ ���� 65 
	printf("%d\n",a);
	
	
	int  b = func(0,49,0,0);//Ĭ�ϰ�  ���� 49 ת��Ϊ �ַ� ��1�� 
	printf("%c\n",b);
 }
 
