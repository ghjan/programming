#include <iostream>
#include <bitset>
using namespace std; 
/*
�����ж���������ݣ�����ÿ�����ݣ�
�����ַ����е�ÿһ���ַ����������Ŀ������żУ��������ÿ���ַ�У��Ľ��ռһ�С�
��������:
3
3a
�������:
10110011
10110011
01100001
*/
//����˼������������ó�ASCII��Ķ�������ʽ��ASCII�ַ���1�ĸ���

int main()
{
	char c;
	int i;
	bitset<8> bit; 
	while(cin>>c)
	{
		if(c == ' ' || c == '\n')
			continue;
		bit = c;
		if((bit.count() & 1) == 0)//��������� 
			bit.set(7);
		cout<<bit<<endl;
	}
	return 0;
}

