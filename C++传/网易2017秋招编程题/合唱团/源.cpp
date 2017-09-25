/*
��Ŀ����
�� n ��ѧ��վ��һ�ţ�ÿ��ѧ����һ������ֵ��ţţ����� n ��ѧ���а���˳��ѡȡ k ��ѧ����
Ҫ����������ѧ����λ�ñ�ŵĲ���� d��ʹ���� k ��ѧ��������ֵ�ĳ˻�������ܷ������ĳ˻���

ʾ��1
����
3
7 4 7
2 50
���
49
*/
#include <iostream>
#include <fstream>
using namespace std;

int max(int a, int b){
	return a > b ? a : b;
}
void swap(int &a, int &b){
	int c = a;
	a = b;
	b = c;
}

int main()
{
	int n, k, d;
	cin >> n;
	int *val = new int[n + 1];
	for (int i = 1; i <= n; ++i){
		cin >> val[i];
	}
	cin >> k >> d;

	//��ʼ��
	long long **arr_up = new long long*[k + 1];
	long long **arr_down = new long long*[k + 1];
	for (int i = 0; i < k + 1; ++i){
		arr_up[i] = new long long[n + 1]();
		arr_down[i] = new long long[n + 1]();
	}
	for (int i = 1; i < n + 1; ++i){
		arr_up[1][i] = val[i];
		arr_down[1][i] = val[i];
	}

	for (int i = 2; i <= k; ++i){	//ѡi����
		for (int j = i; j <= n; ++j){	//����λ�ñ��
			int x = max(j - d, 1);
			long long sum_up = arr_up[i - 1][x] * val[j];//��¼������
			long long sum_down = arr_down[i - 1][x] * val[j];//��¼��С����
			if (sum_up < sum_down){
				swap(sum_up, sum_down);
			}
			for (++x; x < j; ++x){
				long long num = arr_up[i - 1][x] * val[j];
				if (num > sum_up){
					sum_up = num;
				}
				else if (num < sum_down){
					sum_down = num;
				}

				num = arr_down[i - 1][x] * val[j];
				if (num > sum_up){
					sum_up = num;
				}
				else if (num < sum_down){
					sum_down = num;
				}
			}
			arr_up[i][j] = sum_up;
			arr_down[i][j] = sum_down;
		}
	}
	//��ȡ���˻�
	long long max_sum = arr_up[k][k];
	for (int i = k + 1; i <= n; ++i){
		if (arr_up[k][i] > max_sum){
			max_sum = arr_up[k][i];
		}
	}
	cout << max_sum << endl;

	system("pause");
	return 0;
}
/*
��������:
47
-41 -5 -10 -31 -44 -16 -3 -33 -34 -35 -44 -44 -25 -48 -16 -32 -37 -8 -33 -30 -6 -18 -26 -37 -40 -30 -50 -32 -5 -41 -32 -12 -33 -22 -14 -34 -1 -41 -45 -8 -39 -27 -23 -45 -10 -50 -34
6 3
��Ӧ���Ӧ��Ϊ:
5504557500
������Ϊ:
2135936000			����������������Ϊ����û��ô��  MD 

��Ϊ long long ��ȫ��ͨ����
*/
