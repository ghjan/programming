#include <iostream>
#include <queue>
#include<functional>
using namespace std;

//struct less : public binary_function<int, int, bool>
//{	
//	bool operator()(const int& _Left, const int& _Right) const// functor for operator<
//	{	
//		return (_Left < _Right);// apply operator< to operands
//	}
//};

void test1()
{
	priority_queue<int> p;	//Ĭ�����ֵ����
	//����������д  �ǵȼ۵�
	priority_queue<int, vector<int>, less<int>> p2;//less��һ���������ײ��װ����
	priority_queue<int, vector<int>, greater<int>> p3;//��Ҫfunctionalͷ�ļ�
	for (int i = 0; i < 5; i++)
	{
		p.push(rand() % 100);
		p2.push(rand() % 100);
		p3.push(rand() % 100);
	}

	cout << "��ͷԪ�أ�" << p.top() << endl;

	cout << "+++++++++++++++���ǴӴ�С����+++++++++++++++ " << endl;
	while (p.size() > 0)
	{
		cout << p.top() << "\t";
		p.pop();
	}
	cout << endl << "----------------------" << endl;
	while (p2.size() > 0)
	{
		cout << p2.top() << "\t";
		p2.pop();
	}

	cout << endl << "-------------���Դ�С��������-------------" << endl;
	while (p3.size() > 0)
	{
		cout << p3.top() << "\t";
		p3.pop();
	}
	cout << endl;

}

int main()
{
	test1();
	system("pause");
}
