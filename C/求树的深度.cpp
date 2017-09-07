#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct NODE{
	int val;
	struct NODE *left;
	struct NODE *right;
	NODE(int val):val(val),left(NULL),right(NULL){}		
}Node,*Tree;
void create(Tree &p,int val)
{
	if(p==NULL)
	p = new Node(val);
	
	else
	{
		if(val < p->val)
		create(p->left,val);
		
		if(val > p->val)
		create(p->right,val);
	}
 } 

int getDepth(Tree root)
{
	int depthVal = 0,depthLeft = 0,depthRight = 0;
	if(!root)
		return 0;
	 
	//���������߶�								������������һ��root һ��left һ��right һ�������ڵ㣬���� û��right ֻ�������ڵ㣬������������һ�㣩 
	depthLeft = getDepth(root->left);
	//���������߶�
	depthRight = getDepth(root->right);
	depthVal = (depthLeft>depthRight?depthLeft:depthRight) + 1;//�߶�Ҫ����root�����
	return depthVal;
}

int main()
{
	int a[20];
 	Tree root = NULL;
 	//�ȴ���һ���� 
 	for(int i=0;i<10;i++){
 	 	a[i] = rand()%100;
		printf("%-5d",a[i]);	
	 }
	for(int i=0;i<10;i++)
 	create(root,a[i]);
	
	//���������� 
	cout<<"���߶�"<<getDepth(root)<<endl;
}
