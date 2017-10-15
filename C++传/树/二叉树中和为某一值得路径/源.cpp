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
//��vector��Ŀ�ľ����������������cur == exp ��ô�Ϳ���ֱ�Ӵ�ӡ��
void FindPath(Node *node, vector<char> &v, char exp, char cur)
{
	cur += node->val - '0';
	v.push_back(node->val);
	//�����ǰ�ڵ���Ҷ�ڵ�
	if (!node->left && !node->right && cur == exp)
	{
		for (vector<char>::iterator it = v.begin(); it != v.end(); it++)
			cout << *it << " ";
		cout << endl;
	}
	//�������Ҷ�ڵ㣬���������ӽڵ�
	if (node->left)
		FindPath(node->left, v, exp, cur);
	if (node->right)
		FindPath(node->right, v, exp, cur);
	//�����û�ҵ���˵����ǰ�ڵ�����û�к��ʵ�·��  ������治�����ã���ô����Ϳ��Բ�Ҫ
	v.pop_back();
}
void FindPath(Node *node, char expect)
{
	if (!node)
		return;
	vector<char> v;
	FindPath(node, v, expect, '0');
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

	char *str1 = "123##4##2324##1###6##";
	Node *node1 = Create(str1);
	print(node1);
	cout << endl << "--------------------------" << endl;
	FindPath(node1, '9');
	system("pause");
}