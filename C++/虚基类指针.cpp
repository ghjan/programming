#include <iostream>
using namespace std;  
//�ҵ���gcc��64λ�İ汾��ûЧ��������֪��ɶԭ�򣩡��������뿴vs�еĴ��롣������̳С����麯���� 
class A{
	
};
class B1 : virtual public A{			//��һ�������     ��һ�����ָ�룬�洢������ַ 
	
};
class B2 : virtual public A{
	
};
class C1 : virtual public B1{
	
};
class C2 : virtual public B1{
	virtual void b1()
	{
		
	}
};
int main()
{
	cout<<"һ��ָ���С\t"<<sizeof(int*)<<endl;
	cout<<"A\t"<<sizeof(A)<<endl;
	cout<<"B1\t"<<sizeof(B1)<<endl;
	cout<<"C1\t"<<sizeof(C1)<<endl;
	cout<<"C2\t"<<sizeof(C2)<<endl;
}
