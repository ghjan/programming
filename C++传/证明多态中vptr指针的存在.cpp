#include <iostream>
using namespace std;

class A{
	public:
		void printf()
		{
			cout<<"hello"<<endl;
		}
};

class B{
	public:
		virtual void printf()
		{
			cout<<"hello"<<endl;
		} 
};

int main()
{
	cout<<sizeof(A)<<endl;
	cout<<sizeof(B)<<endl;//��vs����4 ����gcc����8��������������֤�� �����Ƕ����麯��ʱ c++�������� �����Զ������һ��������vptrָ�룬ָ��һ���麯���� �� 
}
