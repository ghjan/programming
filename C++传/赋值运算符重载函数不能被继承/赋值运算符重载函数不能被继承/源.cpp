#include <iostream>
using namespace std;

class A1
{
public:
	int operator=(int a)
	{
		return 8;
	}

	int operator+(int a)
	{
		return 10;
	}
};

class B1 : public A1
{
public:
	int operator-(int a)
	{
		return 5;
	}
};

int main1()
{
	B1 v;
	cout << (v + 100) << endl; // OK, print 10
	cout << (v - 100) << endl; // OK, print 5
	//cout << (v = 2) << endl; // Error, ���˸�ֵ��������غ������⣬���е���������غ��������Ա�������̳С�

	system("pause");
	return 0;
}

/*
class Empty{};
������ôд��һ���ģ�
class Empty {
public:
Empty();                        // ȱʡ���캯��
Empty(const Empty& rhs);        // �������캯��

~Empty();                       // �������� ---- �Ƿ�
								// Ϊ�麯��������˵��
Empty& operator=(const Empty& rhs);    // ��ֵ�����

Empty* operator&();             // ȡַ�����
const Empty* operator&() const;
};

*/

