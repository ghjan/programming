#include<stdio.h> 
void dong(char *a,char *b,char c[])			//Ŀǰ��Ϊ��������ֵ���Զ��庯��ֻ����ָ��huozhe��a[]���� �ı��ַ���ﵽĿ�ģ��������һ��������������ĺ���û��Ӱ�� 
{
	*a='&';
	*b='*';
	c[1]='0';
	c[2]='9';
 } 
 int main()
 {
 	int i;
 	char *c,*d,a[5],b[5],e[5];
 	gets(a);
 	gets(b);
 	gets(e);
 	c=a;
 	d=b;
 	for(c,d;c<=a+2;c++,d++)
 	dong(c,d,e);
 	for(i=0;i<4;i++)				//����Ҳ���԰��ַ���� 
 	printf("%c,%c\n",a[i],b[i]);
 	printf("%s,%s\n",a,b);			//�������԰�ȫ���ַ������ ���������ܻ���ָ�룬��Ϊָ���Ѿ���ĩβ��
 	printf("%s\n",e);
}
