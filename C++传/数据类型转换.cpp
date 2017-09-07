#include <iostream>
#include <string>
using namespace std;

//dynamic_cast�ܹ�Ӧ����ָ��ת����
//����ָ��ת���ɸ���ָ��
class A
{
	public:
		void run()
		{
			cout<<"A"<<endl;
		}
};
class B:public A
{
	public:
		void run()
		{
			cout<<"B"<<endl;
		}
};
int main0()
{
	B* b = new B;
	b->run();
	A* a = b;
	a->run();
	dynamic_cast<A*>(b)->run();
}

int main1()
{
	//printf�����Զ�������������	
	//printf("%d",10.2);
	//printf("%f",1); 
	
//	Static_cast����ת����������࣬���Դ�����ת���ɸ��ࡣҲ�ܴӸ���ת�����࣬�������ת���ĸ���ָ�루���߸������ã���ָ��Ķ����������ģ�
//	��ô��û�����⣻���������ָ��Ķ��󲢲���������ô�����runtime����
//	Static_cast�����dynamic_cast���ԣ�������ת��ָ������ã�����Ӧ�����κ��ܹ���ʽת���������

	printf("%d",static_cast<int>(10.2));
	
}
int main2()
{
//	reinterpret_cast
//��1��   Int��ָ��֮����໥ת����
//��2��   �޹�����ָ��֮���ת����
//��3��   ����ָ��֮���ת��
	int *pint = new int(2);
	char *pchar = reinterpret_cast<char*>(pint);
	
	for(int i = 0;i<4;i++)
	{
		cout<<*(pint + i)<<"   "<<reinterpret_cast<void*>(pint + i)<<endl;
	}
	cout<<endl;
	for(int i = 0;i<4;i++)
	{
		cout<<static_cast<int>(*(pchar + i))<<"   "<<reinterpret_cast<void*>(pchar + i)<<endl;
	}
}
int main()
{
//	const_cast���������֣�����ȥ�������ڶ����ϵ�const��volatile��
	int a = 47;
	const int* i = &a;
	int* c = const_cast<int*>(i);
	cout<<*c<<endl;
}

