#include<stdio.h>
#include<string.h>
int main()
{
	int a;
	char str1[100],str2[100];
	scanf("%s%s",str1,str2);
	a=strcmp(str1,str2);
	printf("a=%d\n",a);// �ȱȽϵ�һ����  �����һ����==�ڶ�����  �ͼ����Ƚ�   ���������0   ����str1[i]-str2[i] �� �ַ�ASCII��  ���==���� ����Ƿ���ֵ 
}
