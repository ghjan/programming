#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,j,row,line,**p;//�����Ƕ���һ��˫ָ��   ����  �����û��Լ�����
	printf("�����У�");
	scanf("%d",&row);
	printf("�����У�");
	scanf("%d",&line);
	p=(int **)malloc(row*sizeof(int *));
	if(NULL==p)
	{
		return 0;
	}
	for(i=0;i<line;i++)
	*(p+i)=(int *)malloc(line*sizeof(int));
	if(NULL==p)
	{
		return 0;
	}
	for(i=0;i<row;i++)
	{
		for(j=0;j<line;j++)
		{
			p[i][j]=i+j;
			printf("%5d",p[i][j]);
		}
		printf("\n");
	}
}
