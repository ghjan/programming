#include<stdio.h>
int dong(int a,int b)
{
	return b?dong(b,a%b):a;		//���ù�a��b˭����Ϊ����b��,�ݹ�һ�ξͰ�ab��λ�ӻ��� 
}
int main()
{
	int a,b;
	printf("������������(�ö��Ÿ���)��");
	scanf("%d,%d",&a,&b); 
	int x=dong(a,b);
	printf("���Լ���ǣ�%d",x);
 } 
