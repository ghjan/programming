#include <iostream>
using namespace std;

//#define����е�#�ǰѲ����ַ�������##����������������Ϊһ�����塣
 
#define Str(A) #A		//�������԰��κα�����ת��Ϊ�ַ���

#define Cat(A,B) A##B()
#define Cat2(A,B) A##B

class Dong
{
public:
	void test()
	{
		cout<<"test"<<endl;
	}
	void test2()
	{
		cout<<"test2"<<endl;
	}
	void testYou()
	{
		cout<<"testYou"<<endl;
	}
};
int main()
{
	Dong dong;
	cout<<Str(dong)<<endl;	//�κα�����ת��Ϊ�ַ���
	
	Cat(dong.test,You);
	Cat(dong.test,2);
	Cat(dong.test,);
	
	
	
	
}
