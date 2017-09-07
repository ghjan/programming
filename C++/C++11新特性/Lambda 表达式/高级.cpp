#include<iostream>
#include<algorithm>
#include<array>

using namespace std;

void main()
{
	array<int, 5> arr = { 1, 2, 3, 4, 5 };
	for_each(arr.begin(), arr.end(), [](int num){cout << num << endl; });

	cin.get();
}


void main7()
{
	int a = 10;
	int b = 9;
	int c = 8;
	[&a, b, c](){a = 100; cout << a << " " << b << "  " << c << endl; }();//a�ɶ���д��bcֻ��
	cout << a << " " << b << "  " << c << endl;

	cin.get();
}


void main6()
{
	int n1 = 10;
	int n2 = 20;

	[=](){cout << n1 << "  " << n2 << endl; }();// = �������ⲿ�����������ǡ�ֻ�ܶ�n1 n2 ���ܸı��ⲿ������ֵ
	[=]()mutable{n1 = 500, n2 = 400; cout << n1 << "  " << n2 << endl; }();//����mutable�Ϳ������ⲿ���������������n1 n2�Ǹ���

	[&](){cout << n1 << "  " << n2 << endl; }();//
	[&](){n1 = 100, n2 = 200; cout << n1 << "  " << n2 << endl; }();// & �ȿ��Է����ⲿ������Ҳ�����޸��ⲿ���� ��
	cout << n1 << "   " << n2 << endl;


	cin.get();
}

