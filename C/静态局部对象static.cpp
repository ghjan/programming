#include<iostream>
using namespace std;
int fun()
{
	static int c=0;	//ֻ��һ��ʼ��cһ��ֵ�������Ժ�ú����Ƿ��ٴε��ã�c�������ٱ����¸�ֵ 
	c++;
	return c;
}
int dong1()
{
	static int c;	//��ʹ������ֵĬ�ϸ�c����ֵ=0���Ժ�����ٴε��øú���Ҳ�����c�ٴθ���ֵ 
	c++;
	return c;
}
int dong()
{
	int a=5;		//ÿ�ε��øú�������Ҫ���¸�ֵa=5;
	a++;
	return a;
}
int main() 
{
	int i,c,a,b;
	for(i=1;i<=10;i++)
	{
	a=fun();
	b=dong1();
	c=dong();
}
	cout<<a<<"  "<<b<<"   "<<c<<endl;
	return 0;
}
