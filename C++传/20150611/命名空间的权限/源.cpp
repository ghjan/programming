#include<iostream>
using namespace std;
//int num = 100000;  ���������������ȫ�ֱ��������ʵľ�������������� num = -100;

namespace n
{
	int num = -100;
}
using namespace n;//ʹ�������ռ䣬ֱ�ӵ���ȫ�ֱ�����ʹ��

//�ڲ㸲�����
namespace dong
{
	int num = 100;
	namespace run
	{
		void show()
		{
			int num = 10;
			cout << num << endl;
			cout << dong::num << endl;
			cout << ::num << endl;//  ����ֱ�ӷ���ȫ�ֱ���
		}
	}
}
using namespace dong;//��仰һ��Ҫ�ŵ������ռ�����


void main()
{
	run::show();

	cin.get();
}