#include<stdio.h>
int dong(int i)
{
	int sum;
	if(i==0) sum=1;
	else 
	sum=i*dong(i-1); 
	return sum;
}
int main()
{
	int sum,j;
	printf("����һ������");
	scanf("%d",&j);
	sum=dong(j);
	printf("%d�Ľ׳�Ϊ��%d",j,sum);
}
