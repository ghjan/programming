#include<stdio.h>
//�Ӵ�С���� 
int main()
{
	int a[5],i,j;
	for(i=0;i<5;i++)
	scanf("%d",&a[i]);
	for(i=0;i<5;i++)
	for(j=0;j<5-i-1;j++)		//���� j<5-i-1  ����Ϊð��û�ζ�����С�ŵ����   Ҳ����j<5 ��  j<4  ֻ������û�б�Ҫ ��ѭ���˼��� 
	if(a[j]<a[j+1])
	{
		int t=a[j];
		a[j]=a[j+1];
		a[j+1]=t;
	}
	for(j=0;j<5;j++)
	printf("%d",a[j]);	
}
