#include <iostream>
using namespace std;

class Dong{
	public:
		void test()
		{
			cout<<"test"<<endl;
		}
		void test() const
		{
			cout<<"test const Dong"<<endl;
		}
		void test2() const
		{
			cout<<"test2222 const Dong"<<endl;
		} 
};

int main()
{
	Dong d;
	d.test();
	d.test2();
	
	cout<<"----------------"<<endl;
	
	const Dong dd;//��������� ����Ա���� 
	dd.test();
	dd.test2();
}
