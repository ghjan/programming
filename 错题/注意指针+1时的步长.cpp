#include <iostream>
using namespace std;

class A{
public:
	long a; 
};
class B : public A{
public:
	long b; 
};

void test(A* data,int i)
{
	data[i].a = 2;			//�൱��  data��ַ + 4 * i;	//��һ�θĵľ��� data + 4 ��long ���� ��ֵ = 2  �ڶ��θĵľ���   data + 4 * i �ϵ�ֵ  ֻ�޸��Ĵ� 
}

//��������һ���ڴ�ֲ�
int main()
{
	B data[4];
	for(int i = 0;i<4;i++)
	{
		data[i].a = 1;
		data[i].b = 2;
	}
	for(int i = 0;i<8;i++)
		cout<<*((long *)(data) + i)<<"\t";//		1       2       1       2       1       2       1       2		���ĳ���a����b��ǰ�� 
} 

// ��𰸣� 2 1 2 1 2 1 2 1 
int main1()
{
	cout<<sizeof(long)<<endl;
	cout<<sizeof(A)<<endl;
	cout<<sizeof(B)<<endl;
	
	B data[4];
	for(int i = 0;i<4;i++)
	{
		data[i].a = 1;			//  a  b  ȫ����ֵΪ 1 
		data[i].b = 1;
		test(data,i);
	}
	for(int i = 0;i<4;i++)
		cout<<data[i].a<<"\t"<<data[i].b<<"\t";//	2       2       2       2       1       1       1       1
	cout<<endl;
	for(int i = 0;i<8;i++)
		cout<<*((int *)(data) + i)<<"\t";	// 		2       2       2       2       1       1       1       1
}
