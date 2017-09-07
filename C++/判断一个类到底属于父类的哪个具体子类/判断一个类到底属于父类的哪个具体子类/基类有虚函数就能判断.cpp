#include <iostream>
using namespace std;

/*
����ʱ����ʶ��RTTI���ص����£�
��1������ͨ������ָ��ʶ������ָ��������ʵ��������
��2��RTTI���뽨�����麯���Ļ�����
��3��
Movable * p = new Bus();
cout<<typeid(*p).name()<<endl;//��ӡ���ΪBus������ָ��ָ��Ķ��������
cout<<typeid(p).name()<<endl;//��ӡ���ΪMovable,����ָ�뱾�������
(4)  Movable * obj;
Bus bus = dynamic_cast<Bus&>(*obj);//��ȷ
Bus bus = dynamic_cast<Bus*>(obj);//��ȷ
Bus bus = dynamic_cast<Bus>(*obj);//���󣬴�����ϸ��Ϣ���£�

dynamic_cast��ʹ��˵����
��1��ֻ��������ָ������õ�ת����������ָ�������ת��Ϊ����ָ�������
��2��Ҫת���������б�������麯��
��3�����ת���ɹ������صľ�������ĵ�ַ�����ת��ʧ�ܣ�����NULL
*/

class D1;
class D2;

class B
{
public:
	virtual void test()			//������һ���麯��  ������̬
	{
	}
	static void dong(B* b)
	{
		if (typeid(*b).name() == typeid(D1).name())
		{
			cout << "����D1�����" << endl;
		}
		else if (typeid(*b).name() == typeid(D2).name())
		{
			cout << "����D2�����" << endl;
		}
	}
};
class D1 : public B
{};
class D2 : public B
{};
int main()
{
	B* b1 = new D1;
	B* b2 = new D2;
	cout << typeid(b1).name() << endl;//class B *			ָ���� B* ����
	cout << typeid(*b1).name() << endl;//class D1			������ָ�����D1�ģ�*b1����class D1��
	cout << typeid(*b2).name() << endl;

	B::dong(b1);
	B::dong(b2);

	system("pause");
	return 0;
}
/*
������������������������������ ���������һ���麯��

class B *
class D1
����D1�����
����D2�����
*/