#include<stdio.h>
int main()
{
	int a,b,c,d,e;
	scanf("%d%d",&a,&b);		//��ȫ����Ҫ�ж�a,b�Ĵ�С 
	e=a; 
	d=b;
	while(e!=0)				//շת����� 
	{
		c=d%e;
		d=e;
		e=c;
}
printf("���Լ����%d\n��С������:%d",d,a*b/d);
 } 
