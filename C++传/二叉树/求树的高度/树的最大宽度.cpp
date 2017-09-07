#include <iostream>
#include <cstdlib>
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
int max(int a, int b);
int depth(Node *n)
{
	if (n == NULL)
		return 0;
	return max(depth(n->left) , depth(n->right)) + 1;
}
/*������ĳ���ڵ�����Ҹ߶Ⱥ�+1*/
int sizeTree_sys(Node *node)
{
	if (node == NULL)
		return 0;

	int rootSize = depth(node->left) + depth(node->right) + 1;//�����������������߶Ȳ����
	int leftSize = sizeTree_sys(node->left);//�ݹ�����
	int rightSize = sizeTree_sys(node->right);//�ݹ��Һ���

	return max(max(rootSize, leftSize), rightSize);//ѡ������size �Һ���size �� ��size�ĸ����
}
void printPre(Node *node)
{
	if (node == NULL)
		return;
	cout << node->val << " ";
	printPre(node->left);
	printPre(node->right);
}

int main()
{
	char *a = "ABDF   EGH    C  ";
	Tree root = NULL;
	//�ȴ���һ���� 
	createTree(root, a);
	printPre(root);
	cout << endl << "------------------------" << endl;
	cout << "��ȣ�" << sizeTree_sys(root) << endl;

	system("pause");
	return 0;
}