#include <iostream>
using namespace std;

class A{
	public: 
	A(){
		cout<<"a"<<endl;
		show(); 
	}
	virtual void show()
	{
		cout<<"����"<<endl;
	}
};

class B:public A{
	public: 
	B(){
		cout<<"b"<<endl;
	}
	void show()
	{
		cout<<"����"<<endl;
	}
};

int main2()
{
	B b;
	b.show();
//	a
//	����
//	b
//	����
//1.���ø���Ĺ��캯�����������vptrָ�뱻��ʼ����ָ������麯����
//2.��ִ����ϸ��๹�캯���������vptrָ�뱻��д��ֵ��ָ��������麯���� 
}

//˳��֤���˶�̬ʵ�ֵ�����������ȱһ���� 
int main()
{
	B b;
	cout<<"------------"<<endl; 
	A a = b;
	a.show(); //ע�Ⱑ��������û��ʵ�ֶ�̬������Ϊ��̬����������֮һ�������и���ָ�루���ã�ָ��������� ��  û������ 
	
	A* pa = &b;
	pa->show();//������Ƕ�̬ 
}
