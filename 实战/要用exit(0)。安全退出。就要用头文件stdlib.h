#include<stdio.h>
#include<math.h>
#include<stdlib.h> 
int main()
{
	int sum;
	printf("����һ����Ȼ������ֻ�뿴һ����ϣ���������Ȼ���󰴡��ո񡯣�\n");
	scanf("%d",&sum);
	int a,b,c,d;
	for(a=0;a<=sqrt(sum);a++)
	for(b=0;b<=sqrt(sum);b++)
	for(c=0;c<=sqrt(sum);c++)
	for(d=0;d<=sqrt(sum);d++)
		if(sum==a*a+b*b+c*c+d*d)
		{
		printf("%d=%d^2+%d^2+%d^2+%d^2\n",sum,d,c,b,a);
		exit(0); 
}
}
