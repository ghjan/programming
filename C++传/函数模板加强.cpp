#include <iostream>
using namespace std;

template<class T1,class T2>//class��typenameһ�� 
void mySwap(T1& a,T2& b)
{
	T1 c = a;
	a = b;
	b = c;
}

int main()
{
	int a = 48;//ascii�� ��Ӧ �ַ� 0 
	char b = 'A';//ascii�� ��Ӧ ��ֵ 65 
	mySwap<int,char>(a,b);
	cout<<a<<"   "<<b<<endl;//65   0 
}
