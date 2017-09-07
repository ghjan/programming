#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(vector<int> v)
{
	for (int i = 0; i < 10; i++)
	{
		cout << v[i] << "\t";
	}
	cout << endl;
}

void myPrint(int &v)
{
	cout << v << "  dong  ";
}

int mySort(const int &a, const int &b)
{
	return a > b;//�Ӵ�С����
}

int main()
{
	vector<int> v(10);

	for (int i = 0; i < 10; i++)
	{
		v[i] = rand() % 10;
	}

	print(v);

	for_each(v.begin(), v.end(), myPrint);//�Զ����������ӡ

	cout << endl;

	sort(v.begin(), v.end(), mySort);//�Զ�������

	print(v);

	cin.get();
}