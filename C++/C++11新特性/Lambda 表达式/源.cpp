#include<iostream>
using namespace std;

void main5()
{
	auto fun = [](double a, double b){return a + b; };
	cout << fun(10, 10.2) << endl;
	//								ָ����������
	auto fun2 = [](double a, double b)->int {return a + b; };
	cout << fun2(10, 10.2) << endl;



	cin.get();
}

void main4()
{
	//��һ��()��������б���{}�����塢����()����
	[](char *s, int i){cout << "hello" << "   " << s << "   " << i << endl; }("dong", 20);

	cin.get();
}

void main3()
{
	[]{cout << "hello" << endl; cout << "dong" << endl; }();//����lambda���ʽ

	cin.get();
}

void main2()
{
	//�ֿ�д
	auto fun = [] {cout << "hello" << endl; };//����ָ��
	fun();//���ú���
	cout << typeid(fun).name() << endl;//class <lambda_95d5bca3f836d50802ccb5cfb5d40759>

	cin.get();
}

void main1()
{
	[]{cout << "hello" << endl; }();

	cin.get();
}