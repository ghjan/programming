#include<stdio.h>

int main()
{
	int b = -20;
	unsigned int a = 6;
	(b + a >-1 ) ? puts(">6") : puts("<6");		//�����������  ��Ҳ��������  ��֪��Ϊɶ 
	(b+a >0)?puts(">6") : puts("<6");
	int c=a+b;
	unsigned int d=a+b;
	printf("\n%d   %d",c,d); 
	return 0;
}
