#include <iostream>
#include <string>
using namespace std;

typedef struct Student{
	int age;
	string name;
	struct Student* next;
}List;

List* init()
{
	List* head = new List;
	List* p = head;
	int b;
	char stop;
	cout<<"��ʼ����������(����������$�ͽ�����ʼ��)"<<endl;
	while(stop != '$')
	{
		cout<<"������ѧ������������"<<endl;
		List* node = new List;
		cin>>node->name>>node->age;
		node->next = NULL;
		p->next = node;
		p = node;
		stop = getchar();//�����и�С���ɣ����������� 
	}
	return head;
}
//ͷ�巨 
void addLast(List* head)
{
	List* p = head->next;
	List* node = new List;
	while(p->next!=NULL)
	{
		p = p->next;
	}
	
	cout<<"�������� ����"<<endl;
	
	cin>>node->name>>node->age;
	node->next = NULL; 
	p->next = node;
	//cout<<p->name<<p->age;
}
//β�巨 
void addFirst(List* head)
{
	List* p = head->next;
	List* node = new List;
	cout<<"�������� ����"<<endl;
	cin>>node->name>>node->age;
	head->next = node;
	node->next = p;
} 
//��ֵɾ�� 
void mydelete(List* head)
{
	List* p = head->next;
	List* prev = head;
	string name;
	cout<<"��Ҫɾ���ĸ��˵���Ϣ��(����������)"<<endl; 
	cin>>name; 
	while(p->name!=name)
	{
		prev = p;
		p = p->next;
		
		if(p==NULL)
		{
			cout<<"û�������"<<endl;
			return ; 
		}
	}
	prev->next = p->next;
	delete p;
}
//����ɾ�� 
void mydeleteNum(List* head) 
{
	List* p = head->next;
	List* pre = head;
	int n;
	cout<<"��Ҫɾ���ĸ��ˣ�(���������)"<<endl; 
	cin>>n; 
	if(n>0)
	{
		while(n-->1)
		{
			pre = p;
			p = p->next;
		}
		pre->next = p->next;
		delete p;
	}
}
//�� 
void alter(List* head)
{
	List* p = head->next;
	List* last = p->next;
	string name;
	cout<<"��Ҫ���ĸ��˵���Ϣ��(����������)"<<endl; 
	cin>>name; 
	
	while(p->name!=name)
	{
		p = p->next;
		if(p==NULL)
			return;
		last = p->next;
	}
	
	cout<<"�������µ����ֺ�����"<<endl;
	cin>>p->name>>p->age;
}
//���� 
void check(List* head)
{
	List* p = head->next;
	string name;
	cout<<"��Ҫ���ĸ��ˣ�(����������)"<<endl; 
	cin>>name; 
	while(p->name!=name)
	{
		p = p->next;
		
		if(p==NULL)
		break;
	}
	if(p!=NULL)
		cout<<"������ˣ�����������"<<p->name<<"\t������"<<p->age<<endl;
	else
		cout<<"û�������"<<endl;
}
void display(List* head)
{
	List* p = head->next;
	int n = 1;
	while(p!=NULL)
	{
		cout<<n++<<"��"<<"������"<<p->name<<"\t���䣺"<<p->age<<endl;
		p = p->next;
	}
}

int main()
{
	List* head = init();
	int n = 0;
	while(1)
	{
		cout<<"1.ͷ��\t2.β��\t3.��ֵɾ��\t4.����ɾ��\t5.��\t6.����\t7.��ʾ"<<endl;
		cin>>n;
		
		if(1 == n)
		{
			addFirst(head);
		}
		else if(2 == n)
		{
			addLast(head);
		}
		else if(3 == n)
		{
			mydelete(head);
		}
		else if(4 == n)
		{
			mydeleteNum(head);
		}
		else if(5 == n)
		{
			alter(head);
		}
		else if(6 == n)
		{
			check(head);
		}
		else if(7 == n)
		{
			display(head); 
		}
		else if(n<='0' || n>'7')
		{
			cout<<"����ȷ����"<<endl; 
			break;
		}
	}
	
}
/*
������ 20
��ɯ 32
˧�� 22
���� 44
����ӱ 27
Baby 28$ 
*/
