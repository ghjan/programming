#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <cstdio>
#include <graphics.h>
#include <conio.h>

using namespace std;

class Mpu
{
public:
	string name;
	string date;
	int No;
	int degree;
};

class Man
{
public:
	void sortPowerAll()
	{
		map<int, Mpu *> powerMap;
		for (auto it = UserMap.begin(); it != UserMap.end(); ++it)
		{
			auto UserVec = it->second;
			powerMap[UserVec[UserVec.size() - 1]->degree] = UserVec[UserVec.size() - 1];
		}
		for (auto it = powerMap.rbegin(); it != powerMap.rend(); ++it)
		{
			cout << " ���õ�����" << it->second->degree << endl << endl;
		}
	}
	int getMonth(string date)
	{
		int start = date.find('-') + 1;
		int end = date.find('-', start);
		string monthStr(date.begin() + start, date.begin() + end);
		stringstream ss;
		int monthInt;
		ss << monthStr;
		ss >> monthInt;
		return monthInt;
	}
	int countPowerUse(string name, int startMonth, int endMonth)
	{
		if (UserMap.empty() || name.empty() || startMonth < 1 || startMonth > endMonth ||
			endMonth > 12 || UserMap.find(name) == UserMap.end())
			return -1;
		vector<Mpu *> userVec = UserMap[name];
		int startPower, endPower;
		for (auto it = userVec.begin(); it != userVec.end(); ++it)
		{
			int month = getMonth((*it)->date);
			if (month == startMonth)
				startPower = (*it)->degree;
			else if (month == endMonth + 1)
				endPower = (*it)->degree;
		}
		return endPower - startPower;
	}
	int getPowerUseByNo(int No, int startMonth, int endMonth)
	{
		int sumPower = 0;
		for (auto it = UserMap.begin(); it != UserMap.end(); ++it)
		{
			vector<Mpu *> userVec = it->second;
			if (No == userVec[0]->No)
				sumPower += countPowerUse(userVec[userVec.size() - 1]->name, startMonth, endMonth);
		}
		return sumPower == 0 ? -1 : sumPower;
	}
	map<int, double> getAllNoPower()
	{
		map<int, double> noPowerMap;
		int sumPower = 0;
		for (auto it = UserMap.begin(); it != UserMap.end(); ++it)
		{
			vector<Mpu *> userVec = it->second;
			if (noPowerMap.find(userVec[0]->No) == noPowerMap.end())
				noPowerMap[userVec[0]->No] = userVec[userVec.size() - 1]->degree;
			else
				noPowerMap[userVec[0]->No] += userVec[userVec.size() - 1]->degree;

			sumPower += userVec[userVec.size() - 1]->degree;
		}
		for (auto it = noPowerMap.begin(); it != noPowerMap.end(); ++it)
		{
			it->second = it->second / sumPower * 360;
		}
		return noPowerMap;
	}
	map<string, vector<Mpu *>> UserMap;
};

class MyGreaphic
{
public:
	void show(map<int, double> anglgMap)
	{
		initgraph(1000, 600);
		setorigin(500, 300);
		//setbkcolor(0xFFFFFF);

		double val = PI / 180;
		double curAngle = 0;

		auto it = anglgMap.begin();
		line(0, 0, 0, -200);
		setcolor(0x4941F2);
		settextstyle(50, 0, "����");
		char *word = new char[20];
		sprintf(word, "%.2lf", it->second / 360);
		outtextxy(-100, -250, word);

		for (++it; it != anglgMap.end(); ++it)
		{
			curAngle += it->second;
			setcolor(0x4941F2);
			settextstyle(50, 0, "����");
			char *word = new char[20];
			sprintf(word, "%.2lf",it->second / 360);

			outtextxy(1.2 * R * sin(curAngle * val), -0.5 * R * cos(curAngle* val), word);

			setcolor(0xFFFFFF);
			line(0, 0, R * sin(curAngle * val), -R * cos(curAngle * val));
		}
		setcolor(0x6FDAFF);
		circle(0, 0, 200);
	}
	const int R = 200;
	const double PI = 3.14159265;
};

int main()
{
	Man *manage = new Man;
	int startMonth, endMonth, No;
	string user;
	cout << "�����룺�û�����¥���ţ��������ڣ�������" << endl;
	while (1)
	{
		Mpu *mpu = new Mpu;
		if (cin >> mpu->name >> mpu->No >> mpu->date >> mpu->degree)
		{
			map<string, vector<Mpu *>>::iterator it = manage->UserMap.find(mpu->name);
			if (it == manage->UserMap.end())
			{
				vector<Mpu *> v(1, mpu);
				manage->UserMap[mpu->name] = v;
			}
			else
			{
				manage->UserMap[mpu->name].push_back(mpu);
			}
		}
		else
			break;
	}
	cin.clear();
	cout << "�Ӹߵ����ų�ÿ���û������õ���" << endl;
	manage->sortPowerAll();

	cout << "ͳ��ĳ�û�ĳ�µ����õ���" << endl;
	cin >> user >> startMonth >> endMonth;
	cout << "�û�����" << user << "��" << startMonth << "�� -- " << endMonth << "�� "
		<< "���õ�����" << manage->countPowerUse(user, startMonth, endMonth) << "��" << endl << endl;

	cout << "ͳ��ĳ¥����ĳ�µ�ĳ�µ����õ���" << endl;
	cin >> No >> startMonth >> endMonth;
	int sumPower = manage->getPowerUseByNo(No, startMonth, endMonth);
	if (sumPower == -1)
	{
		cout << "û���ⶰ¥" << endl;
		return 0;
	}
	cout << "¥�ţ���" << No << "�� " << startMonth << "�� -- " << endMonth << "�� " << "���õ�����" << sumPower << "��" << endl << endl;
	system("pause");

	MyGreaphic g;
	g.show(manage->getAllNoPower());

	
	system("pause");
	return 0;
}
/*
ʯһ�� 1 2016-1-1 300
��˧ 1 2016-1-1 300
Ҧ�� 2 2016-1-1 300
���� 3 2016-1-1 300

ʯһ�� 1 2016-2-1 520
��˧ 1 2016-2-1 510
Ҧ�� 2 2016-2-1 620
���� 3 2016-2-1 550

ʯһ�� 1 2016-3-1 720
��˧ 1 2016-3-1 710
Ҧ�� 2 2016-3-1 820
����3 2016-3-1 750

*/