#include<stdio.h>
#include<queue>
using namespace std;
//��������c++�ķ��� 
int main()
{
	queue<char>cque;
	char c;
	int n=6;
	while(--n)// ���� --n �� n-- �����������  --n�ȼ�һ���ж�n�Ƿ�Ϊ0   n-- ���ж��Ƿ�Ϊ0  ��ִ�� --  
	{
		c = getchar();
		getchar();
		cque.push(c);//����� 
	}
	//�ж϶����Ƿ�Ϊ�� ����Ϊ:empty()
	while(!cque.empty())
	{
		printf("front = %c\n",cque.front());
		printf("back = %c\n",cque.back());
		printf("size = %d\n\n",cque.size());
		cque.pop();//������
	}
}
