#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char a[] = "www.baidu.com/dong.html";
	char *b = strchr(a,'/');
	cout<<a<<endl; 
	cout<<b<<endl;
	++b;//�����Ϳ��Ի���ļ��� 
	cout<<b<<endl;
}


