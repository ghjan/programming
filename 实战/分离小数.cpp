#include<stdio.h>
#include<math.h>
int main()
{
	double a,f,i;
	scanf("%lf",&a);
	f=modf(a,&i);		//i��f������double�ͣ�a������float �� 
	printf("%f=%f+%f",a,i,f);
 } 
