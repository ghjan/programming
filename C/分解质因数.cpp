#include<stdio.h>
int main()
{
	int n,i=2;
	printf("������һ����:");
	scanf("%d",&n);
	printf("�����Ƕ�ô���£�%d=",n);
	for(;i<=n;i++)
	{
	while(n!=i)
	{
		if(n%i==0)
		{
		printf("%d*",i);
		n/=i;
		}
		else
		break; 
	}
	} 
	printf("%d",n);
}
