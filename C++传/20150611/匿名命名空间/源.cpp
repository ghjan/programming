#include<iostream>
//using namespace std;
//���������ռ�
namespace
{
	int num = 100;
}
//int num = -100;  //���ܼ���仰�� ������ ���������ռ�����ı������൱��ȫ�ֱ����� ���� �ᷢ����ͻ

namespace dong = std;//��std����������Ƽ���
void main()
{
	num = -2;
	dong::cout << num << dong::endl;

	std::cin.get();
}