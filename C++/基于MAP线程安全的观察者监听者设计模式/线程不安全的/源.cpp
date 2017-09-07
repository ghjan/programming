#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <vld.h>
using namespace std;

/*������*/
class Listener
{
public:
	string name;
public:
	Listener(string n) :name(n){}
	virtual void handleMessage(int msgid) = 0;//�ص�����
};
/*����ע������ߵ��û�*/
class Listener1 :public Listener
{
public:
	Listener1(string n) :Listener(n){}
	virtual void handleMessage(int msgid)
	{
		/*�����Լ�����Ȥ����*/
		switch (msgid)
		{
		case 0:cout << name << " recv 0" << endl; break;
		case 1:cout << name << " recv 1" << endl; break;
		default:cout << name << "������Ȥ" << endl;
		}
	}
};
class Listener2 :public Listener
{
public:
	Listener2(string n) :Listener(n){}
	virtual void handleMessage(int msgid)
	{
		/*�����Լ�����Ȥ����*/
		switch (msgid)
		{
		case 0:cout << name << " recv 0" << endl; break;
		case 2:cout << name << " recv 2" << endl; break;
		default:cout << name << "������Ȥ" << endl;
		}
	}
};
class Listener3 :public Listener
{
public:
	Listener3(string n) :Listener(n){}
	virtual void handleMessage(int msgid)
	{
		/*�����Լ�����Ȥ����*/
		switch (msgid)
		{
		case 1:cout << name << " recv 1" << endl; break;
		case 2:cout << name << " recv 2" << endl; break;
		default:cout << name << "������Ȥ" << endl;
		}
	}
};
/*�۲���*/
class Observer
{
public:
	/*Ϊĳһ��������ע��һ����Ϣ*/
	void registerMsg(Listener *listener, int msgid)
	{
		map<int, vector<Listener*>>::iterator it = obserMap.find(msgid);//�鿴��Ϣ�Ƿ��Ѿ�������
		vector<Listener*> v;
		if (it == obserMap.end())//û�б�����
		{
			v.push_back(listener);
		}
		else//�Ѿ������������Ϣ����ôֻ��Ҫ������û�����������
		{
			/*����Ҫ�ж�һ����û���ظ�ע��*/
			v = it->second;
			for (vector<Listener*>::iterator it = v.begin(); it != v.end(); ++it)
				if ((*it) == listener)/*����ҵ�����û��Ѿ�ע��*/
					return;
			v.push_back(listener);
		}
		obserMap[msgid] = v;
	}
	/*���۲쵽��Ϣ���ͷַ���ȥ*/
	void dispatchMsg(int msgid)
	{
		map<int, vector<Listener*>>::iterator it = obserMap.find(msgid);
		if (it != obserMap.end())
		{
			for (vector<Listener*>::iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2)
				(*it2)->handleMessage(msgid);
		}
	}
	map<int, vector<Listener*>> obserMap;
};
int main()
{
	/*���������û�*/
	Listener *l1 = new Listener1("Listener1");
	Listener *l2 = new Listener2("Listener2");
	Listener *l3 = new Listener3("Listener3");
	/*һ��������*/
	Observer obser;

	/*Ϊ�û�ע����Ϣ*/
	obser.registerMsg(l1, 0);
	obser.registerMsg(l1, 1);
	obser.registerMsg(l2, 0);
	obser.registerMsg(l2, 2);
	obser.registerMsg(l3, 1);
	obser.registerMsg(l3, 2);

	obser.registerMsg(l3, 2);//���ظ��ܼ��벻


	int msgid;
	while (cin >> msgid)
	{
		obser.dispatchMsg(msgid);
	}
	delete l1;
	delete l2;
	delete l3;
	return 0;
}