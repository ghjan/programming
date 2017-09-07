#include <iostream>
#include <bitset>
#include <typeinfo>
using namespace std;
/*ע��Ǳ궼�Ǵ�0��ʼ*/
int main1()
{
	bitset<100> b;			//��ʼ��ȫ��0 
	cout<<b.test(2)<<endl;  //test( pos ) pos λ�Ƿ�Ϊ1
	b.set(2);				//set( pos ) ��pos λ��1
	cout<<b<<endl;
	
	cout<<b.any()<<endl;	//����λ�Ƿ�Ϊ1
	
	b.set(6);
	cout<<b.count()<<endl;	//ֵ��1 ��λ�ĸ���
	
	cout<<b.size()<<endl;	//λԪ�صĸ���
	
	cout<<b[6]<<" "<<b[7]<<endl;	//[pos] ����pos λ
	
	b.set();				//������λ��1
	cout<<b.count()<<endl;
	
	b.reset(2);				//��pos λ��0
	cout<<b.count()<<endl;
	
	b.reset();				//������λ��0
	cout<<b.count()<<endl;
}

int main()
{
	bitset<10> b(12);		//ʮ����ת��Ϊ�����ƣ��ٺ͸ճ�ʼ���õ�10��0  ���� ������   0000001100
	cout<<b<<endl;
	
	bitset<10> bb;
	bb = 4;					//ֱ�Ӹ�ֵҲ���� 
	cout<<bb<<endl;
	
	bitset<10> b2(012);		//8���� 0000001010
	cout<<b2<<endl;
	
	bitset<10> b3(0xf);		//0000001111
	cout<<b3<<endl; 
	 
	string s = "111000";
	bitset<10> b4(s);		//0000111000
	cout<<b4<<endl;
	
	string s2 = b4.to_string();//������bitset ����ת����string
	cout<<s2<<endl;
	
	unsigned long a = b.to_ulong();//������bitset ����ת����unsigned long �͵�������ʾ
	cout<<a<<endl;
	
	bitset<10> b5 = b | b2;
	bitset<10> b6 = b & b2;
	cout<<b5<<endl;
	cout<<b6<<endl;
	
	cout<<typeid(b5).name()<<endl;
}
