#include<stdio.h>
#include<math.h>
int main()
{
	int i,age,a,b,c[10],d[10]={0};	//d[10]={0}��������ȫ��0 
	for(age=11;age<100;age++)
	{
		a=pow(age,3);
		b=pow(age,4);
		if(a>=1000&&b>=100000)
		{
			for(i=0;i<4;i++)
			{
				c[i]=a%10;
				a=a/10;
			}
			for(;i<10;i++)
			{
				c[i]=b%10;
				b=b/10;
			}
			for(i=0;i<10;i++)
			d[c[i]]++;			//˫���飬�ж�c[i]���Ƿ����ظ����� 
			for(i=0;i<10;i++)
			if(d[i]>1)
			break;
			if(i==10)
			printf("����%d��",age);
		}
	 } 
}
