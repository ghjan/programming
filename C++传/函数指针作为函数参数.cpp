#include <iostream>
using namespace std;

void MyFunc(int a,int b)
{
	cout<<"a = "<<a<<"   b = "<<b<<endl; 
}

//��һ�ַ��� 
void MyOp1(void (dong)(int,int))//����һ��������ȥ����ʵ���Ǵ���һ�������׵�ַ��ȥ��
{
	cout<<"--------------"<<endl;
	dong(520,20);
}
//�ڶ��ַ��� ��only add typedef ��void(*)(int,int)�����ĺ���  ȡ��һ���������ѣ� 
typedef void(*Func)(int,int);
void MyOp2(Func dong)
{
	cout<<"--------------"<<endl;
	dong(5200,200);
}

//�����������壺
void MyFunc2(int a,int b) 
{
	cout<<"hello dong "<<a<<"   "<<b;
}
 
int main()
{
	MyOp1(MyFunc);//MyFunc���Ǻ����׵�ַ  ����������һ������ָ�� 
	MyOp2(MyFunc);
	
	MyOp1(MyFunc2);//��������ڣ�ֻҪ����������void ������ int��int �Ϳ��Դ���ȥ��Ȼ����� 
} 
