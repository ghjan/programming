#include <iostream>
using namespace std;
/*
˼·�����ֵĹ��ɣ��� 1---n  ֻҪÿ�θ��ڶ���λ�����θ�ֵ�Ϳ��Եõ�ԭ��������
1---n  ������һ��ѭ������ÿ�����Ƿ��ʵ����ڶ�����û�б���ֵ��Ԫ�ء����ǾͿ��Խ��� 1---n  �����θ�ֵ
�����Ƿ��ʵ����һ��Ԫ�أ��ǵ�Ҫ������һ��Ԫ�أ�һֱ����������顣
*/
void sort(int* arr, int n)
{
	int i = 0, j = 1;
	int yes = 0;
	while (1)
	{
		if (arr[i] == 0)
		{
			if (j == n)			//����ѭ����������ֻ���ҵ����һ��δ����ֵ��Ԫ�أ���ֵ֮�����ǣ����ǲ�����ѭ��
			{
				arr[i] = j;
				break;
			}
			if (yes == 1)
			{
				arr[i] = j++;
				yes = -1;
			}
			yes++;

		}
		if (++i == n)
			i = 0;
	}
}

int main()
{
	int m, n, j;
	cin >> m;
	int* arr;
	for (int i = 0; i < m; i++)
	{
		cin >> n;
		arr = new int[n]();
		sort(arr, n);
		for (j = 0; j< n - 1; j++)
		{
			cout << arr[j] << " ";
		}
		cout << arr[j] << endl;
		delete arr;
	}

	system("pause");
	return 0;
}
