#include<iostream>
using namespace std;

//1.���õ�ʱ����룬�����õ�ʱ�򲻱��룬��Ҳ����˵�����õ�ʱ�򲻻����﷨����
//2.����ģ�����壬ͨ�ã�����
//3.ԭ������������ģ�庯��
//4.ǿ����ģ�� <>
template<class T>		//ģ�壨template��
T add(T a, T b)
{
	cout << "����T" << endl;
	return a + b;
}
double add(double a, double b)
{
	cout << "����double" << endl;
	return a + b;
}
void main1()
{
	cout << add(1, 2) << endl;
	cout << add('1', '2') << endl;//����ֵ��һ��char
	cout << '1' + '2' << endl;// ��1����ascii��Ϊ 49  ��2��Ϊ50   ��c��Ϊ99
	cout << '1'<< endl;
	cout << '2' << endl;

	cin.get();
}
void main2()
{
	cout << add(1.0, 2.0) << endl;//ԭ������������ģ�庯��
	cout << add<double>(1, 2) << endl;//�����Ϳ��Ե������庯��

	system("pause");
}