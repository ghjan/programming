#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void print(vector<T> &v)
{
	for (vector<T>::iterator it = v.begin(); it != v.end(); ++it)
		cout << *it << " ";
	cout << endl;
}

void test9()
{
	cout << "--------test9---------" << endl;
	vector<int> v;
	for (int i = 0; i<6; ++i)
		v.push_back(i);
	print(v);

	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		/*
		if (*it == 3)
			v.erase(it); 
		
		������erase()��Iter��������ʧЧ�ˣ������һҰָ�롣���Ӹ�P���ﲻ�����ص�����һ��Ԫ�صĵ�����
		*/
	}

	//���ַ������
	for (vector<int>::iterator it = v.begin(); it != v.end();)
	{
		if (*it == 3)
		{
			it = v.erase(it);//���ص�����һ��Ԫ�صĵ�����
			cout << "���ص�����һ��Ԫ�� : " << *it << endl;
		}
		else
			++it;
	}
	print(v);
}