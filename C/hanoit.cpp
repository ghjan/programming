#include<stdio.h>
#include<time.h>
void move(char x,char y)
{
	printf("%c->%c\t",x,y);
}
void hanoit(int n,int a,int b,int c)
{
	if(n==1) move(a,c);			//ʼ����a�Ƶ�c 
	else
	{
		hanoit(n-1,a,c,b);		//��a�ϵ����ӽ���c�Ƶ�b�� if����ǽ������ڶ������ƶ���b��     ��1�� 
			move(a,c);			//ʼ����a->c 
		hanoit(n-1,b,a,c);		//�� b �ϵ����ӽ��� a �Ƶ� c ��                                     ��2��  1��2�Ĳ�����һ����� 
	}
}
int main()
{
	int n=3;
	hanoit(n,'a','b','c');		//��֮  ����û��⡣���������� 
}
