#include <iostream>
#include <cmath>
using namespace std;
/*˼·����һ�������ҵ����Ϊ1�ļ��������ȿ��Գɹ�����*/
int sum;
int ss = 1;//ȥ���ظ���

void sort(int &a, int &b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}
/*�ж��Ƿ������Ϊ1����*/
bool success(int a, int b)//a > b
{
	int c = a - b;
	if (c < 1)
		return false;
	if (1 == c)
		return true;
	sort(b, c);
	return success(b, c);
}

int device(int *arr, int n)
{
	//for (int i = 0; i<= n; i++)
	//{
	//	if (arr[i] == 1)
	//	{
	//		sum++;
	//		continue;
	//	}
	//	for (int j = i + 1; j<= n; j++)
	//	{
	//		if (arr[i] == 1)
	//		{
	//			sum++;
	//			continue;
	//		}
	//		int a = arr[n] - arr[i];
	//		int b = arr[n] - arr[j];
	//		if (success(a, b))
	//			sum++;
	//	}
	//}
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 1)
		{
			sum++;
			continue;
		}
		for (int j = i + 1; j <= n; j++)
		{
			if (arr[j] == 1)
			{
				sum++;
				continue;
			}
			if (success(arr[i], arr[j]))
			{
				if (arr[i] == arr[j])
					ss++;
				sum++;
			}
		}
	}
	return sum;
}

/*��n == 2 ʱ*/
int main()
{
	int n, m, count = 0, i = 0, j = 0;
	cin >> n >> m;
	int *arr = new int[n];
	arr[n - 1] = m;
	for (int i = 1; i <= m; i++)
	{
		arr[0] = i;
		for (int j = 1; j <= m; j++)
		{
			arr[1] = j;
			device(arr, n);
		}
	}
	cout << sum - ss << endl;
	system("pause");
}
/*д��������*/
int main1()
{
	int n, m, count = 0, i = 0, j = 0;
	cin >> n >> m;
	int *arr = new int[n];
	arr[n - 1] = m;
	while (++count)
	{
		for (; i<m; i++)
		{
			arr[0] = i;
			break;
		}
		for (j = 0; j <= m; j++)//��Ȼ�� 
		{
			arr[1] = j;
			//sub(arr,n);
		}
		if (pow(m, n) == count)
			break;
	}
	return 0;
}
