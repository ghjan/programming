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
	case '(':
	default: return 0;
	}
}

void error()
{
	cout << "��ı��ʽ������,����ϸ���" << endl;
}

void count(char* str)
{
	stack<char> s;
	char ch = str[0];

	while (ch != '\0')
	{

	}

}

int main()
{



	cin.get();
}
