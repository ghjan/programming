#include<stdio.h>
int main()
{
	double j=100.0,sum=100.0;
	int i;
	for(i=1;i<19;i++)
	{
		j=j/2.0;
		sum+=j;
	}
	printf("һ����·�̣�%f\n��ʮ�η����ĸ߶ȣ�%f",sum,j/2);
}
