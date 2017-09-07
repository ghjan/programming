//	С��������һ��ʯ��·ǰ��ÿ��ʯ���ϴ�1���ű��Ϊ��1��2��3.......
//	����ʯ��·Ҫ��������Ĺ������ǰ��������С�׵�ǰ���ڵı��ΪK�� ʯ�壬
//	С�׵���ֻ����ǰ��K��һ��Լ��(����1��K)����������K + X(XΪK��һ����1�ͱ����Լ��)��λ�á� 
//	С�׵�ǰ���ڱ��ΪN��ʯ�壬�����������ǡ��ΪM��ʯ��ȥ��С����֪��������Ҫ��Ծ���ο��Ե��
//	���磺
//	N = 4��M = 24��
//	4->6->8->12->18->24
//	����С��������Ҫ��Ծ5�Σ��Ϳ��Դ�4��ʯ������24��ʯ��
//	�������� :
//	����Ϊһ�У�����������N��M���Կո������
//	(4 �� N �� 100000)
//	(N �� M �� 100000)
//	
//	������� :
//		 ���С��������Ҫ��Ծ�Ĳ���, ������ܵ������ - 1
#include<iostream>
#include<cmath>
using namespace std;

//��ȡԼ��
int* get(int n,int *num)
{
	int* arr = new int[n];
	int* arr1 = new int[n / 2];
	int j = 0,k = 0;
	for (int i = n / 2; i > 1; i--)
	{
		if (n%i == 0)
			arr[j++] = i;
	}
	*num = j;
	return arr;
}

int step(int n, int m,int count)
{
	if (n >= m)
	{
		if (n == m)
			return count;
		return -1;
	}
	int num;
	int res;
	int *arr = get(n,&num);
	for (int i = 0; i < num; i++)
	{
		res = step(arr[i] + n, m, count + 1);
		if (res > 0)
			return res;
	}
	return -1;
}
int main()
{
	int N, M;
	cin >> N >> M;

	cout << step(N, M, 0) << endl;
	
	system("pause");
	return 0;
}
/*
�𰸴���:���ύ�ĳ���û��ͨ�����еĲ�������
caseͨ����Ϊ80.00%

��������:
676 12948

��Ӧ���Ӧ��Ϊ:
10
������Ϊ:
13
*/