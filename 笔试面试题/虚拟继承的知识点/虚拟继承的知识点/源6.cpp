#include <iostream>
using namespace std;
class a
{
	int arr[20];
	virtual void test();
};
class b :public virtual a
{
	/*������a�е�arr[20]��vptrָ��  ���̳й���*/
	int bb;
	/*���溯��ֻ����һ��ָ��*/
	virtual void fff();
	virtual void ggg();
	virtual void hhh();
};

void test7()
{
	cout << sizeof(a) << endl;
	cout << sizeof(b) << endl;
	cout << "-------------------------------------" << endl;
}

/*
84
96
*/