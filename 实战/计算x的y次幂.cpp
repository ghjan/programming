#include<stdio.h>
#include<math.h>
int main()
{
	float x,y;
	printf("�����룺x y\n");
	scanf("%f%f",&x,&y);
	printf("%.1f^%.1f=%.3f",x,y,pow(x,y));
}
