#include<stdio.h>
#include<stdlib.h>
int main()
{
	int (*p)[3],i,j,n;//n ��  3 �� ��ָ������     �����Ͳ������û����� ��  ��Ȼdev C++�����ַ����������ж����û�����   ���ܶ����������    
	scanf("%d",&n);
	p=(int (*)[3])malloc(n*3*sizeof(int));
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
		{
			p[i][j]=i+j;
			printf("%5d",p[i][j]);
		}
		printf("\n"); 
	}
}
