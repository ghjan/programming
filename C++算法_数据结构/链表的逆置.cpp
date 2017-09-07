#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

typedef struct Dong{
	char str[20];
	struct Dong *next;
}*Node, Dong;

Node init()
{
	Node root = new Dong;
	Node tNode = root;
	Node node;
	char str[20];
	cin >> str;
	while (*str != '$')
	{
		node = new Dong;
		strcpy(node->str, str);
		node->next = NULL;
		tNode->next = node;
		tNode = node;
		cin >> str;
	}
	return root;
}
void print(Node root)
{
	cout << "-------------------------" << endl;
	root = root->next;
	while (root != NULL)
	{
		cout << root->str << endl;
		root = root->next;
	}
	cout << "-------------------------" << endl;
}
/////////////////////////////�ݹ�//////////////////////////////////////
Node sys_reverse(Node pre, Node cur)
{
	Node Rnode = NULL;
	if (cur)
	{
		Rnode = sys_reverse(cur, cur->next);
		cur->next = pre;
	}
	else
	{
		Rnode = pre;//�������һ���ڵ�
	}
	return Rnode;
}

void reverse(Node root)
{
	if (!root)
		return;
	Node node = sys_reverse(root, root->next);
	root->next->next = NULL;					//*********ע�⣺������Ҫ�ѳ���ͷ���ĵ�һ���ڵ�next��ֵΪNULL����Ȼ��ӡ��û�н���������
	root->next = node;//����Ҫ��ͷ���͡�ԭ���������һ���ڵ�����
}
/////////////////////////////�ǵݹ�//////////////////////////////////////
void reverse2(Node root)
{
	if(!root) return;
	Node node = root->next;
	Node pre = NULL,nextNode;
	while(node)
	{
		nextNode = node->next;
		node->next = pre;
		pre = node;
		node = nextNode;
	}
	root->next = pre;
}

int main()
{
	Node root = init();
	print(root);
	reverse(root);
	print(root);
	reverse2(root);
	print(root);
}
/*
nice
to
meet
you
$
*/
