#include<stdio.h>
union dong{
	int a;
	char b[2];
}u;
int main()
{
	u.b[0] = 'a';
	u.b[1] = 'b';
	printf("%d\n",u.a);
	
	printf("�����Ǿ������\n");
	int x = 'b';
	printf("%d",(x<<8)+'a');
	
}
