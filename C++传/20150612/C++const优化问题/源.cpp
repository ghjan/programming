#include<iostream>
using namespace std;

void run1(const int *p);//���Ըı��ַ�����ܸı�����
void run2(int const *p);//������һ��
void run3(int *const p);//���Ըı����ݣ����ܸı��ַ
void run4(const int * const p);//���ܸı��ַ�����ܸı�����
void run5(int const * const p);//������һ��



void main()
{
	const int n[5]{1, 2, 3, 4, 5};
	for (int i : n)
	{
		cout << i << endl;
	}
	*((int *)&n) = 100;//�ı��һ��Ԫ��     //const����û���Ż�
	for (int i : n)
	{
		cout << i << endl;
	}

	cin.get();
}


void main3()
{
	int i = 10;
	const int a = i;
	//int arr[a];   //�������С���C++�����Ż�������Ϊ i ���ǳ���
	
	//���Ż�Ҳ�кô������ǿ��Ը�const��ֵ��

	*((int *)&a) = 300;//��Ϊ���Ż��ˡ������Ǵ��ڴ���ȡ����ַ�����ĵ�ַ�ϵ��ڴ棬�����ܸı�const��ֵ
	cout << i << "   " << a << endl;



	cin.get();
}


void main2()
{
	const int a = 10;
	int arr[a];//�����ǿ��Եġ���c++�Ż��󡣡�a����10          c�в���
}


void main1()
{
	const int a = 10;						//�������Ǹ���a��ֵ�ǳ�������c++���������Ż������Ժ�ȡֵ�������ڴ���ȡ��
	cout << "a �ĵ�ַ ��" << &a << endl;

	int *p = (int *)&a;
	cout << "p ָ��ĵ�ַ ��" << p << endl;

	*((int *)&a) = 1000;

	cout << *(&a) << endl;//a��ֵ�����ܸı䡣��c++�������Ż��ˡ�������a���ڼĴ�����ȡ��10   �������ڴ�
	cout << a << endl;
	cout << p << endl;
	cout << *p << endl;
	/*
	a �ĵ�ַ ��    00DDFA90
	p ָ��ĵ�ַ ��00DDFA90		��ַһ��
	10
	10
	00DDFA90
	1000					���Կ�������a��ַ�ϵ��ڴ��Ѿ����ı�
	*/
	cin.get();
}
