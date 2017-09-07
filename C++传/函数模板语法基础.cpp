#include <iostream>
#include <typeinfo>
#include<algorithm>
using namespace std;

//һ��ʼ���ǳ�����ԭ������c++���治����swap��Ϊ���������Ѿ���  algorithm ���ͷ�ļ������ˣ����ǿ���ֱ�ӵ��� 
//template<typename T>
//void swap(T& a,T& b)
//{
//	T c = a;
//	a = b;
//	b = c;
//	cout<<typeid(a).name()<<endl;
//}
int main1()
{
	int a = 1;
	int b = 2;
	swap(a,b);
	char c = 'c',d = 'd';
	swap(c,d);
	cout<<a<<"   "<<b<<endl;
	cout<<c<<"   "<<d<<endl;
}

/*template����c++��������������Ҫ���з��ͱ�� 
  typename ����C++������ T��һ���������ͣ���Ҫ���� 
*/

template<typename T>
void mySwap(T& a,T& b)
{
	T c = a;
	a = b;
	b = c;
	cout<<typeid(a).name()<<endl;
}
//void dong(T& a)   //template ֻ����һ��������������������Ǵ�� 
//{}
int main()
{
	int a = 1,b = 2;
	mySwap(a,b);
	cout<<a<<"   "<<b<<endl;
	
cout<<"------------------"<<endl;
	
	//���ͱ�̺���ʹ�ã������ַ���
	 
	 //1.�Զ������Ƶ�
	char c = 'c',d = 'd';
	mySwap(c,d);
	cout<<c<<"  "<<d<<endl;
	
	//2.�������͵���
	mySwap<int>(a,b);
	cout<<a<<"   "<<b<<endl;
	
}

