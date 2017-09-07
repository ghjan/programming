#include <iostream>
#include "MyVector.h"
#include <vector>
using namespace std;

class A
{
public:
	int id;
	A(int a) :id(a){ cout << "����" << id << endl; }
	A(const A &a){ this->id = a.id; cout << "copy����" << id << endl; }
	~A(){ cout << "xigou" << id << endl; }
};

void test1()
{
	A a1(1);
	A a2(2);
	vector<A> v;
	v.push_back(a1);
	v.push_back(a2);
	cout << "----------------" << endl;
	vector<A> v2 = v;
	cout << "----------------" << endl;
}
/*
����1		a1
����2		a2
copy����1	push_back�ǽ��еĿ�������  a1
copy����1	�����ڴ棬���ǿ�������	   a1
xigou1		������ǰ�ڴ��ϵ�		   a1
copy����2	��ǰ�ڴ��Ϲ���			   a2
----------------
copy����1
copy����2
----------------
xigou1
xigou2
xigou1
xigou2
xigou2
xigou1
*/
void test2()
{
	A a1(1);
	A a2(2);
	MyVector<A> v;
	v.push_back(a1);
	v.push_back(a2);
	cout << "----------------" << endl;
	MyVector<A> v2 = v;
	cout << "----------------" << endl;
}
/*
����1
����2
copy����1
copy����1
xigou1
copy����2
----------------
----------------
xigou1
xigou2
xigou2
xigou1
*/