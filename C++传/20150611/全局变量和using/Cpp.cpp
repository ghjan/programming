#include<iostream>

int a = 10;

namespace
{
	//ֻ���൱��ȫ�֡���������ȫ�֡���ȫ��û��a = 10  ���൱��ȫ��
	int a = 55;//ֻҪ������a  ���Ƿ������������Ϊ�����á���������ռ�Ͳ�����
}
void main()
{
	//std::cout << a << std::endl;//����  "a" ����ȷ	

	std::cout << ::a << std::endl;//ʹ��ȫ�ֵ�a

	std::cin.get();
}