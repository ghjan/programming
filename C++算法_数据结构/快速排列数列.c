#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"kuaisu.h"
#define N 100
int main()
{
	int a[N],i;
	srand(time(NULL));
	for(i=0;i<N;i++)
	{
		a[i]=rand()*N/32767;
	}
	printf("����ǰ\n");
	for(i=0;i<N;i++) printf("%d\t",a[i]);
	printf("\n�����\n");
	kuaisu(a,N);
	for(i=0;i<N;i++)
	{
	printf("%d\t",a[i]);
 } 
}
