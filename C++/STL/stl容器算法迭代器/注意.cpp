#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
class Student3
{
public:
	string name;
	Student3(string _name)
	{
		name = _name;
	}
	Student3(const Student3 &s)
	{
		cout << "�������� ���ǣ�" << s.name << endl;
		//name = s.name;//ǳ����
		name = s.getName();//һ��ʼ��������������Ǳ�����Ϊconst�����ǲ����Ե������еķ�const��Ա����
	}
	string getName() const//ԭ������Ҫ�� const
	{
		return name;
	}
};