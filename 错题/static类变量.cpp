#include <iostream>
using namespace std;
/*
static����������ж����У�����һ��������ֵ�ı䣬��������õ��ľ��Ǹı��Ľ��
*/ 
class A
{
public:
	static int i;	
};
int A::i = 1;

int main()
{
	A a;
	A a2;
	a.i++;
	a2.i++;
	cout<<a.i<<endl;
	cout<<a2.i<<endl;
}
