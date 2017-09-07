#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct NODE{
	int val;
	struct NODE *left;
	struct NODE *right;
	NODE(int val):val(val),left(NULL),right(NULL){}		//��ʼ��֧�� TreeNode��int x�����ַ�ʽ���� ��x����val��left��right��ֵNULL 
}Node,*Tree;
//������������ ������  ���Բ����������ͬ���� 
void create(Tree &p,int val)//���û��˫ָ�룬����Ҳ�൱��˫ָ�룬�����  ָ��ȡ��ַ   ָ��ȡ��ַҲ���൱�ڶ���ָ��(���ˣ���������)
{
	if(p==NULL)//������˫ָ����ô���ӣ�������ֱ�Ӳ��� һ��ָ�� p   �����˫ָ��  ��Ҫ�� (*p)->  �Ƚ��鷳   (��� &p ������c++�е�����)
	p = new Node(val);
	
	else
	{
		if(val < p->val) //��ǰֵ С�� �� ��ֵ
		create(p->left,val);
		
		if(val > p->val)//��ǰֵ  ���� �� 
		create(p->right,val);
	}
 } 
 /* ����������� ˫ָ�� 
 void create(Tree *p,int val)
{
	if(*p==NULL)
	*p = new Node(val);
	
	else
	{
		if(val < (*p)->val) //��ǰֵ С�� �� ��ֵ
		create(&(*p)->left,val);
		
		else if(val > (*p)->val)
		create(&(*p)->right,val);
		
		else
		printf("���ظ�������%d\n",val);
	}
 } 
 */
 
void visit(Tree t)
{
	if(t->val != NULL)
	printf("%-5d",t->val);
}
void preOrder(Tree t)
{
 	if(p != NULL)
 	{
 //		visit(p);  	//�������  ��֪��Ϊʲô  0 �ᱻ��Ϊ�� NULL 	���NULL �ĺ궨����� 0	
 		printf("%-5d",p->val);
		preOrder(p->left);
		preOrder(p->right);	
	 }
}
void inOrder(Tree t)
 {
 	if(p != NULL)
 	{ 		
		preOrder(p->left);
		printf("%-5d",p->val);
		preOrder(p->right);	
	 }
}
 void postOrder(Tree t)
{
 	if(p != NULL)
 	{ 		
		preOrder(p->left);
		preOrder(p->right);	
		printf("%-5d",p->val);	
	 }
 }
 int main()
 {
 	int a[20];
 	Tree root = NULL;
 	for(int i=0;i<10;i++){
 	 	a[i] = rand()%100;
		printf("%-5d",a[i]);	
	 }
	for(int i=0;i<10;i++)
 	create(root,a[i]);

	puts("\n\n��������");
	preOrder(root);
	
	puts("\n��������");
	inOrder(root);
	
	puts("\n��������");
	postOrder(root); 
 	return 0;
 }
