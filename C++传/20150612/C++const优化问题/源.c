#include<stdio.h>
int main()
{
	const int a = 10;

	*((int *)&a) = 1000;

	printf("%d", a);//c���ԣ������͡���ֻҪ�Լ��롣const��ֵ�Լ����Ը�

	getchar();
	return 0;
}