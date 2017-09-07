#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>
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
class Listener1:public Listener
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
	void registerMsg(weak_ptr<Listener> listener, int msgid)
	{
		map<int, vector<weak_ptr<Listener>>>::iterator it = obserMap.find(msgid);//�鿴��Ϣ�Ƿ��Ѿ�������
		vector<weak_ptr<Listener>> v;
		if (it == obserMap.end())//û�б�����
		{
			v.push_back(listener);
		}
		else//�Ѿ������������Ϣ����ôֻ��Ҫ������û�����������
		{
			/*����Ҫ�ж�һ����û���ظ�ע��*/
			/*Ҳ�������̰߳�ȫ*/
			v = it->second;
			for (vector<weak_ptr<Listener>>::iterator it = v.begin(); it != v.end(); ++it)
			{
				shared_ptr<Listener> p = (*it).lock();
				if (!p)
					return;
				if (p == (shared_ptr<Listener>)listener)/*����ҵ�����û��Ѿ�ע��*/
					return;
			}
			v.push_back(listener);
		}
		obserMap[msgid] = v;
	}
	/*���۲쵽��Ϣ���ͷַ���ȥ*/
	void dispatchMsg(int msgid)
	{
		map<int, vector<weak_ptr<Listener>>>::iterator it = obserMap.find(msgid);
		if (it != obserMap.end())
		{
			for (vector<weak_ptr<Listener>>::iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2)
			{
				/*�̰߳�ȫ*/
				shared_ptr<Listener> p = (*it2).lock();
				if (p)
				{
					p->handleMessage(msgid);
				}
			}
		}
	}
	map<int, vector<weak_ptr<Listener>>> obserMap;
};
/*
1.���������ʱ���ã�ǿ����ָ��shared_ptr
2.��ָ��й¶������߳�ʱ�ã�������ָ��weak_ptr
3.�ڱ���߳���ʹ���������ָ�룬��Ҫ��������ָ��ת��Ϊǿ����ָ��
4.����.lock()����Ϊ�գ�˵�������������ڱ���߳����Ѿ���������
ֻ�����C++���������̰߳�ȫ�������̰߳�ȫ����û�н����
*/
int main()
{
	/*�߳�1*/
	/*���������û�*/
	shared_ptr<Listener> l1(new Listener1("Listener1"));
	shared_ptr<Listener> l2(new Listener2("Listener2"));
	shared_ptr<Listener> l3(new Listener3("Listener3"));
	/*һ��������*/
	Observer obser;

	/*Ϊ�û�ע����Ϣ*/
	obser.registerMsg(l1, 0);
	obser.registerMsg(l1, 1);
	obser.registerMsg(l2, 0);
	obser.registerMsg(l2, 2);
	obser.registerMsg(l3, 1);
	obser.registerMsg(l3, 2);
	
	/*�߳�2*/
	int msgid;
	while (cin >> msgid)
	{
		obser.dispatchMsg(msgid);
	}
	return 0;
}