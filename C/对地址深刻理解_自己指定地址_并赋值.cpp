#include<stdio.h>
int main()
{
	int b=10;
	int c=1,d=2;
	
	int *p;
	p=&c;
	
	unsigned long *q;
	q=(unsigned long *)0x10000;		// ָ����ַ Ϊ 100000    ��������ָ���ĵ�ַ�з�Χ  Ӧ������Щ��ַ ϵͳռ���� �����Լ�û��Ȩ�޷���  
	*q=123;					// �Ե�ַָ������ݸ�ֵ  123 	�൱��	(*(int *)100000)=1  һ������ 
	printf("%d\t%d\n%d\t%d\n%d\t%d\n%d\t%d\n%d\t%x\n",b,&b,c,&c,d,&d,*p,p,*q,q);	
 } 
