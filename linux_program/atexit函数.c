#include <stdio.h>
#include <stdlib.h>

void myFunc1(void)
{
	printf("myFunc1\n");
}
void myFunc2(void)
{
	printf("myFunc2\n");
}

int main()
{
	atexit(myFunc1);
	
	printf("main111\n");
	
	atexit(myFunc2);//���ᱻִ�У�ֻ��ִ�е�ʱ�����ں���
	
	return 0;
	exit(0);
	
	printf("main222\n");
}
//�����
// main
// myFunc2
// myFunc1
//��atexit()�ĺ�������ִ��