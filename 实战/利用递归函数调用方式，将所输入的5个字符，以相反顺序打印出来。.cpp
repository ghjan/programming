#include<stdio.h>
void dong(int i)
{
	char c;
	if(i==1)
	{
		c=getchar();
		putchar(c);
	}
	else
	{
		c=getchar();
		dong(i-1);
		putchar(c);
	}
}
int main()
{ 
	int i;
	printf("��׼�����뼸���ַ���");
	scanf("%d",&i);
	dong(i+1);
	printf("��׼�����뼸���ַ���");
 } 
