#include<iostream>
using namespace std;
int main()
{
	cout<<"������һ���ַ�(ע����һ���ַ�)"<<endl;
	cout<<cin.get()<<endl;			//�� cin.get������ȡ���з� 
	cin.get();						//���������һ���ַ����Ļس���
	
	char a;
	cout<<"������һ���ַ�"<<endl; 
	a=cin.get();
	cout<<a<<endl;
	cin.get();
	
	cout<<"������һ���ַ���"<<endl;
	char s[20],p[20];
	cin.get(s,20);
	cout<<s<<endl;
	cin.get();						//���������һ���ַ����Ļس���
	
	cout<<"������һ���ַ���"<<endl;
	cin.getline(p,20);				//cin.getline��������з�
	cout<<p<<endl;
	
	return 0;
}
