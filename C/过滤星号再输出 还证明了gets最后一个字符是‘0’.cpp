#include<stdio.h>
int main()
{
	char a[100];
	int i;
	gets(a);		//������ӳ��˵����gets�����Ļ��з��ĳ���'\0' 
	for(i=0;;i++)
	{
		if(a[i]!='*')
		printf("%c",a[i]);
		if(a[i]=='\0')	//���ſ��� 
		break;
	}
 } 
