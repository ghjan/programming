#include<iostream>
using namespace std;

namespace all
{
	namespace V2014
	{
		void fun()
		{
			cout << "V2014" << endl;
		}
	}
}
namespace all
{
	namespace V2015//����Ĭ�ϰ汾��ԭ��inline���൱����all��ֱ��չ����
	{
		void fun(int a)
		{
			cout << "V2015" << endl;
		}
	}
}


void main()
{
	all::V2014::fun();
	all::V2015::fun(1);
//	all::fun();//Ĭ�ϰ汾

	cin.get();
}