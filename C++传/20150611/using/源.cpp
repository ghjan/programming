#include<iostream>
using namespace std;

//C++��usingȡ��typedef
using DB = double;//c++������
using array = int[10];
typedef void(*PFD)(double);            // ���y�Z��
using PFD = void(*)(double);           // �����Z��

namespace dong
{
	template<class T> 
	T add(T a, T b)
	{
		using t = T;//��ģ��ȡ����
		t c = a + b;
		return c;
	}

};

void main()
{
	cout << dong::add(1, 2) << endl;

	cin.get();
}

void main1()
{
	cout << sizeof(DB) << endl;
	cout << sizeof(array) << endl;

	cin.get();
}