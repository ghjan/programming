/*
������ģʽ��Iterator�����ṩһ�ַ���˳�����һ���ۺ϶����еĸ���Ԫ�أ����ֲ���¶�ö�����ڲ���ʾ��
������Ҫ����һ���ۺ϶��󣬶��Ҳ�����Щ������ʲô����Ҫ������ʱ�򣬾�Ӧ�ÿ���ʹ�õ�����ģʽ��
���⣬����Ҫ�Ծۼ��ж��ַ�ʽ����ʱ�����Կ���ȥʹ�õ�����ģʽ��
������ģʽΪ������ͬ�ľۼ��ṹ�ṩ�翪ʼ����һ�����Ƿ��������ǰ��һ���ͳһ�Ľӿڡ�
*/

#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

template<class T>
class MyIterator
{
	T begin, end;
public:
	MyIterator(T t1,T t2)
	{
		begin = t1;
		end = t2;
	}
	bool hasNext()
	{
		if (begin != end)
			return true;
		return false;
	}
	T next()
	{
		T temp = begin++;
		return temp;
	}
};

int main()
{
	int a[] = { 1, 2, 3, 4, 5 };
	vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
	list<int> l(a, a + sizeof(a) / sizeof(a[0]));
	string str = "chen ming dong";
	
	//����
	MyIterator<int*> *it = new MyIterator<int*>(a, a + sizeof(a) / sizeof(a[0]));
	while (it->hasNext())
	{
		int* i = it->next();
		cout << *i << endl;
	}
	delete it;
	cout << "---------------------------------" << endl;
	MyIterator<list<int>::iterator> *it2 = new MyIterator<list<int>::iterator>(l.begin(), l.end());
	while (it2->hasNext())
	{
		auto i = it2->next();
		cout << *i << endl;
	}
	cout << "---------------------------------" << endl;
	MyIterator<vector<int>::iterator> *it3 = new MyIterator<vector<int>::iterator>(v.begin(), v.end());
	while (it3->hasNext())
	{
		cout << *(it3->next()) << endl;
	}
	cout << "---------------------------------" << endl;
	MyIterator<string::iterator> *it4 = new MyIterator<string::iterator>(str.begin(), str.end());
	while (it4->hasNext())
	{
		cout << *(it4->next()) << endl;
	}
	cout << "---------------------------------" << endl;
	system("pause");
	return 0;
}
