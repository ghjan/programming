#include<iostream>
using namespace std;


class D{
	static int i;
	static int j;
	public:
		D()
		{
			cout<<"����"<<i++<<endl;
		}
		~D()
		{
			cout<<"����"<<j++<<endl;
		}
};
int D::i = 1;
int D::j = 1;


int main()
{
	//��λnew
	char buffer[1024] ;//��ջ��
	char *p = new (buffer) char[100];//��buffer�ϵ��ڴ��п���100char   ��ʵ�൱��û�п����ڴ�
	
	int *q = new int;
	int *q2 = new int;
	int *qq = new (q) int(10);
	cout<<q<<endl;				//0x8d14e0
	cout<<qq<<endl;				//0x8d14e0  ��ַһ�� 
	cout<<q2<<endl;				//0x8d1500
	
	int *d = (int*) operator new(sizeof(int));//malloc�����ڴ�
	cout<<*d<<endl;				//3873248		//����ֻ�����ڴ棬û�г�ʼ�� 
	int *dd = new (d) int(10);
	cout<<*d<<endl;				//10			//��ʼ��
	cout<<*dd<<endl;
	
	*d = 99;// d �� dd ָ��ͬһƬ�ڴ� 
	cout<<*d<<endl;				//99
	cout<<*dd<<endl;			//99
 } 

int main4()
{
	//�ڶ��Ͽ��ٳ���
	const int *p = new const int(10);
	//�ڶ��Ͽ��ٳ������� 
	//const int *q = new const int[10];
 } 
int main3()
{
	//��ô�ж��Ƿ�new�ɹ�  2
	int *p = new (nothrow) int(10);			//���� nothrow�ؼ��־Ͳ������쳣���� mallocһ���� 
	if(p == NULL)
	{
		cout<<"û��new�ɹ�"<<endl;
	}
	cout<<"new�ɹ�"<<endl;
 } 
int main2()
{
	//��ô�ж��Ƿ�new�ɹ�
	try										//malloc ��ͨ������ֵ�Ƿ�ΪNULL ���жϣ�new��ͨ�����쳣 
	{
		int *p = new int(10);	
	}
	catch(const bad_alloc &err)
	{
		cout<<"û��new�ɹ�"<<endl;
	}
	cout<<"new�ɹ�"<<endl;
 } 
int main1()
{
	D **p = new D*[4];
	//������ά���� 
	for(int i = 0;i<4;i++)
	{
		p[i] = new D[2];
	}
	//�ͷ�
	 for(int i = 0;i<4;i++)
	{
		delete[] p[i];
	}
	delete[] p;
	
}
