#include<iostream>
using namespace std;
template<class t,int n>		//���������������Լ�Ҫ��   ��Ҫ����ĸ�ʽ 
t max(t a[n])
{
	t b=a[0];
	for(int i=1;i<n-1;i++)
	{
		if(b<a[i])
		{
			b=a[i];
		}
	}
	return b;
}
int main()
{
	int a[]={5,8,9,6,3,5};
	double b[]={1.1,9.7,5.9,2.4};
	int c=max<int,6>(a);			//��ģ��   
	double d=max<double,4>(b);
	cout<<c<<"  "<<d<<endl; 
}
