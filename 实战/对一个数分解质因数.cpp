#include<stdio.h>
int main()
{
	int n,i,j;
	printf("���룺");
	scanf("%d",&n);
	printf("n=");
	for(i=2;;i++)
	{
		if(n%i==0&&n!=i) 
		{
		printf("%d*",i);
		n=n/i;
		i--;
	}
		if(n==i) 
		 { 
		 printf("%d",i);
		  break; 
		  }
	}
	 }
