#include<stdio.h>
int main()
{
	int a,b,suma,sumb,i;
	for(a=2;a<1500;a++)
	{
	for(b=1;b<a;b++)
	{
		suma=sumb=0;
	for(i=1;i<=a/2;i++)
		if(a%i==0)
			suma+=i;
	for(i=1;i<=b/2;i++)
		if(b%i==0)
		sumb+=i;
			if(suma==b&&sumb==a)
			printf("%d,%d\n",a,b);		//�Լ����ģ��о���ȱ�ݣ��㷨�����ʣ���ʱ�ܾ� 
		}
	}
}
