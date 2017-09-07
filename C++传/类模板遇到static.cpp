#include <iostream>
using namespace std; 

template<class T>
class A{
	public:
		T a;
		static int s;
};

//���Ҫ��  ��ģ���е�static ��Ա��ʼ��������Ҫ���� 
template<class T>
int A<T>::s = 1; 

int main()
{
	A<int> a1;
	A<int> a2;
	
	A<char> b1;
	A<char> b2;
	
	a1.s++;
	b1.s += 48;
	
	cout<<a2.s<<endl;//���ǿ��Կ�������a1  a2 ����һ��static  int s
	
	cout<<b2.s<<endl;//���ǿ��Կ�������a ϵ�к� bϵ�� �õĲ���һ��static int s    ��Ϊc++�������������������࣬һ����int�����ģ���һ����char������ 
	
}
