#include<stdio.h>
typedef struct
{
	int a;
	int b;
	int c;
	int d;
 }str1;
typedef struct
{
	char a;
	char b;
	char c;
	char d;
}str2;
typedef struct
{
	unsigned int a;
	unsigned int b;
	unsigned int c;
	unsigned int d;
 }str3;
int main()
{
	//��ϸ������Ľ��   �᲻���������һ��   ֻ�����ýṹ���һ����ַ  �Ժ�Ķ����й��ɵ� 
	
	str1 *dong=(str1 *)9700;
	printf("%d   %d   %d   %d\n",&dong->a,&dong->b,&dong->c,&dong->d);
	
	str2 *dong2=(str2 *)9800;
	printf("%d   %d   %d   %d\n",&dong2->a,&dong2->b,&dong2->c,&dong2->d);
	
	str3 *dong3=(str3 *)9900;
	printf("%d   %d   %d   %d\n",&dong3->a,&dong3->b,&dong3->c,&dong3->d);
}
