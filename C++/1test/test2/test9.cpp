#include <iostream>
#include <stack>
#include <set>

using namespace std;

int test9()
{
	set<int> s;
	int zero = 2;
	char ch;
	int sum = 0;
	while (zero > 0)
	{
		ch = getchar();
		if (sum == 0 && ch == '0')
		{
			zero--;
		}
		else if (ch >= '0' && ch <= '9')
		{
			sum = sum * 10 + ch - '0';
		}
		else if (sum && ch == ' ')
		{
			s.insert(sum);
			sum = 0;
		}
	}
	set<int>::iterator it = s.begin();
	for (; it != s.end(); ++it)
	{
		cout << *it << " ";
	}
	
	return 0;
}
/*
��@cipher&�� ��ʾ�ַ���cipher��ʹ�÷���1���ܹ���
��# cipher^�� ��ʾ�ַ���cipher��ʹ�÷���2���ܹ���
��$cipher%�� ��ʾ�ַ���cipher��ʹ�÷���3���ܹ���
��#c@hip&er^�� ����ϵļ��ܷ�ʽ ��ʾ ��hip��������1���ܹ��� ����ǰ���ִ��� ��c���� ��er��ƴ�Ӻ���ִ��Ǳ�����2���ܺ��
*/
int test10()
{
	stack<char> s;
	char ch;
	while (cin >> ch)
	{
		if (ch == '@' || ch == '#' || ch == '$')
			s.push(ch);
		else if (ch == '&')
		{
			if (s.top() == '@')
				s.pop();
			else
			{
				cout << "false";
				return 0;
			}
		}
		else if (ch == '^')
		{
			if (s.top() == '#')
				s.pop();
			else
			{
				cout << "false";
				return 0;
			}
		}
		else if (ch == '%')
		{
			if (s.top() == '$')
				s.pop();
			else
			{
				cout << "false";
				return 0;
			}
		}
	}
	cout << "true";

	return 0;
}