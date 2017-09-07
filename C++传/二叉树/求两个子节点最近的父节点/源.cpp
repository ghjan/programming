/*
���1. �ڵ�ֻ��left/right��û��parentָ�룬root��֪

���2. rootδ֪������ÿ���ڵ㶼��parentָ��

���3. �������Ǹ��������������root�������ڵ��ֵ(a, b)��֪


1.������ַ�����1���ҵ�ĳ���ڵ㣬Ȼ���Ҹ��ڵ㣨�����δ��뵽�����У���Ȼ����һ���ڵ�Ҳ�����Ҹ��ڵ㣨ÿ��һ�ξͱ���һ���������Ƿ���������ڵ㣩
			��2������һ�漰����ѭ�������ǿ������ҵ��������ڵ㣬Ȼ�������Ҹ��ڵ㣬�������ڵ��ڸ��ڵ���ұ߾���string�� + "1" ��߾� + "0" ��ʱ������ʼ�Ƚ������ַ�����ʲôʱ����ȣ��Ǿ��ǹ������ڵ�
			��2������2�Ǵ����3�еõ�����У��Ӹ���ʼ������������ڵ��ڸ������ߣ�˵��������ǹ����ڵ㣬�������
2.˼·���ӵ�ǰ�ڵ㵽root�γ�������������Ҫ��ľ������������һ�������ڵ�

3.ֻҪ�ӽڵ���ֵ�ڸ�����ֵ�����ߣ���ô������ǹ������ڵ㣨��򵥵ģ�
*/
#include <iostream>
#include <string>
using namespace std;

typedef char ElemType;
#define  END '#'

typedef struct BtNode  // BinaryTreeNode
{
	//BtNode *parent;
	BtNode *rightchild;
	BtNode *leftchild;
	ElemType data;
}BtNode, *BinaryTree;

BtNode * _Buynode()
{
	BtNode *s = (BtNode*)malloc(sizeof(BtNode));
	if (NULL == s) exit(1);
	memset(s, 0, sizeof(BtNode));
	return s;
}

BtNode * CreateTree2(ElemType *&str)
{
	BtNode *s = NULL;
	if (*str != END)
	{
		s = _Buynode();
		s->data = *str;
		s->leftchild = CreateTree2(++str);
		s->rightchild = CreateTree2(++str);
	}
	return s;
}
/*û�д���û�ҵ��������Ҳ���ǲ����Ҹ�һ���ڵ���Ϣ*/
BinaryTree findLowestParrent(BinaryTree root, BinaryTree a, BinaryTree b)
{
	if (root == NULL)
		return NULL;
	if (root == a || root == b)//ֻҪ�ҵ�һ���ڵ�ͷ�������ڵ�
		return root;
	BinaryTree left = findLowestParrent(root->leftchild, a, b);
	BinaryTree right = findLowestParrent(root->rightchild, a, b);
	if (left != NULL && right != NULL)//�����ҽڵ㶼��Ϊ�յ�ʱ��˵���ҵ�������Ĺ������ڵ㣬���õĻ������3��˼·���Ӹ��ڵ�һ�£�ֻҪĳ���ڵ���������������Ҫ�ҵĽڵ㣬˵������������ǵĹ������ڵ㣩
		return root;
	return left != NULL ? left : right;//�ҵ������һ���ڵ�ͷ������ĸ��ڵ㣨�൱�����õݹ����η��������ĸ��ڵ㣩��ͬ������ҵ����ҽڵ�
	/*
	���õ�һ�����������������ұ�ͬʱ�ҽڵ㣬��ô���صľ���root��64�У�
					  ���ֻ��left��Ϊ�գ�rightΪ�գ���ô����left�����left�൱��������һ���ݹ��root�ڵ㣬�����ظ�����ʼ�����ҵ���left �� right ͬʱ���ڵ������
	*/
}

/*-----------------------����Ĵ�����ǲ�����---------------------------*/
BinaryTree findNode(BinaryTree root, char ch)
{
	BinaryTree tree = NULL;
	if (root != NULL)
	{
		if (ch == root->data)
			return root;
		tree = findNode(root->leftchild, ch);
		if (tree == NULL)
			tree = findNode(root->rightchild, ch);
	}
	return tree;
}
int main()
{
	ElemType *str1 = "ABDH##J##E##CF##G##";
	BinaryTree root = CreateTree2(str1);
	BinaryTree a = findNode(root, 'H');
	BinaryTree b = findNode(root, 'J');
	cout << a->data << endl;
	cout << b->data << endl;
	cout << findLowestParrent(root, a, b)->data << endl;

	cout << "---------------------------------------" << endl;
	BinaryTree a2 = findNode(root, 'E');
	BinaryTree b2 = findNode(root, 'J');
	cout << a2->data << endl;
	cout << b2->data << endl;
	cout << findLowestParrent(root, a2, b2)->data << endl;
	
	cout << "----------------��һ��û�ҵ������-----------------------" << endl;
	BinaryTree a3 = new BtNode;
	a3->data = 'M';
	a3->leftchild = a3->rightchild = NULL;
	BinaryTree c3 = findLowestParrent(root, a3, b2);//a3�������棬�������Ƿ�����b2����Ϊb2����
	if (c3)
		cout << c3->data << endl;
	else
		cout << "û�ҵ�" << endl;

	system("pause");
}
/*								������Ҷ���������
										A
								B				C
							D		E		F		G
						  H   J
*/