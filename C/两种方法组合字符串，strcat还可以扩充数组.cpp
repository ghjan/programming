#include<stdio.h>
#include<string.h>
int main()
{
	char a[]="123";
	char p[9]="/dev/led";
	strcat(p,a);
	printf("%s",p);
	
	printf("\n%c\n",p[10]);//ͻȻ����strcat �����������ַ������С  ����p[]������û�� p[10]�� 
	
	int b = 321; 
	char q[20];
	sprintf(q,"/dev/led%d",b);//sprintf��strcatǿ�󣬣��������԰� ���� �� �ַ��� �ϲ� 
	printf("%s\n",q);
	
	int c = 123;
	char d[30];
	sprintf(d,"321    \n    %d",c);//�������ַ��� ���տ� ���س���  ������һ��ת��Ϊһ�� �ַ�����     ����sprintf�ǳ�ǿ�� 
	printf("%s",d);
 } 
