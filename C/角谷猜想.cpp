#include<stdio.h>
int main()
{
	int a,b,c,d;
	printf("����һ����Ȼ����");
	scanf("%d",&a);
	while(a!=1)
	{
	if(a%2==0) a=a/2;
	else a=a*3+1;
	printf("%d\n",a); 
 } 
 printf("�ǹȲ�������%-5d",a);
}
