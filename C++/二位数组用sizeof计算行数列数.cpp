#include<iostream>
using namespace std;
int main()
{
	int a[2][3]={{1,2,3},{9,8,7}};
	int row=sizeof(a)/sizeof(a[0]);		//sizeof(a)��ʾ��������ռ�ڴ��С����sizeof(a[0])��ʾһ��Ԫ����ռ�ڴ� 
	int column=sizeof(a[0])/sizeof(int);	//sizeof(int)��ʾ�õ�һ��IntԪ�صĴ�С 
	cout<<row<<"\t"<<column<<endl;
 } 
