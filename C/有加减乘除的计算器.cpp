#include<stdio.h>
int main()
{
	float a,b,m;
	char op;
	printf("�����룺");
	scanf("%f%c%f",&a,&op,&b);
	switch(op)
	{
		case '+':m=a+b;break;
		case '-':m=a-b;break;
		case '*':m=a*b;break;
		case '/':m=a/b;break;
		default:printf("�Ӽ��˳����붼������Ҳ��������\n");
 }
 printf("%.2f%c%.2f=%.2f",a,op,b,m);
}
