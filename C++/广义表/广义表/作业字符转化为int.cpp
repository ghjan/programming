#include<iostream>
using namespace std;

#include<malloc.h>
#include<string.h>
//ֻ���� 8 10 16 ��������
int StrToInt(char *str)
{
	if (*str == ' ' || *str >= '0' && *str <= '9' || *str >= 'a' && *str <= 'f'
		|| *str >= 'A' && *str <= 'F')
	{
		char *p;
		int sum = 0;
		int i = 1;
		while (*str == ' ')
			str++;

		p = str;
		if (*str == '0')
		{
			//����16����
			p = str + 2;
			if (*(str + 1) == 'x' || *(str + 1) == 'X')
			{
				int len = strlen(p) - 1;
				while (len != -1)
				{
					int a = *(p + len);
					if (a >= 'a' && a <= 'f')
						a = a - 'a' + 10;
					else if (a >= 'A' && a <= 'F')
						a = a - 'A' + 10;
					else
						a = a - '0';
					sum += a * i;
					i *= 16;
					len--;
				}
			}
			else
			{
				//����8����
				p = str + 1;
				int len = strlen(p) - 1;
				while (len != -1)
				{
					sum += (*(p + len) - '0') * i;
					i *= 8;
					len--;
				}
			}
		}
		else if (*str != 0)
		{
			//����10����
			int len = strlen(p) - 1;
			while (len != -1)
			{
				sum += (*(p + len) - '0') * i;
				i *= 10;
				len--;
			}
		}
		return sum;
	}
	return -1;
}
int main2()
{
	char *str = "12";
	cout << StrToInt(str) << endl;

	str = "012";
	cout << StrToInt(str) << endl;

	str = "0x12";
	cout << StrToInt(str) << endl;

	str = "0xABC";
	cout << StrToInt(str) << endl;

	system("pause");
	return 0;
}
// "67890";
// "678986567898767985"
// "0x67Aasf"
// "0567890";
// "8aadf";
// "+2345"
// "-345"
// "     324324";
// "  324   sa";
///"asdfasd"=> 0
