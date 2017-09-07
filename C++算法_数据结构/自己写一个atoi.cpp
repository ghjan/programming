#include <iostream>
#include <cstdlib> 
using namespace std;

/* ע�⣺1.��������ֵ����Ҫ����״̬g_status
		 2.�жϲ����Ƿ�Ϊ�գ������������Ƿ�Ϊ��
		 3.�ж�������
		 4.��ת��Ϊ������ʱ���ж�ÿһλ�Ƿ���0 - 9
		 5.�ж���û��Խ�磨����Խ�磩 */ 

enum Status{value = 0,invalue};
int g_status = invalue;

int my_atoi(char *str)
{
	if(!str | !*str)
		return 0;
	long long sum = 0;
	bool fu = false;
	if(*str == '-')
	{
		fu = true;
		++str;
	}
	else if(*str == '+')
		++str;
	if(*str == 0)
		return 0;
	while(*str)
	{
		if(*str >= '0' && *str <= '9')
		{
			sum = sum * 10 + *str - '0';
			++str;
			if((fu && sum > 0x80000000) || (!fu && sum > 0x7fffffff))
				return 0;
		}
		else
			return 0;
	}
	if(fu)
		sum = 0 - sum;
	g_status = value;
	return int(sum);
}

int main()
{
	char *str1 = "+123";
	char *str2 = "-123";
	char *str3 = "+";
	
	cout<<my_atoi(str1) + 1<<endl;
	cout<<atoi(str1) + 1<<endl;

	cout<<my_atoi(str2) + 1<<endl;
	cout<<atoi(str2) + 1<<endl;

	cout<<my_atoi(str3) + 1<<endl;
	cout<<atoi(str3) + 1<<endl;
}

