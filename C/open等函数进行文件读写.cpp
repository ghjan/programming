#include<stdio.h>
int main()
{
	int i;
	char str[2][10];
	char str2[2][10];
	FILE *fp;
	fp=fopen("D:\\dong.dat","a+");
	for(i=0;i<3;i++)
	{
		gets(str[i]);
		fputs(str[i],fp);
		fputs("\n",fp);
	}
//	fclose(fp);
	//�������´�   ������fseek 
//	fp=fopen("D:\\dong.dat","a+");

	fseek(fp,1L,0);	// �ڶ������� ��ʾ ��ǰλ�� ������ʼ��Ϊ׼   ��  1L  ���Ǵӵ�һ���ַ���ʼ�������Ǵ�0 ��ʼ�ġ������ڶ�������  0  �����ļ���ʼ 
	for(i=0;i<3;i++)
	{
		fgets(str2[i],sizeof(str[i]),fp);	
		printf("%s",str2[i]);
	}

 } 
