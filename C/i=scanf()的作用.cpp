#include<stdio.h>
int main()
{
	int a,b,i,c;
	i=scanf("%d%d%c",&a,&b,&c);						/*����4587 1246dgdn45����*/ 
	printf("%d\t%d\t%c",a,b,c);
	printf("\n%-5d",i); 							/*�������a,b,c���ɹ�����ĸ���*/ 
 } 
/*
4587 1246dgdn45
4587 1246 d
3
-------------------------------
123
123
123     123

3
*/ 
