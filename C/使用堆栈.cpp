#include<stdio.h>
#include<stack>
using namespace std;
//��������c++�ķ��� 
int main()
{
	stack<char>cstack;
	char c;
	int n=6;
	while(--n)// ���� --n �� n-- �����������  --n�ȼ�һ���ж�n�Ƿ�Ϊ0   n-- ���ж��Ƿ�Ϊ0  ��ִ�� --  
	{
		c = getchar();
		getchar();
		cstack.push(c);//����� 
	}
	//�ж϶����Ƿ�Ϊ�� ����Ϊ:empty()	��Ϊ�շ��� 0 
	while(!cstack.empty())
	{
		printf("top = %c\n",cstack.top());
		printf("size = %d\n\n",cstack.size());
		cstack.pop();//������
	}
}
