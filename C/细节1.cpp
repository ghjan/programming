#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	char i = 128;//ascii��  ��Χ�� 0 - 127 
	unsigned int a = i;//�Ȱ� i ��Ϊ int == -128  �ٰ� int ��Ϊ unsigned int (������ unsigned int ��ǳ���) 
	
	printf("%d\n",i); 
	printf("%u\n",a); 
	
	if(a==128)
	cout<<"yes"<<endl;
	else
	cout<<"no"<<endl;
}
