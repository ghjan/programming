#include<stdio.h>
#include<stdlib.h>
int  add(int a,int b)
{
	int wei=0,jinwei=0;
	while(b!=0)
	{
		wei=a^b;		//wei ���мӷ�����  �� �ڶ�������  ��û�н�λ 
		jinwei=(a&b)<<1;//jinwei <<1 ʵ�ֽ�λ 
		a=wei;
		b=jinwei;
	}				//ÿ����һ�� jinwei������һ��0 ���� wei�ֽ�����һ������  jinwei�԰�λ������Ϊ0 �ĸ���Խ��Խ�� 
	return wei;
}
int aadd(int a,int b)	//Ϊ��֤�� ÿ�� ����������ֵ  ���  ��ԭʽ��� 
{
	int wei,jinwei;
	wei=a^b;
	jinwei=(a&b)<<1
	;
	return wei+jinwei;
 }
 int aaadd(int a,int b)//too1 
 {
 	return a+b;
 }
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d+%d=%d\n",a,b,add(a,b));
	printf("%d+%d=%d\n",a,b,aadd(a,b));	
	printf("%d+%d=%d\n",a,b,aaadd(a,b));
}





 
