/*
�Ȳ�������
2,3,5,7,11,13,....���������С�
���ƣ�7,37,67,97,127,157 ������ȫ��������ɵĵȲ����У��еȲ��������С�
�ϱߵ����й���Ϊ30������Ϊ6��

2004�꣬�����뻪������������֤���ˣ��������ⳤ�ȵ������Ȳ����С�
������������һ��˵ĳɹ���

����һ����Ϊ����������������еļ�������������ĵ�������

����Ϊ10�ĵȲ������У��乫����Сֵ�Ƕ��٣�
*/

#include <iostream> 
#include <bitset>
using namespace std;
#define N 10000
long long arr[N / 2];//�����洢�������ռ任ʱ��
int len;
void isPrime(bitset<N + 1> &bit)
{
	bit[0] = bit[1] = 1;
	for (long long i = 2; i <= N; ++i)
	{
		if (bit[i] == 0)
		{
			for (long long j = i; i * j <= N; ++j)//������Ҫע�� i * j �п����Ǹ���  �����õ���long long 
				bit[i * j] = 1;
			arr[len++] = i;
		}
	}
}
int result()
{
	bitset<N + 1> bit;
	
	isPrime(bit);

	for (int i = 210; i <= 1000; ++i)//���� 
	{
		for (int j = 0; j < len; ++j)//�������� 
		{
			int su = arr[j];
			if (su == 199)
				cout << su << endl;
			int k = 1;
			for (; k < 10; ++k)//��ÿһ�������ж��Ƿ���������
				if (k * i + su >= N || bit[k * i + su] == 1)
					break;
			if (k == 10)
				return i;
		}
	}
	return 0;
}
int main()
{
	cout << result() << endl;

	return 0;
}
