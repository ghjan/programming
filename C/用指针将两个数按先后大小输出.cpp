#include<iostream>
using namespace std;
int main()
{
	int t,a=2,b=3,*p,*p1=&a,*p2=&b;
	cout<<"a="<<*p1<<"b="<<*p2<<endl;
	p=p2;		//���ֵ����ǵ���p1��p2������a���Ƕ���b������ 
	p2=p1;
	p1=p;
	cout<<"a="<<*p1<<"b="<<*p2<<endl;
	t=*p1;		//���ֵ�����ֱ�ӵ���a��b��ֵ�� a��Ϊ�� 
	*p1=*p2;
	*p2=t;
	cout<<"a="<<*p<<"b="<<*p2;
}
