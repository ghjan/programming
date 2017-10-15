#include <iostream>
#include <cstring>
using namespace std;

typedef struct dong{
	char value;
	struct dong *left;
	struct dong *right;
}*Node, Dong;

Node buyNode()
{
	Node node = new Dong;
	node->value = -1;
	node->left = NULL;
	node->right = NULL;
	return node;
}
#if 0
Node create_tree_byPI2(char *&sp, char *si, int n)
{
	if (sp == NULL || si == NULL || n <= 0)
	{
		--sp;						//����ؼ��ϣ���Ϊ������ܱ����ˣ�˵������������������sp��������һ���ݹ��Ѿ�++�ˣ�����������Ҫ--
		return NULL;
	}
	int i = 0;
	for (; i < n; i++)
	{
		if (*sp == *(si + i))
			break;
	}
	Node node = buyNode();
	node->value = *sp;
	node->left = create_tree_byPI(++sp, si, i);
	node->right = create_tree_byPI(++sp, si + i + 1, n - i - 1);
	return node;
}
#endif

/*��������������Ǹ�Ҫ��һ�㣬�����׳�bug  ����bug�����˺þã�������Ϊ���õ��µģ������������Լ���������������*/
Node create_tree_byPI(char *sp, char *si, int n)
{
	if (sp == NULL || si == NULL || n <= 0)
	{
		return NULL;
	}
	int i = 0;
	for (; i < n; i++)
	{
		if (*sp == *(si + i))
			break;
	}
	Node node = buyNode();
	node->value = *sp;
	node->left = create_tree_byPI(sp + 1, si, i);
	node->right = create_tree_byPI(sp + i + 1, si + i + 1, n - i - 1); //���� sp + i + 1 ��Ҫ�Լ����һ��
	return node;
}
/*�������� ���� ���� �������ֻ࣬��������������ʱ��ע���� i + 1  ���� i */
Node create_tree_byIL(char *si, char *sl, int n)
{
	if (sl == NULL || si == NULL || n <= 0)
	{
		return NULL;
	}
	int i = 0;
	for (; i < n; i++)
	{
		if (sl[n - 1] == si[i])
			break;
	}
	Node node = buyNode();
	node->value = sl[n - 1];
	node->left = create_tree_byIL(si, sl, i);
	node->right = create_tree_byIL(si + i + 1, sl + i, n - i - 1);
	return node;
}

/*�������*/
void print(Node root)
{
	if (root == NULL)
		return;
	print(root->left);
	cout << root->value << "\t";
	print(root->right);
}
/*�������*/
void print2(Node root)
{
	if (NULL == root)
		return;	
	print2(root->left);
	print2(root->right);
	cout << root->value << "\t";
}

int main()
{
	/*�������Ǵ�ͷ��βû�иı��ַ��������Կ�������ֱ��ָ�򣬵���Ҫע�⣺�������Ҫ�ı���Ҫ new*/
	char *sp = "ABDEFGC";//����
	char *si = "DBFEGAC";//����
	char *sl = "DFGEBCA";//����
	Node root = create_tree_byPI(sp, si, strlen(si));
	print(root);/*�������*/
	cout << endl << "------------------------------------------------" << endl;
	Node root2 = create_tree_byIL(si, sl, strlen(si));
	print2(root2);

	getchar();
}
