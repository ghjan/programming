#include <iostream>
#include<algorithm>
#include <list>
using namespace std;

/* list ����ɾ���ر�� */

void print(list<int> l)
{
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl << "----------------------" << endl;
}

void test1()
{
	list<int> l;
	cout << l.size() << endl;

	for (int i = 0; i < 5; i++)
	{
		l.push_back(i);//β�巨
	}
	*l.begin() = 99;
	print(l);

	for (int i = 0; i < 5; i++)
	{
		l.push_front(i);//β�巨
	}
	print(l);

	list<int>::iterator it = l.begin();
	cout << *it << endl;
	it++;
	cout << *it << endl;
	//*it + = 5;  ���󡣲�֧���������

	//����
	l.insert(it, 1000);
	print(l);
	
	//ɾ������
	l.erase(l.begin(), it);//ע�� list ������û������ +  ����l.begin() + 1 �ᱨ��
	print(l);

	l.erase(++l.begin());//ɾ���ڶ���Ԫ��
	print(l);

	

}