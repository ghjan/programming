#include<iostream>
using namespace std;
struct dong				//���������Ҫ��cmd.a   .b  ��ǰ��Ͳ��ܼ�typedef   ����  ���൱��  struct dong ==cmd 
{
	int a;
	char *d;
}cmd;
int main()
{
	cmd.a=10;
	cmd.d ="dongdong";
	cout<<cmd.a <<endl;
	cout<<cmd.d <<endl;		
}
