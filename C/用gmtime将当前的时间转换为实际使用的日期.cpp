#include<stdio.h>
#include<time.h>
int main()
{
	printf("����ʱ�䣺\n");
	time_t t;
	struct tm *p;
	t=time(NULL);
	p=gmtime(&t);
	printf("%d��%02d��%02d��\t",(1900+p->tm_year),(1+p->tm_mon),p->tm_mday);
	printf("����%d\n",p->tm_wday);
	printf("%d:%d:%d",(8+p->tm_hour),p->tm_min,p->tm_sec);
}
