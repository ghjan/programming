#include<stdio.h>
int main()
{
	printf("������һ��4*4������\n");
	int a[4][4],j,i;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			scanf("%5d",&a[i][j]);
	printf("�������������:\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
			printf("%5d",a[i][j]);
		printf("\n");
	}
	printf("����������������������ǣ�\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<=i;j++)
			printf("%5d",a[i][j]);
		printf("\n");
	}
}
