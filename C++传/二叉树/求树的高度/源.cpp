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
/*˼��ܼ򵥣������������ж���ҾͰ�������һ��root�µ�һ��Left��Right�����������ڵ㣨����ֻ�������ڵ�����ֻ��rootһ���ڵ㣩
���˼·��1.���������ж�һ���ڵ������Ƿ��к��ӣ�����к��ӣ���ô��+1�����������Ͳ��Ǹ߶��ˣ��ǽڵ�����ˣ� �����+1��root��
		  2.����������Ż�����ֻ�ж��������ĺ��ӣ�ֻ���������ӣ�ֱ��û�к���Ϊֹ���������ػᵼ������ұ߸ߵ���������ӵ���
		  3.�ٴζ������Ż���ÿ�α������Һ��ӵ�ʱ�����һ���жϣ��ж������Ƿ�����Һ��Ӹ�����ʵ�ʾ���
			��һ�����Ӿ�+1û�к��Ӿͷ���0���ڷ��ظ߶ȵ�ʱ�����һ������ ���ص������Һ�������ߵ�һ����Ȼ��͵ݹ飩
*/
int getDepth(Tree root)
{
	int depthVal, depthLeft, depthRight;

	if (!root)
		return 0;

	//���������߶�				������������һ��root һ��left һ��right һ�������ڵ㣬���� û��right ֻ�������ڵ㣬������������һ�㣩 
	depthLeft = getDepth(root->left);
	//���������߶� 
	depthRight = getDepth(root->right);
	depthVal = (depthLeft>depthRight ? depthLeft : depthRight) + 1;//ÿһ�εݹ�����Ҫ+1�����ǵ�����
	return depthVal;
}
/*�ڶ���˼·  ��*/
int max(int a, int b)
{
	return a > b ? a : b;
}
int getDepth2(Tree root)
{
	if (!root) return 0;
	return max(getDepth2(root->left), getDepth2(root->right)) + 1;//����������������������ߵģ�Ȼ�� + 1������
}
int main1()
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

	cout << endl;
	//���������� 
	cout << "���߶�" << getDepth(root) << endl;

	cout << "���߶�" << getDepth2(root) << endl;

	cin.get();
	return 0;
}
