#include <iostream>
using namespace std;
//���Լ��ı������ϵ���ûʲô�����ȥ��������ţ�ͱ������ͻᱨ����ַ�Ƿ����� 
int main()
{
	int* c = new int;
	
	int* a = c;//����������ƭ���������������������������ǻ��ǷǷ�������δ������ڴ��ַ 
	
	for(int i = 0;i<10;i++)
	{
		a[i] = i;
	}
	
	for(int i = 0;i<10;i++)
	{
		cout<<a[i]<<endl;
	}
}
