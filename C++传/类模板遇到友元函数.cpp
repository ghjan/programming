#include <iostream>
using namespace std;
//Ҫ��vs�е��� 

//��Ҫ��A ������һ����ģ�����Ԫ����������������ǰ�����   ��  �� ���� ������
template<class T>
class A;

template<class T>
void sub(A<T> &a, int i);

template<class T>
A<T> operator+(A<T> &a1, A<T> &a2);

template < typename T >
class A
{
	friend A operator-<T>(A &a1, A &a2);
	friend A operator+<T>(A &a1, A &a2);
	friend void add(A<int> &, int);//��Ԫ���������ⲿ����Ԫ�����������û���κι�ϵֻ�ǣ���Ԫ�������Է���������е��κζ��� 
	friend void sub<T>(A &, int);//��ģ�����Ԫ����
	T age;
public:
	A(){}
	A(T a)
	{
		age = a;
	}
	void show()
	{
		cout << age << endl;
	}
};

template<class T>
A<T> operator-(A<T> &a1, A<T> &a2)
{
	A<T> tmp(a1.age - a2.age);
	return tmp;
}

void add(A<int> &a, int i)
{
	a.age += i;
	//cout << "hello" << endl;
}

template<class T>
A<T> operator+(A<T> &a1, A<T> &a2)//������������� add����֮ǰʵ�֡�����Ȼ�ͱ�������֪������Ϊʲô
{								//Ҳ���԰������������add����֮�󣬵��Ǳ�������ǰ�����к�������
	A<T> tmp(a1.age + a2.age);//�²⣺���ܷ���add�����ԭ�������ڴ����Ѿ�����<int>�����ˣ�����֮�󲻻��ٴ���A�࣬����֮ǰ��A�ಢ����ʶ+�������
	return tmp;				//���񣬲���ʶ sub �������һ������Ҫ����ǰ����к�������������֪���������
}							//���֣�ֻҪadd��������A�����κζ�������ô�Ͳ������ ����ʶ + ������ţ������൱��

template<class T>
void sub(A<T> &a, int i)
{
	A<T> c(a.age - i);
	a.age = c.age;
}

int main11()
{
	A<int> a(10);
	A<int> b(50);
	A<int> c = b - a;
	c.show();

	A<int>d = b + a;
	d.show();

	cin.get();
	return 0;
}

int main22()
{
	A<int> a(10);
	add(a, 1000);
	a.show();

	sub(a, 20);
	a.show();

	cin.get();
	return 0;
}

int main()
{
	A<int> a(10);
	add(a, 1000);
	a.show();

	sub(a, 20);
	a.show();

	A<int> b(50);
	A<int> c = b - a;
	c.show();

	A<int>d = b + a;
	d.show();


	cin.get();
	return 0;
}
