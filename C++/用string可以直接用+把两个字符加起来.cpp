#include<iostream>
using namespace std;
int main()
{
	string a="chen",b="dong",d="abcdefghigk";
	string c=a+b;
	string e(d,2,3);		//�úñȽ��������Ĳ��� 
	string f(d,3);
	cout<<c<<endl;
	cout<<e<<endl;
	cout<<f<<endl;
	cout<<f[2]<<endl;		//���±������� 
 } 
