#include<iostream>
#include <stack>
#include <cstring>
using namespace std;

int priority(char c)
{
	switch (c)
	{
	case '+':return 1;
	case '-':return 1;
	case '*':return 2;
	case '/':return 2;
	case '^':return 3;
	case '%':return 3;
	case '('://���������ֻΪ������ӽ�׳�������ǲ�׽������
	case ')':
	default: return 0;
	}
}

void error()
{
	cout << "��ı��ʽ������,����ϸ���" << endl;
}

bool change(char s1[], char* &s2)
{
	stack<char> stack;
	char ch = s1[0];
	int i = 0;//��¼s1���ڵ�λ�� 
	int j = 0;//��¼s2��λ�� 

	while (ch != '\0')
	{
		if (ch >= '0'&&ch <= '9' || ch == '.' || ch == ' ')
		{
			s2[j++] = ch;
			ch = s1[++i];
		}
		else if (ch == '(')
		{
			stack.push(ch);
			ch = s1[++i];
		}
		else if (ch == ')')
		{
			if (stack.empty())
			{
				error();
				return false;
			}
			while ((ch = stack.top()) != '(')
			{
				s2[j++] = ch;
				stack.pop();
			}
			if (ch != '(')
			{
				error();
				return false;
			}

			stack.pop();
			ch = s1[++i];
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%')
		{
			if (!stack.empty())
			{
				char top = stack.top();
				//������ջ�������ȼ�С�������ȼ����Ԫ������ 
				//���ջ�е����ȼ��ȵ�ǰ����ô�����ջ�е�Ԫ��  ֱ��ջ������Ԫ�ض�����С 
				while (priority(top) >= priority(ch))//���ѭ���б�Ҫ����Ϊ��ǰԪ��Ҫ��ջ���������ȼ��ߵı����ȳ���
				{
					s2[j++] = top;
					stack.pop();
					if (stack.empty())
						break;
					top = stack.top();
				}
			}
			stack.push(ch);//ջ��û�б������ȼ���С����   ��ջ 
			ch = s1[++i];
		}
		else
		{
			error();
			return false;
		}
	}
	while (!stack.empty())
	{
		ch = stack.top();
		s2[j++] = ch;
		stack.pop();
	}
	s2[j] = '\0';
	return true;
}

int main()
{
	char s1[] = "( 5 + 2 ) + 3 * 2 ^ 2 - ( 4 - 6 ) * 12 + 4 + 32 -1 + 42";//����ְ��ַ���>=28֮��return ��������
	cout << "len = " << strlen(s1) << endl;
	char* s2 = new char(strlen(s1) + 1);

	if (change(s1, s2))
	{
		cout << s2 << endl;
	}
	return 0;
}
