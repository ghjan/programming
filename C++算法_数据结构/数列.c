#include"maopaos.h" 
#include<stdio.h>
#include<time.h> 
int main()
{
	int n,k,a[10000];
	srand(time(NULL));
	printf("����Ҫ���м�����:");
	scanf("%d",&n);
	for(k=0;k<n;k++)
	{
		a[k]=rand()*100/32767;
	}
	small(a,n);
	for(k=0;k<n;k++)
	{
	if(k%10==0&&(k!=0))
	printf("\n");
	printf("%d\t",a[k]);
}
}
