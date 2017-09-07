#include <iostream>
#include <deque>
#include<algorithm>
using namespace std;

void print(deque<int> d)
{
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl << "----------------------" << endl;
}

//ͷ�壬β�壬ɾ��
void test1()
{
	deque<int> d;
	d.push_back(1);
	d.push_back(2);
	d.push_back(3);

	d.push_front(7);
	d.push_front(8);
	d.push_front(9);

	print(d);

	cout << "ͷ��Ԫ�أ�" << d.front() << endl;
	cout << "β��Ԫ�أ�" << d.back() << endl;

	cout << "ɾ��ͷ��" << endl;
	d.pop_front();
	print(d);

	cout << "ɾ��β��" << endl;
	d.pop_back();
	print(d);

	//����
	deque<int>::iterator it = find(d.begin(), d.end(), '2');
	int index = distance(d.begin(), it);//��������������֮���λ��
	cout << "2���ڵ�λ�ã�" << index << endl;
}