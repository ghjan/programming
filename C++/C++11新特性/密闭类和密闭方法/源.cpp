//����ֹ����̳С���������

class Base final
{
};
class Derived : public Base //�̳��ܱ��࣬�﷨����
{
};

//final����

class Base2
{
	virtual void A() final;
};
class Derived : public Base2
{
	virtual void A(); //��д�ܱշ������������
};

int main()
{

}