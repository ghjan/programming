#include<stdio.h>
#include<string.h>
char str1[100001],str2[100001];
void add(char a[])									// ������0 1 
{
	strcat(str2,a);
}
int main()
{
	str2[0]='\0';									// ûӴ��һ��  ��һ�ξͲ���ִ��add �е� strcat 
	scanf("%s",str1);
	int i,a=strlen(str1);
	//ʮ������ת��Ϊ2���� 
	//�����ж����2������  �Ƿ��ܹ���3����
	if(a%3==1)											// str1  �� str2�ĳ���  ��4����ϵ  ��  str1   �ĳ�����һ����Ч�� 
	add("00");
	else if(a%3==2)
	add("0");
	for(i=0;i<a;i++)
	{
		switch(str1[i])
		{
			case '0':add("0000");break;
			case '1':add("0001");break;
			case '2':add("0010");break;
			case '3':add("0011");break;
			case '4':add("0100");break;
			case '5':add("0101");break;
			case '6':add("0110");break;
			case '7':add("o111");break;
			case '8':add("1000");break;
			case '9':add("1001");break;
			case 'A':add("1010");break;
			case 'B':add("1011");break;
			case 'C':add("1100");break;
			case 'D':add("1101");break;
			case 'E':add("1110");break;
			case 'F':add("1111");break;
			default:break;
		}
	}
	//���ڽ���2����ת��Ϊ8����
	int b=strlen(str2);
	for(i=0;i<b;i+=3)									// i<b  �������ϸ˼��   �����׳��� 
	{
		str1[i]=(str2[i+2]-'0'+(str2[i+1]-'0')*2+(str2[i]-'0')*4)+'0';			// ��һ��Ҳ�����׳��� ��  ��ϸ˼�� 
		if(i==0&&str1[i]=='0')							//  ������п��ܵ�һλ�����λ��Ϊ0  ��Ϊ�������������00  ����ԭ���ļ���0  ��������λΪ0 
		continue;										//  ���ǲ����� ǰ��λ��Ϊ 0     ��Ϊ���2������ǰ�����5��0    2����3λ ��8����1λ 
		printf("%c",str1[i]);
	}
	return 0;
}
