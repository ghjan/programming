#include <iostream>
#include <string>
using namespace std;

class god
{
public:
	virtual void deal(int money)
	{
		if (money < 5000)
		{
			cout << "�ϵۣ���ȥ���ϱ��" << endl << endl;
			return;
		}
		cout << "�ϵ۶��ﲻ����" << endl;
	}
};
class grandfather :public god
{
public:
	void deal(int money)
	{
		if (money < 3000)
		{
			cout << "үү����ȥ����ֻ�" << endl << endl;
			return;
		}
		cout << "үү�ﲻ���㣬��ȥ���ϵ�Ҫ�ɣ�" << endl;
		god::deal(money);
	}
};
class father :public grandfather
{
public:
	void deal(int money)
	{
		if (money < 2000)
		{
			cout << "�ְ֣���ȥ��ˮ��" << endl << endl;
		}
		cout << "�ְְﲻ���㣬��ȥ��үүҪ�ɣ�" << endl;
		grandfather::deal(money);
	}
};
class mother :public grandfather
{
public:
	void deal(int money)
	{
		if (money < 1000)
		{
			cout << "���裺��ȥ����" << endl << endl;
		}
		cout << "����ﲻ���㣬��ȥ��үүҪ�ɣ�" << endl;
		grandfather::deal(money);
	}
};
int main()
{
	mother().deal(4000);

	father().deal(6000);

	system("pause");
	return 0;
}