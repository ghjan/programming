#include<iostream>
/*
ģ��Ԫʵ�ֵݹ����
ִ���ٶȿ죬������������������ʱ���Լ�ڱ�����

��Ȼ����ܷǵݹ飬��á���������죬ִ�п�
*/


//��ŵ��  �ݹ���
int hanta1(int n)
{
	if (n == 1)
		return 1;
	else if (n == 2)
		return 2;
	else
		return hanta1(n - 1) + hanta1(n - 2);
}
//�ǵݹ�
int hanta2(int n)
{
	if (n == 1)
		return 1;
	else if (n == 2)
		return 2;
	else
	{
		int sum = 0;
		int a = 1, b = 2;
		for (int i = 3; i <= n; i++)
		{
			sum = a + b;
			a = b;
			b = sum;
		}
		return sum;
	}
}
//ģ��Ԫ
template<int N>
struct data
{
	//�ݹ�
	enum{ res = data<N - 1>::res + data<N - 2>::res };
};
template<>
struct data<1>
{
	enum{ res = 1 };
};
template<>
struct data<2>
{
	enum{ res = 2 };
};
void main()
{
	//std::cout << hanta1(40) << std::endl;
	std::cout << data<70>::res << std::endl;
	std::cout << hanta2(70) << std::endl;

	std::cin.get();
}