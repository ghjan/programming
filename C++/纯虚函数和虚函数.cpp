#include <iostream>
using namespace std;
class Chen{
	public:
		virtual void test();			//�麯���������� ����Ҫʵ����(���Ը���)������ �������ʵ���� 
		virtual void test2() = 0;		//���麯���������� ����ʵ���������븲�ǣ������� ���಻��Ҫʵ����
};
void Chen::test(){
	cout<<"chen"<<endl;
}
class Ming:public Chen{
	public:
		void test() override{
			cout<<"ming"<<endl;
		}
		void test2() override{
			cout<<"ming2"<<endl;
		}
};
int main()
{
	Ming ming;
	ming.test();
	ming.test2();
}
