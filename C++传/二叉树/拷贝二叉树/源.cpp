#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct NODE{
	int val;
	struct NODE *left;
	struct NODE *right;
	NODE(int val) :val(val), left(NULL), right(NULL){}
}Node, *Tree;
void create(Tree &p, int val)
{
	if (p == NULL)
		p = new Node(val);

	else
	{
		if (val < p->val)
			create(p->left, val);

		if (val > p->val)
			create(p->right, val);
	}
}
//�������
void perOrder(Tree t)
{
	if (t == NULL)
	{
		return;
	}
	cout << t->val << "   ";
	perOrder(t->left);
	perOrder(t->right);
}
//����������
Tree copyTree(Tree t)
{
	Tree tLeft = NULL, tRight = NULL, tNode = NULL;//��������ָ��
	if (t->left)
		tLeft = copyTree(t->left);//��ָ�� ���еݹ������ڵ�
	else
		tLeft = NULL;			//ֱ��ĳ���ڵ����ڵ�ΪNULL
	if (t->right)				  
		tRight = copyTree(t->right);//��ָ��  ���еݹ�����ҽڵ�
	else
		tRight = NULL;			//ֱ��ĳ���ڵ���ҽڵ�ΪNULL

	tNode = new Node(t->val);//�����������root�ڵ�
	tNode->left = tLeft;	//�����������Left�ڵ�
	tNode->right = tRight;	//�����������Right�ڵ�

	return tNode;
}

int main()
{
	int a[20];
	Tree root = NULL;
	//�ȴ���һ���� 
	for (int i = 0; i<10; i++){
		a[i] = rand() % 100;
		printf("%-5d", a[i]);
	}
	for (int i = 0; i<10; i++)
		create(root, a[i]);

	cout << endl << "�������" << endl;
	perOrder(root);

	cout << endl << "������п���" << endl;

	Tree cT = copyTree(root);
	perOrder(cT);

	cin.get();
}