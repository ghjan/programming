#include <iostream>
using namespace std;	
//			short,char								    	  float			���涼��������ת��Ϊ���棬�Ƚϵ�ʱ��ֱ��ת��Ϊ�������ͱȽ� 
//				��												�� 
//Ĭ��ת��     int   ->    long     ->    unsigned     ->     double     	 ���水��ͷ������Ĭ������ת������Ҫ��ʱ���ת 

void test1()
{
	unsigned int a = 1;
	char b = -1;
	a>b?cout<<"a>b"<<endl:cout<<"b>=a"<<endl;		//		b>=a			char  ->  unsigned  ||  int  ->  unsigned
} 
void test2()
{
	unsigned short a = 1;
	char b = -1;
	a>b?cout<<"a>b"<<endl:cout<<"b>=a"<<endl;		//		a>b				char  ->   int  || short   ->   int  
}
void test3()
{
	unsigned int a=20;
    signed int b=-130;
    a>b?cout<<"a>b"<<endl:cout<<"b>=a"<<endl;		//		b>=a			
}
void test4()
{
	
	unsigned int a=20;
 	signed int b=-130;
 	std::cout<<a+b<<std::endl;
//������Ϊ4294967186��ͬ���ĵ���������֮ǰ��a��20��b��ת��Ϊ4294967166������a��b��4294967186
//�����ͳ˷������������ơ�

//�����Ϊsigned int�����ݵ�c=-130��b��������֮�����ʱ��Ӱ��b�����ͣ���������ȻΪsigned int�ͣ�
	signed int c = -130;
	std::cout<<c+30<<std::endl;
//���Ϊ-100��				
//�����ڸ�������˵����������float��double��ʵ���϶����з�������
//unsigned ��signedǰ׺���ܼ���float��double֮�ϣ���Ȼ�Ͳ������з��������޷�����֮��ת���������ˡ�	

//�����ʽ�д��ڷ������ͺ��޷�������ʱ 
//���еĲ��������Զ�ת��Ϊ�޷������� 
}
void test5()
{
	//��˵��΢�������⣺
	unsigned int i=3;
	cout<<i * -1<<endl;						//		4294967293
	cout<<hex<<i*-1<<endl;					//		fffffffd
	cout<<i - 4<<endl;						//		ffffffff
	
	cout<< -1*i + 2 <<endl; 				//		ffffffff
} 
int main()
{
	unsigned int a = 1;
	char b = -1;
	cout<<a<<endl;
	cout<<(unsigned int)b<<endl;
	cout<<(int)b<<endl;
	cout<<"--------------------------"<<endl;
	test1();
	cout<<"--------------------------"<<endl;
	test2();
	cout<<"--------------------------"<<endl;
	test3();
	cout<<"--------------------------"<<endl;
	test4();
	cout<<"--------------------------"<<endl;
	test5();
}
