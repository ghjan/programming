#include <iostream>
#include <map>
#include <string>
using namespace std;
/*
��һ��ɾ��һ��map�е�Ԫ��(��Ҫ�����������ʧЧ����) 
*/ 
void print(map<int, string> &m)
{
	for(map<int, string>::iterator it = m.begin();it != m.end();++it)
	{
		cout<<it->first<<":"<<it->second<<endl;
	}
	cout << "---------------------" << endl;
}
int main()
{
	map<int,string> IntMap;
	for(int i = 0;i<5;++i)
	{
		IntMap[i] = i + '0';
	}
	print(IntMap);
	for(map<int,string>::iterator it = IntMap.begin();it != IntMap.end();/*������������*/)
	{
		if(it->second == "3")
		{
			IntMap.erase(it++);
		}
		else
			it++;
	}
	print(IntMap);
}
