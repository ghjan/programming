#include<stdio.h>
int func(int a,int b,int c)
{
	return a+b+c; 
}
int func(int a,int b)
{
	return a+b;
}

typedef int( *dong)(int,int);//����һ�� ��Ϊdong ����ֵΪ int  ����Ϊ int ,int  �ĺ���**ָ��** 

int main()
{
	dong P = func;//�Զ�ƥ��  int func(int a,int b)
				//ƥ��ʱҪע�⣺1�����������б�һ��	 2��������������Ҫһ��
	int c = P(1,2); 
	printf("%d\n",c);
 }
