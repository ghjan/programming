#include<iostream>
using namespace std;
//��ָ��  ���� 
void swap1(int *a,int *b)
{
	int 
	t = *a;
	*a = *b;
	*b = t;
}
//������ 
void swap2(int &a,int &b)
{
	int 
	t = a;
	a = b;
	b = t;
}
int main()
{
	int a = 1 , b = 2;
	
	swap1(&a,&b);
	cout<<"a = "<<a<<endl<<"b = "<<b<<endl;
	
	swap2(a,b);
	cout<<"a = "<<a<<endl<<"b = "<<b<<endl;
}
