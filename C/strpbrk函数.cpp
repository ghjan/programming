#include <iostream>
#include <cstring> 
using namespace std;

int main()
{
	char *s1= "hello dong nice to meet you";
	char *s2 = "nice";
	char *s3 = strpbrk(s1,s2);//��Դ�ַ�����s1�����ҳ����Ⱥ��������ַ�����s2������һ�ַ���λ�ò����أ����Ҳ����򷵻ؿ�ָ�롣
	if(s3)
		cout<<s3<<endl;
	else
		cout<<"NULL"<<endl;
} 
