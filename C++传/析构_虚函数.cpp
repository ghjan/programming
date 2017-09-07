#include <iostream>
using namespace std;

class A{
	public: 
	~A()
	{
		cout<<"A��������"<<endl;
	}
};

class C{
	public: 
	virtual ~C()					//��Ϊ�˵���һ�������ָ��ɾ��һ��������Ķ���ʱ������������������ᱻ���á�
	{
		cout<<"C��������"<<endl;
	}
};

class B:public A,public C{
	public: 
	~B()
	{
		cout<<"B��������"<<endl;
	}
};

void Del1(A* a)
{
	delete a;
 }
void Del2(C* c)
{
	delete c;//�����ָ��ɾ��һ��������Ķ�������������������ᱻ���á�
}

int main1()
{
	B* b = new B;
	Del1(b);
	cout<<"--------------"<<endl;
	B* bb = new B;
	cout<<"--------------"<<endl;
	Del2(bb);							//���ۺ��������ô�࣬������Ϊ��C������������������������м̳еĻ������������������ִ��һ�� 
	cout<<"--------------"<<endl;
//	B��������
//	A��������
 } 
 
 //����  ���Ż���򵥣� 
 class D : public C{
 	public:
	 ~D(){
	 	cout<<"D��������"<<endl;
	 } 
 }; 
 int main()
 {
 	D* d = new D;
 	Del2(d);
	cout<<"--------------"<<endl; 	
 	C* c = new D();
 	delete c;
  } 
