#include<stdio.h>
int main() 
{
	int i,a,b,c,d=0;
	scanf("%d,%d",&a,&b);
	if(a<b)
	{
		c=a;
		a=b;
		b=c;
	}
	for(i=b;i>0;i--)
	{
		if(a%i==0&&b%i==0)
		{
			d=1;
			printf("���Լ����%d\n��󹫱�����%d",i,a*b/i);
		}
		if(d==1)
		{
			break;
		}
	}
}
