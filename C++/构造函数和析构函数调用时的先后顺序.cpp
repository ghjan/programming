#include<iostream>
#include<cstring>
using namespace std;
class dong1
{
public:
	dong1()
	{
		cout<<"����dong���캯��"<<endl;
	}
	void set(char *p)
	{
		strncpy(name,p,sizeof(name));
	}
	char *get()
	{
		return name;
	}
	char name[20];
	~dong1()
	{
		cout<<"����dong��������"<<endl;
	}
};
class cat:public dong1
{
public:
	cat()
	{
		cout<<"����cat���캯��"<<endl;
	}
	~cat()
	{
		cout<<"����cat��������"<<endl;
	}
	void dis()
	{
		cout<<"è�����֣�"<<get()<<endl;
	}
};
int main()
{
	cat a;
	a.set ("dong");
	a.dis();
	a.set("chen");
	a.dis();
	return 0;
}


