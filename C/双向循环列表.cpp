#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
	int a;
	struct list *next;
	struct list *prior;
}str;
int n;
str * creat(str *head)
{
	str *p,*pt;
	printf("Ҫ���뼸�����ݣ�\t");
	scanf("%d",&n);
	int m=n;
	printf("\n������\n"); 
	scanf("%d",&head->a);
	p=pt=head;
	while(m>1)
	{
		m--;
		p=(str *)malloc(sizeof(str));
		scanf("%d",&p->a);
		p->prior=pt;
		pt->next=p;
		pt=p;
	}
	head->prior=p;
	p->next=head;
	return head;
 } 
//���� 
void gothrough(str *head) 
{
	str *p;
	p=head;
	printf("�������\n");
	int m=n;
	while(m)
	{
		m--;
		printf("%-3d",p->a);
		p=p->next;
	}
	printf("\n�������\n");
	m=n;
	while(m)
	{
		m--;
		p=p->prior;
		printf("%-3d",p->a);
	}
 }
//ɾ���ڵ㣬����ɾ������ 
void deletelist(str *head)
{
	printf("��Ҫɾ���ĸ��ڵ�?\t");
	int node;
	scanf("%d",&node); 
	
	str *front,*behind;
	front=behind=head;
	behind=behind->next;
	int m=n;
	if(node>2)
	while(node>2)
	{
		behind=behind->next;
		front=front->next;
		node--;
	}
	if(1==node)
	{
		head->a=behind->a;// ������ʼ���������ģ�ͻȻ���ֺ���ͷ��㲻��ɾ������Ȼ����������� �����Ի���һ������ ��ɾ��ͷ��� 
	}
	behind=behind->next;
	
	front->next=behind;
	behind->prior=front;
	head=front;
	n--;	
}
//����ڵ㣬׼ȷ��˵��ֻ���뵽��β�������úܣ����컹�кܶ���Ҫ�� �����м���ʵҲ���� 
void insert(str *head)
{
	int a,node=n;
	str *p,*q,*str1;
	str1=(str *)malloc(sizeof(str));
	printf("\n��Ҫ�������\n");
	scanf("%d",&str1->a);
	
	p=head;
	while(node>1)
	{
		p=p->next;
		node--;
	}
	q=p->next;
	p->next=str1;
	str1->prior=p;
	q->prior=str1;
	str1->next=q;
	n++;
 } 
int main()
{
	str *head;
	int m;
	head=(str *)malloc(sizeof(str));// �ص�**Ϊ������ռ��Ǳ���ģ�1.��������û�ж������з���ռ�  2.���������ռ�����˿ռ�Ҳֻ�����Ǹ���������Ч������Ҫ����ȫ����Ч�� 
	head=creat(head);
	gothrough(head);
	while(1)
	{
		printf("\n1.�������\t2.ɾ������\t3.��������\n");
		scanf("%d",&m);
		if(1==m)
		{
			insert(head);
		 } 
		 if(2==m)
		 {
			deletelist(head);
		 }
		 if(3==m)
		 {
		 	gothrough(head);
		 }
	}
 } 
