#include<stdio.h>
int main()
{
	char a[20],c;
	scanf("%s",a);
	fflush(stdin);/*�о���c=getchar()һ����Ч��*/ 
	c=getchar();
	printf("%s  %c",a,c);
 } 
