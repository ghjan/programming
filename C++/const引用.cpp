#include<iostream>
using namespace std;
int main()
{
	const int &b = 1;		//���������� 
	cout<<"b = "<<b<<endl;
	
	//b = 2;���ܸı�b��ֵ
	//�õ�ַ
	int *p = (int *)&b;
	*p = 2;					// ���� ô ��Ȼ�� ������1�� ��Ϊ �� 2   ˵�� b ���õĲ����ǳ��� 1��ֵ 
	 
	cout<<"b = "<<b<<endl;
	
	//���治�� ���ã���a == ������1�� 
	const int a = 1;
	int *q = (int *)&a;
	*q = 2;	 					//����ȡ��ַҲ���ܸı�   ������1��   ��ֵ 
	cout<<"a = "<<a<<endl;
	
}
