#include<stdio.h>
int main()
{
	char str[100];
	// %[^\n] ����˼����  ֱ������س��ַ�  �Ž��� 
	scanf("%[^\n]",str);//ֱ������س�������ȡ�Ž�������Ȼ���ܳ���a����Ĵ�С������������������gets(str)Ч��һ����
	printf("%s\n",str);
	getchar();			// ������������Ļس��� ��Ȼ���������س� 
	char str2[100];
	gets(str2);
	puts(str2);
}
