#include<stdio.h>
void dong(char *a)
{
	*a='2';
}
void dong2(int *a)
{
	*a=1234;
}
int main()
{
	char *a,c;
	int *b,d;
	a=&c;			//ͬ�� 
	b=&d;			//��һ������ȥ��  ָ���������һ����ַ�����ܸĵ�ַ 
	dong(a);
	dong2(b); 
	printf("%c\n%d",*a,*b);
}
