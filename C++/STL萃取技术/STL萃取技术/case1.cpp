#include<iostream>
using namespace std;

template<class I, class T>
void func_imp(I iter, T t)
{
	cout << typeid(I).name() << endl;
	cout << typeid(T).name() << endl;
}
template<class I>
inline void func(I iter)
{
	cout << typeid(I).name() << endl;
	func_imp(iter, *iter);//���԰�iter ָ������͸���ȡ����
}
int main1()
{
	int i = 9;
	func(&i);
	system("pause");
	return 0;
}

