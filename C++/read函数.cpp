#include<iostream>
using namespace std;
int main()
{
	char data[80];
	cin.read(data,80);
	data[cin.gcount ()]='\0';//��ctrl+z�س��������루���������һ�����룩 
	
	cout<<endl<<data<<endl;
	cout<<"---------------------"<<endl;
	cout.write(data,80);	//���������ctrl+zҲ�����    ��������������� 
	cout<<endl;
	return 0;
}
