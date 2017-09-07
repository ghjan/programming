#include <iostream>
/*
ʹ�þ���̬��ʵ�ֶ���̬
��������һ����ģ��Ԫ��̣�Template Metaprogramming���г����ı�׼��̼��ɡ�
	��C++�У����Խ���ģ����ʵ���������������֧�ֶ���̬���ƵĹ������ԡ�������C++������֧�ֶ���̬��ʽ��
*/


//����̬
//class Base 
//{
//public:
//     virtual void method() = 0;
//     virtual ~Base() {}
//};
//class Derived : public Base
//{
//	public:
//		virtual void method()
//		{
//			std::cout<<"Derived"<<std::endl;
//		}
//};
//class Derived2:public Base
//{
//public:
//	virtual void method(){
//		std::cout << "Derived2" << std::endl;
//	}
//};
//int main(){ 
//    Base *pBase = new Derived;
//    pBase->method(); // ���:"Derived"
//    delete pBase;
//    Base *pBase2 = new Derived2;
//    pBase2->method(); // ���:"Derived2"
//    delete pBase2;
//    
//    return 0;
//}
/*
������ʹ��CRTP��Curiously Recurring Template Pattern����ʵ�ֶ��������Ӧ���ܵľ���̬���룺
*/
template <class Derived>
class Base {
public:
	void method()
	{
		static_cast<Derived*>(this)->implementation();//�����ַ�ʽ�����̬ 
	}
};
class A : public Base<A> {
public:
     void implementation()
	 {
    	std::cout << "A" << std::endl;
     }
};
class B : public Base<B> {
public:
	void implementation()
	{
		std::cout << "B" << std::endl;
	}
};
int main()
{
    Base<A> *pBase = new Base<A>;
    pBase->method(); 
    delete pBase;
    
    Base<B> *pBase2 = new Base<B>;
    pBase2->method();
    delete pBase2;
    
    return 0;
}
