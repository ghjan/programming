#include<iostream>
using namespace std;

void test(char &c)//������ò�����д 
{
	cout<<"������&c  "<<c<<endl;
}

//�������д,,ͨ�ã���ֻ�ǲ��ܸ�c��ֵ 
void test2(const char &c)
{
	cout<<"������const char &c  "<<c<<endl;
}

char get()//ע�����ﲻ�Ƿ��ص� ����c    ���Ƿ��صĳ��� 'a'   ��Ϊջ���Ͼͻ��ˣ����ر���û���� 
{
	char c = 'a';
	return c;
}
char &get(int i)
{
	char b = 'B';
	char & c = b; 
	return c;
} 
int  main1()
{
	//test(get());    //��仰�ǲ���ͨ������ġ�������Ϊ  test  �������ַ����� 
	test2(get()); 
	
	
	//test test2 ����ͨ�����롣�� 
	char c = 'A';
	test(c);		//������Կ��ɴ���ȥһ�� 'A'  �ַ����� 
	test2(c);
	
	test(get(1));//���Ǳ��ַ���ֵ��һ�����ã���಻��ͨ������
}








int &pget()//ע�⣬���Ǵ�������ֵ�����ã�������Ҳ�����Ǹ����ã���Ȼ��ñ𷵻����� 
{
	int i =10;
	return i;
}
int main()
{
	int i = pget();
	cout<<i<<endl; 
	cout<<i<<endl; //����û���⣬��Ϊ�����Ǹ�ֵ���ǰ� i ��ֵΪ�� 10��������û�д�����ȥ 
	
	int &ii = pget();//��Ϊ ii Ҳ��һ�����á����õĻ���ջ�ϵı����������Գ������� 
	cout<<ii<<endl;  
	cout<<ii<<endl; //�����ˣ�����Ϊջ���ڴ汻������ 
}
