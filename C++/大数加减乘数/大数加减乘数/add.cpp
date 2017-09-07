#include "common.h"
//string add(char* str1, char* str2)
//{
//	string res = "";//�������ս��
//	int n1 = strlen(str1);
//	int n2 = strlen(str2);
//	int n = n1 > n2 ? n1 : n2;
//	char *str3 = new char[n+1];
//	memset(str3, '0', n);
//	str3[n] = '\0';
//	int m = n;
//	while (--n1 >= 0)
//		str3[--m] = str1[n1];
//	while (--n2 >= 0)
//	{
//		str3[--n] += str2[n2] - '0';
//		if (str3[n] > '9')
//		{
//			str3[n] = (str3[n] - '0') % 10 + '0';
//			if (n == 0)
//				res = "1";
//			else
//				str3[n - 1] += 1;
//		}
//	}
//	return res + str3;
//}
//������Ҫ֪��str1��str2�ĸ�����  �������Ч�ʱ������
string add(char* str1, char* str2)
{
	string res = "";//�������ս��
	int n1 = strlen(str1);
	int n2 = strlen(str2);
	//����Ҫ��֤str1 ���ڵ��� str2
	if (n1 < n2)
	{
		char* temp = str1;
		str1 = str2;
		str2 = temp;
		n1 += n2;
		n2 = n1 - n2;
		n1 -= n2;
	}
	while (--n1 >= 0)
	{
		if (--n2 >= 0)
			str1[n1] = str1[n1] + str2[n2] - '0';
		if (str1[n1] > '9' && n1!= 0)
		{
			str1[n1 - 1] += 1;
			str1[n1] = (str1[n1] - '0') % 10 + '0';
		}
	}
	if (str1[0] > '9')
	{
		str1[0] = (str1[0] - '0') % 10 + '0';
		res = "1";
	}
	return res + str1;
}