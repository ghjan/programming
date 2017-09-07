#include<iostream>
using namespace std;

//����ӿ� 
class Algorithm
{
public:
	virtual void replace() = 0;
};
//���־�����滻�㷨 
class A_algorithm:public Algorithm{
public:
	void replace()
	{
		cout << "A_algorithm" << endl;
	}
};
class B_algorithm :public Algorithm{
public:
	void replace()
	{
		cout << "B_algorithm" << endl;
	}
};
class C_algorithm :public Algorithm{
public:
	void replace()
	{
		cout << "C_algorithm" << endl;
	}
};

//Cache��Ҫ�õ��滻�㷨 
class Cache
{
	Algorithm *a;
public:
	Cache(Algorithm *a)
	{
		this->a = a;
	}
	~Cache()
	{
		delete a;
	}
	void replace()
	{
		a->replace();
	}
};

enum al{ A, B, C }algorithm;
class Cache2
{
	Algorithm *a;
public:
	Cache2(enum al algor)
	{
		if (algor == A)
		{
			a = new A_algorithm;//�Լ�new  ����Ҫ���㷨��¶��ȥ��������ͨ����ģʽ���
		}
		else if (algor == B)
		{
			a = new B_algorithm;
		}
		else if (algor == C)
		{
			a = new C_algorithm;
		}
	}
	~Cache2() { delete a; }
	void replace()
	{
		a->replace();
	}
};

int main()
{
	//  ��������ַ�ʽ���ͻ�����Ҫ֪����Щ�㷨�ľ��嶨�塣ֻ�����������ַ�ʽʹ�ã����Կ�����¶��̫���ϸ�ڡ�
	Cache(new B_algorithm()).replace();////��¶���㷨�Ķ���

	cout << "----------------" << endl;

	Cache2(C).replace();


	system("pause");
}