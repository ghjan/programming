//c++�е�����
#include<stdio.h>
int main()
{
	int a = 4;
	int &b = a;//�� a ȡ����  Ϊ  b   ע�� ���������� Ӧ�ú� a ������һ�� 
	printf("%d  %d\n",a,b);
	
	b = 5;
	printf("%d  %d\n",a,b);
	
	printf("0x%x  0x%x\n",&a,&b);
		 
 } 
