#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct{
	char val;
}Node, *Tree;
Node* a = new Node;

//���ǿ��Ըı��ַ�ϵ�ֵ�����ǲ��ܸı䴫������  �����ĵ�ַ
void test1(Tree t)//ǧ��ע�Ⱑ����������һ������������ǰһֱ��Ϊָ��Ͳ������ˣ�����ʵ�κζ������������ˣ����൱�� Tree t = p;
{
	cout <<t<< endl;

	t = a;

	cout << t << endl;
}
//���ǿ��Ըı��ַ�ϵ�ֵ��Ҳ�ܸı䴫������  �����ĵ�ַ
void test2(Tree &t)//ֻ�����ã����Ǵ������Ķ�����û���κθı�
{
	cout << t << endl;

	t = a;

	cout << t << endl;
}

int main2()
{
	Tree p = new Node;
	test1(p);
	cout << p << endl;

	cout << "-------------------" << endl;

	test2(p);
	cout << p << endl;

	cin.get();
	return 0;
}