#include <iostream>
using namespace std;

/*�ڶ���*/
class A
{
public:
	static A *getInstance()
	{
		static A *instance = new A;
		return instance;
	}

	void show(){ cout << "��" << endl; }
private:
	~A(){ cout << "����" << endl; }
	A(){ cout << "gouzhao" << endl; }
};
/*�����ݶ�  ��vs�ϳ��������ʱ������*/
class A2
{
public:
	static A2 &getInstance()
	{
		static A2 instance;
		cout << (void *)&instance << endl;
		return instance;
	}
	void show(){ cout << "��" << endl; }
	//~A2(){ cout << "����" << endl; }//�����������빲��
private:
	A2(){ cout << "gouzhao" << endl; }
};

int main1()
{
	A *a = A::getInstance();
	a->show();

	system("pause");
	return 0;
}
int main()
{
	A2 a = A2::getInstance();
	a.show();

	system("pause");
	return 0;
}