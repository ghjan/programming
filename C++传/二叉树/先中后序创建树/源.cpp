#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;

typedef struct NODE{
	char val;
	struct NODE *left, *right;
}Node, *Tree;

//���򴴽�
void createTreeA(Tree &t, char a[], int &i)//ע���������Ǳ�����&���ã���Ϊ����Ҫ�ı䴫������root�ĵ�ַ��ҪΪ�������ڴ棩
{
	if (i > 9 || a[i] == ' ')
	{
		t = NULL;
		return;
	}

	t = new Node;

	t->val = a[i];
	createTreeA(t->left, a, ++i);
	createTreeA(t->right, a, ++i);
}
//���򴴽�
void createTreeB(Tree &t, char a[], int &i)//ע���������Ǳ�����&���ã���Ϊ����Ҫ�ı䴫������root�ĵ�ַ��ҪΪ�������ڴ棩
{
	int ii = i;
	if (i > 9 || a[i] == ' ')
	{
		t = NULL;
		return;
	}

	t = new Node;


	createTreeB(t->left, a, ++i);
	t->val = a[ii];
	createTreeB(t->right, a, ++i);
}
//���򴴽�
void createTreeC(Tree &t, char a[], int &i)
{
	int ii = i;
	if (i > 9 || a[i] == ' ')
	{
		t = NULL;
		return;
	}

	t = new Node;

	createTreeC(t->left, a, ++i);
	createTreeC(t->right, a, ++i);
	t->val = a[ii];
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
//�ݹ��������
void inOrderY(Tree t)
{
	if (!t)
		return;
	inOrderY(t->left);
	cout << t->val << "   ";
	inOrderY(t->right);
}
//�ݹ�������
void postOrderY(Tree t)
{
	if (!t)
		return;
	postOrderY(t->left);
	postOrderY(t->right);
	cout << t->val << "   ";
}
int main()
{
	//���ִ������ķ���Ҳ����#���������Ұ�#�����˿ո�   ���к󴴽�������������һ����
	char a[] = { '1', '2', '3', ' ', ' ', '4', ' ', ' ', '5', '6' };//ע������Ҫ�����ո���Ϊ������������ҪNULL
	int i = 0, ii = 0, iii = 0;
	Tree rootA = NULL;
	Tree rootB = NULL;
	Tree rootC = NULL;

	//���򴴽�
	createTreeA(rootA, a, i);
	cout << "�ݹ��������" << endl;
	preOrderY(rootA);
	cout << endl << "�ݹ��������" << endl;
	inOrderY(rootA);
	cout << endl << endl << "�ݹ�������" << endl;
	postOrderY(rootA);

	cout << endl << "-------------------" << endl;

	//���򴴽�
	createTreeB(rootB, a, ii);
	cout << endl << "�ݹ��������" << endl;
	inOrderY(rootB);
	
	//���򴴽�
	createTreeB(rootC, a, iii);
	cout << endl << endl << "�ݹ�������" << endl;
	postOrderY(rootC);


	

	cin.get();
	return 0;
}