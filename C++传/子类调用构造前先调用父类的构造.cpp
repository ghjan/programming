#include <iostream>
using namespace std;

class A{
	public: //û��public �Ĺ��캯�������Ͳ��ܱ����˼̳У�����Ϊ���˼̳еĹ��캯������� 
	A(){
		cout<<"a"<<endl;
	}
};

class B:public A{
	public://û��public �Ĺ��캯�����Ͳ��ܴ������󡣲��㵥�� 
	B(){
		cout<<"b"<<endl;
	}
};

int main()
{
	B b;
	//a
	//b
	//�ȵ��ø��๹�� 
}
