#include<iostream>
using namespace std;

enum word{ hello, now };
class Frog;
//������
class Prince
{
public:
	virtual void currentState(Frog*, enum word){}
};
//������
class Frog
{
	Prince* prince = NULL;
public:
	void setState(Prince *prince)
	{
		if (this->prince != NULL)
			delete this->prince;
		this->prince = prince;
		�������();
	}
	void �������()
	{
		cout << "��ð�����" << endl;
		prince->currentState(this, hello);
		���ڼ�������();
	}
	void ���ڼ�������()
	{
		cout << "���ڼ������ˣ�" << endl;
		prince->currentState(this, now);
	}
};
//���ӵ�״̬
//����
class noon :public Prince
{
	void currentState(Frog* frog, enum word w)
	{
		switch (w)
		{
		case hello: cout << "С�����ֿ�������" << endl; break;
		case now: cout << "����������" << endl;
		}
	}
};
//����
class morning :public Prince
{
	void currentState(Frog* frog, enum word w)
	{
		switch (w)
		{
		case hello:cout << "С������ð�" << endl; break;
		case now:cout << "����������" << endl; frog->setState(new noon);
		}
	}
};


int main2()
{
 	Frog().setState(new morning);
	

	system("pause");
	return 0;
}