#include <iostream>
using namespace std;

//�����쳣�����壺1.�����ҳ�����
				//2.�ó�����ΪһЩ�ɼ����쳣���������������������Ӧ�Ĵ�ʩ���Ͳ���������ļ������� 

int div(int a,int b)
{
	try{
		if(b == 0)
		{
			throw 1;
		}
		if(a == 0)
		{
			throw 2;
		}
		return a/b;
	} catch(int code){
		if(code == 1)
		{
			cout<<"����������Ϊ0"<<endl;
		}
		if(code == 2)
		{
			cout<<"��������Ϊ0"<<endl;
		}
		return 0;
	}
}

int main()
{
	div(0,0);
	cout<<"-------------"<<endl;
	div(0,1);
}
