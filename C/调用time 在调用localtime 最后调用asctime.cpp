#include<stdio.h>
#include<time.h>
int main()
{
	time_t t;
	struct tm *p;
	t=time(NULL);
	p=localtime(&t);
	printf("          ���� �� �� ʱ��     ���\n");
	printf("����ʱ�䣺%s",asctime(p));
 } 
