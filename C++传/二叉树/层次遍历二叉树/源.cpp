//����һ�ö�������Ҫ��ֲ�����ö������������ϵ��°���η��ʸ�����ÿһ�㵥�����һ�У�ÿһ��Ҫ����ʵ�˳��Ϊ�����ҡ�
//�����ڱ����Ĺ����н��ò�ڵ�ĺ��ӽڵ�ѹ��һ�����У������Ϳ���ʵ�ִ��ϵ���һ��һ��ر����ö�������
#include <iostream>
#include <queue>
using namespace std;

typedef struct NODE{
	char val;
	struct NODE *left, *right;
}Node, *Tree;

//���򴴽�
void createTree(Tree &t, char *&a)//ע���������Ǳ�����&���ã���Ϊ����Ҫ�ı䴫������root�ĵ�ַ��ҪΪ�������ڴ棩
{
	if (*a == ' ' || *a == NULL)
	{
		t = NULL;
		return;
	}
	t = new Node;
	t->val = *a;
	createTree(t->left, ++a);
	createTree(t->right, ++a);
}

//�ݹ��������
void preOrderY(Tree t)
{
	if (!t)
		return;
	cout << t->val << "   ";
	preOrderY(t->left);
	preOrderY(t->right);
}

void printByLevel(Tree t)
{
	Tree p;
	queue<Tree> q;
	q.push(t);
	while (!q.empty())
	{
		p = q.front();
		q.pop();
		cout << p->val << " ";
		if (p->left)
			q.push(p->left);
		if (p->right)
			q.push(p->right);
	}
}

int main()
{
	char *a = "123  4  56";
	Tree t = new Node;
	createTree(t, a);
	preOrderY(t);
	cout << endl;
	printByLevel(t);

	system("pause");
}