#include<iostream>
using namespace std;
/*
���ǿ��԰� ���� ת��Ϊ ����	  const int -> const int		��
���ǿ��԰� ���� ת��Ϊ ����   int -> const int				��
���ǿ��԰� ���� ת��Ϊ ����   const int -> int				��	Ϊ������һ������ֵ

							  const int * -> const int *	��
							  int * -> const int *			�� 
							  const int * -> int *			��

							  int ** -> const int **		��
							  const int ** -> int **		��
�����int ���Ի��� char long ...  ���� int *  , char *
*/

int main3()
{
	//��һ��˵
	int *p = NULL;
	int const *d = p;//d���Ը��� �����ǣ�int const *    Ҳ����˵������ int* -> int const  *
	//int *pppp = d;  const int * -> int *��

	int *const* q = &p;//p == *q  *q���ܸı�
	int **const q2 = &p;//*q ���Ա���ֵ ���Ա� int *��ֵ    �൱�� *p���Ա� int * ��ֵ����û����
	cout << typeid(d).name() << endl;
	//int const ** q3 = &p;	//�� *q ���Ա���ֵ ���Ա� int const *��ֵ    �൱�� *p���Ա� int const * ��ֵ���Ǿʹ���
	const int ** dong = NULL;
	//int ** dong2 = dong;//�޷��ӡ�const int **��ת��Ϊ��int **��

	int const *pp;
	int const ** q3 = &pp;//*q ���Ա���ֵ ���Ա� int const *��ֵ    �൱�� p���Ա� int const * ��ֵ��û����
	
	//�෴
	const int *a;
	//int **b = &a;  //�����ǿ��Ը�*b��ֵ �����ǣ� int *  �൱�� a �� int * ��ֵ���Ե�
					//�������Ǹ� aҲ���Ը�ֵ �����ǣ�const int *  �൱�� *b �� const int * ��ֵ�����
					//�������Ƕ���һ�����������֤������������������û�з�����֤�������Ƿ�����֤����Ҳ��û����ģ�������ӷ�����֤���͹��ˡ�
	//���������Ժ���Ҫ��������ͬʱ��֤��Ҳ���Դ�const���֣�����һ������Ҳ�ܽ����
	// ���� const int *a  ���Ǿ��뵽���� *a ��ֵ��������ֵ��  �� a��ֵ��Ȼ��ȥ��֤
	// ���� const int **a	�� **a ��ֵ��������ֵ��	�� *a ��ֵ��Ȼ��ȥ��֤  �� a��ֵ��Ȼ��ȥ��֤
	//���������
	const int **b = &a;

	//����һ�������
	int *const c = NULL;
	//int **d = &c; //�������Ǹ� *d ��ֵ int* ���͵�ֵ  �൱�ڸ� c ��ֵ ��Ȼ���Ϳ���ƥ�䣬 ����c���ܱ���ֵ
	//�ͺ��������������
	int const x = 1;
	int const y = 2;
	//x = y;	x��y������Ȼһ����but x�ǳ���

	//�ܽ�:��const�ұ�û��*  ������֤��const��ֵ����const�ұ���*��������֤const   (���Ǳ䶯�Ǹ�ֵ��
	//Ҫ�Ǽǲ�ס�����߶���֤
	getchar();
	return 0;
}
int main2()
{
	int *p;
	//const int **q = &p;// �޷��ӡ�int **��ת��Ϊ��const int **�� Ϊʲô�������أ�
						//���治��˵  int -> const int ����ô
	//const int **q��ʾ�����޸�**p ��ֵ�����������ǿ����޸�*p��ֵ����*p ����Ϊ��ֵ��
	//���� *p��˵   const int*  *p;		*p��һ��const int* ���͵�
	//���������const int *b = NULL;  *p = b;  �൱��p = b ;  ����������Ļ������� const int -> int	,���Ա�����������
	
	//����취��1
	const int *const *q = &p;//����	  **q ��һ������  *q  Ҳ��һ������(���仰˵*p ������Ϊ��ֵ��)
	//����취��2
	const int *a;
	const int **b = &a;//�����Ļ���**b��һ��������������Ϊ��ֵ��    *b��������Ϊ��ֵ��
						//����  ������const int *c = NULL;  *b = c;  �൱��a = b ;  const int -> cosnt int ûɶ����
	//�����������ûɶ������
	const int *c = NULL;
	*b = c;
	a = c;


	system("pause");
	return 0;
}
int main1()
{
	int a = 10;
	int &b = a;
	const int c = a;	// int -> const int  ����

	const int Pi = 3; 
	int i = Pi;			// const int -> int Ҳ��
	i = 5;
	cout << i << endl;

	//const int a = 10;
	//const int &b = a;	//	const int -> const int 
	
	system("pause");
	return 0;
}