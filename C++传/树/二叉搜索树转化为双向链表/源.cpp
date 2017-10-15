#include <iostream>
#include <vector>
using namespace std;

typedef struct NODE{
	char val;
	struct NODE *left, *right;
}Node, *Tree;

Node *Create(char *&str)
{
	if (!str || !*str || '#' == *str)
		return NULL;
	Node *node = new Node;
	node->val = *str;
	node->left = Create(++str);
	node->right = Create(++str);
	return node;
}
//left��˫��������ָ����һ����rightָ����һ��
void Convert(Node *node, Node *&pre)
{
	if (!node)
		return;
	//������ݹ������һ���ģ�������ݹ�
	if (node->left)
		Convert(node->left, pre);
	//������ߵĽڵ㣬ָ����һ���ڵ�
	node->left = pre;
	//pre����һ���ڵ�Ҳ��node���������pre������ô��Ҫָ��node
	if (pre)
		pre->right = node;
	//����һ���ڵ�Ų������ڵ�
	pre = node;
	//Ȼ���ٵݹ��ұ�
	if (node->right)
		Convert(node->right, pre);
}

Node *Convert(Node *node)
{
	if (!node)
		return NULL;
	Node *pre = NULL;
	Convert(node, pre);

	//���������ͷ
	while (pre->left)
		pre = pre->left;
	return pre;
}
void print(Node *node)
{
	if (node)
	{
		cout << node->val << " ";
		print(node->left);
		print(node->right);
	}
}
int main()
{
	char *str1 = "421##3##865##7###";
	Node *node1 = Create(str1);
	print(node1);
	cout << endl << "--------------------------" << endl;
	Node *node = Convert(node1);
	while (node)
	{
		cout << node->val << " ";
		node = node->right;
	}
	system("pause");
}