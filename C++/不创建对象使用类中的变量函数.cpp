#include<iostream>
using namespace std;

class A{
public:
	void test()
	{
		cout<<"aaaaa"<<endl;
	}
	static void test2()
	{
		cout<<"BBBBBB"<<endl;
	}
	int a;
};

int main()
{
	void (*p2)() = A::test2;
	(*p2)();
	
	void (A::*p)() = A::test;		//�ܸ�ֵ�������ǵ��ò����� 
	cout<<p<<endl; 
	cout<<A::test<<endl;
	
	int A::*p3 = &A::a;				//��vs�лᱨ��vc��gcc�п������������������������岻��� 
}
