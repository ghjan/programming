#include<stdio.h>
int main()
{
	int t,a,b,c,d;
	printf("������������a b\n");
	scanf("%d%d",&a,&b);
	c=a,d=b;
	while(b!=0)
	{
		t=b;
		b=a%b;
		a=t;
	}
	printf("���Լ����%d\n��󹫱�����%d",a,c*d/a);
 } 
