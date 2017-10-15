#include <iostream>
#include <cstdlib>
using namespace std;
typedef struct node
{
	char data;
	int ltag, rtag;
	struct node *lchild, *rchild;
}bitree;
bitree *Q[32], *pre = NULL;

//����
bitree *create()
{
	bitree *s, *root;
	int front, rear;
	char x;

	front = 1; rear = 0;
	root = NULL;
	x = getchar();
	while (x != '$')
	{
		rear++;
		s = NULL;
		if (x != '@')
		{
			Q[rear] = (bitree*)malloc(sizeof(bitree));
			Q[rear]->data = x;
			Q[rear]->ltag = 0;
			Q[rear]->rtag = 0;
			Q[rear]->lchild = NULL;
			Q[rear]->rchild = NULL;
			if (rear == 1)
				root = Q[rear];
			else
			{
				if (rear % 2 == 0)
					Q[front]->lchild = Q[rear];
				else
					Q[front]->rchild = Q[rear];
				if (rear % 2 == 1)
					front++;
			}
		}
		else
		{
			Q[rear] = s;
			if (rear % 2 == 1)
				front++;
		}
		x = getchar();
	}
	getchar();
	return root;
}
//�������
void Inorder(bitree *t)
{
	if (t)
	{
		Inorder(t->lchild);
		printf("%c", t->data);
		Inorder(t->rchild);
	}
}
//������ (������������   //����ڵ�Ϊ�յ�ȫ��ָ��������һ���ڵ㣬�ҽڵ�Ϊ�յ�ȫ��ָ��������һ���ڵ�
void Thread1_sys(bitree *t)
{
	bitree *p = t;
	if (p)
	{
		Thread1_sys(p->lchild);
		/*��ʵ����ָ����һ���ڵ㣬�Ҹо�ûɶ�ã���ȫ��Ӱ�����*/
		if (p->lchild == NULL)		//����Ϊ�յĻ���ָ��������һ���ڵ�
		{
			p->ltag = 1;//��־���Ա����Ǳ������ױ���
			p->lchild = pre;
		}
		if (pre->rchild == NULL)	//��һ���ڵ��Һ���Ϊ�գ���ָ����������ڵ�
		{
			pre->rtag = 1;//��־���Ա����Ǳ������ױ���
			pre->rchild = p;
		}
		pre = p;
		Thread1_sys(p->rchild);
	}
}
void Thread(bitree *t)
{
	Thread1_sys(t);
	pre->rtag = 1;
}
void Thread2_sys(bitree *t, bitree *&pre2)
{
	bitree *p = t;
	if (p)
	{
		Thread2_sys(p->lchild, pre2);
		if (p->lchild == NULL)		//����Ϊ�յĻ���ָ��������һ���ڵ�
		{
			p->ltag = 1;//��־���Ա����Ǳ������ױ���
			p->lchild = pre2;
		}
		if (pre2 && pre2->rchild == NULL)	//��һ���ڵ��Һ���Ϊ�գ���ָ����������ڵ�
		{
			pre2->rtag = 1;//��־���Ա����Ǳ������ױ���
			pre2->rchild = p;
		}
		pre2 = p;
		Thread2_sys(p->rchild, pre2);
	}
}
void Thread2(bitree *t)
{
	bitree* pre2 = NULL;
	Thread2_sys(t, pre2);
	pre2->rtag = 1;
}
//����һ���ڵ㣬�ҵ���һ���ڵ�
bitree *Inorder_next(bitree *p)
{
	if (p->rtag == 1)				// == 1 ˵��ʹ���Ǽӵ�һ���ߣ�����ԭ���������е�
		return p->rchild;			// ֻҪ���ұ� rtag == 1 ˵��һ��ָ����������һ���ڵ�
	else
	{
		p = p->rchild;				// �ߵ��������ˣ�˵���ұ��к���
		while (/*p && */p->ltag == 0)	// �������ٴα����������ӣ��ߵ���Ͷˣ����������   ������һ���ڵ��������Һ��ӾͲ���Ҫ p &&
			p = p->lchild;
		return p;
	}
}
//�������
void Travel_order(bitree *t)
{
	while (t->ltag == 0)		//�����������һ���ڵ㣬�϶�������ߵ��Ǹ�����
		t = t->lchild;
	while (t)
	{
		cout << t->data;
		t = Inorder_next(t);	//�ҵ���һ�������ҵ���һ��
	}
	cout << endl;
}
//////////////////////////////////////////////////////////////////////
////////////////////���Ŵ�ӡ////////////////////////////////////////
bitree* Last(bitree* p)
{
	while (p->rtag != 1)
		p = p->rchild;
	return p;
}
bitree* Prev(bitree* p)
{
	if (p == NULL) return NULL;
	if (p->ltag == 1)
		return p->lchild;
	else
		return Last(p->lchild);
}
void resTravel_order(bitree *t)
{
	for (bitree *p = Last(pre); p != NULL; p = Prev(p))
	{
		cout << p->data << "  ";
	}
	cout << endl;
}
int main()
{
	bitree* root;
	root = create();
	Inorder(root);
	cout << endl << "----------���Ƿ�������������һ��-----------" << endl;
	pre = root;
	Thread(root);
	Travel_order(root);

	bitree* root2 = create();
	Thread2(root2);
	Travel_order(root2);
	resTravel_order(root2);

	system("pause");
}
/*
���У�ltag=0 ʱlchildָ������Ů��
ltag=1 ʱlchildָ��ǰ����
rtag=0 ʱrchildָ������Ů��
rtag=1 ʱrchildָ���̣�
*/
//���룺ABC@DE@$
//��ӡ��BDAEC