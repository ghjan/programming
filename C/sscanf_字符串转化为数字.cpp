//ʮ����ת��Ϊʮ������  8���� 
#include<stdio.h>
int main()
{
	int i;
	char str[40];
		scanf("%s", str);
		sscanf(str,"%d", &i);
		printf("ʮ���ƣ�%d\nʮ�����ƣ�0x%x\n�˽��ƣ�0%o", i, i, i);
}
