#include <iostream>
#include <string>
#include <map>
using namespace std;

int main1()
{
	map<int, string> ismap;
	ismap.insert(map<int, string>::value_type(1, "dong1"));
	ismap.insert(map<int, string>::value_type(5, "dong5"));
	ismap.insert(map<int, string>::value_type(4, "dong4"));
	ismap.insert(map<int, string>::value_type(3, "dong3"));
	ismap.insert(map<int, string>::value_type(2, "dong2"));

	for (int i = 1; i < 6; i++)
	{
		cout << ismap[i] << endl;
	}

	ismap.erase(4);

	for (map<int, string>::iterator it = ismap.begin(); it != ismap.end(); it++)
	{
		cout << it->first << "\t" << it->second << endl;//key���ֵ�˳���Զ�����
	}

	map<char*, int> m;
	m.insert(map<char*, int>::value_type("dong1", 1));
	m.insert(map<char*, int>::value_type("dong2", 2));
	m.insert(map<char*, int>::value_type("dong3", 3));
	for (map<char*, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << "\t" << it->second << endl;//key���ֵ�˳���Զ�����
	}

	getchar();
	return 0;
}
int main()
{
	map<int, string> ismap;
	ismap[1] = "������1";
	ismap[2] = "������2";
	ismap[3] = "������3";
	for (int i = 1; i <= 3; i++)
	{
		cout << ismap[i] << endl;
	}

	map<string, int> m;
	m["˧��"] = 1;
	cout << m["˧��"] << endl;


	getchar();
	return 0;
}
/*
C++STL��map,set�ĵײ�ʵ��ȫ���õĺ������java,C#������ͬ�����

*/