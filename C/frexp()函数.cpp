#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	float x,y;
	int p;
	printf("����ʵ����");
	scanf("%f",&y);
	x=frexp(y,&p);		/*��ȻpΪһ��int��ָ�룬�����治��д��*p        */ 
	printf("%.2f��β����%.2f,ָ����%d\n",y,x,p);
	printf("%.2f=%.2f*2^%d\n",y,x,p);
 } 
