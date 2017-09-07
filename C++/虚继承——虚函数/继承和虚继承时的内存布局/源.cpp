#include<iostream>
using namespace std;
class Parent
{
public:
	int age;
	Parent() :age(10){}
	virtual void f(){ cout << "Parent::f()" << endl; }
	virtual void g(){ cout << "Parent::g()" << endl; }
};
class Child : public Parent
{
public:
	int num;
	Child() :num(6){}
	virtual void f(){ cout << "Child::f()" << endl; }
	virtual void h(){ cout << "Child::h()" << endl; }
	virtual void gc(){ cout << "Child::gc()" << endl; }
};
class GrandChild : public Child
{
public:
	int gpa;
	GrandChild() : gpa(4){}
	virtual void f(){ cout << "GrandChild::f()" << endl; }
	virtual void ggc(){ cout << "GrandChild::ggc()" << endl; }
	virtual void gc(){ cout << "GrandChild::gc()" << endl; }
};

int main()
{
	typedef void(*Func)(void);
	GrandChild temp;
	Parent *p = new GrandChild();
	int ** ptVtab = (int **)(&temp); //����������һ������ָ��ָ������ڴ洢���麯������ڵ�ַ��Ϊʲô��									int�أ����������32λ�Ļ���һ��ָ��
	int i = 0; //ռ��4���ֽڵĴ洢�ռ䣡
	Func f;
	for (i = 0; (Func)ptVtab[0][i] != NULL; i++)//�����ڴ�ռ����ʼλ��
	{
		f = (Func)ptVtab[0][i];
		f();
	}
	cout << (int)ptVtab[1] << endl;//�����ĸ��ֽ�֮���λ�ã�
	cout << (int)ptVtab[2] << endl;
	cout << (int)ptVtab[3] << endl;
	p->f();
	system("pause");
	return 0;
}
/*
GrandChild::f()
Parent::g()
Child::h()
GrandChild::gc()
GrandChild::ggc()
10
6
4
GrandChild::f()
*/