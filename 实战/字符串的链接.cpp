#include<stdio.h>
#include<string.h>
void dong(char s[],char t[])
{
	char *a,*b,c[330];
	a=s;
	b=t;
	int i=0;
	for(;*a!='\0';a++)
	{
	c[i]=*a;		//������ܰ�c[i]����ָ��*c����������Ϊ*c=*a;����� 
	i++;
}
	for(;*b!='\0';b++)
	{
		c[i]=*b;
		i++;
	}
	c[i]='\0';
	printf("%s\n",c);
}
int main()
{
	char s[20],t[20],c;
	scanf("%s",s);
	c=getchar();
	scanf("%s",t);
	dong(s,t);
}
