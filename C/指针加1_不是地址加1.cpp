#include<stdio.h>
int main()
{
	int *p;
	p=(int *)95000;
	char *a;
	a = (char *)96000;
	printf("%d  %d\n",p,p+1);//ע��ָ��� 1 ���ǵ�ַ��1     ��ַ = ���� * 1  ��int �� ���� 4 * 1�� 
	printf("%d  %d",a,a+1);													//��char �� ���� 1*1�� 
 } 
