#include<iostream>
using namespace std;
class Base
{
public:
    Base()
    {
        Init();
    }
    virtual void Init()
    {
        printf("Base Init\n");
    }
    void func()
    {
        printf("Base func\n");
    }
};
class Derived: public Base
{
public:
    virtual void Init()
    {
        printf("Derived Init\n");
    }
    void func()
    {
        printf("Derived func\n");
    }
};
 
int main()
{
    Derived d;
    ((Base *)&d)->func();
    ///////////////////////////////////////////
    cout<<"------------����--------------"<<endl;
	Derived *dd = new Derived;//ע���ʼ�������ʱ�򣬺�����û���κι�ϵ 
	((Base *)dd)->func(); 
    return 0;
}
