//������һ�ο���
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void quick(int a[], int left, int right)
{
	int l = left, r = right;
	if (l < r)
	{
		int t = a[l];
		while (l < r)
		{
			while (l < r && a[r] >= t)
				r--;
			a[l] = a[r];
			while (l < r && a[l] < t)
				l++;
			a[r] = a[l];
		}
		a[l] = t;
		quick(a, left, l - 1);
		quick(a, l + 1, right);
	}
}
/*
	while (l < r && a[r--] >= t)
			a[l] = a[++r];			//��������д������ǰһֱ��֪��ԭ�򣬣���ʵ������Ϊ l < r &&  Ҳ����˵r--��һ��ÿ��ѭ����ִ�еõ�  
									//Ҳ���ܰ�  l < r ȥ��  ԭ������a[l] = a[r] ����Ϊ�˰��ұߴ�ķŵ������  �������֤l<r�Ļ��ͻ��� 
									//// �� l < r �ŵ�a[r] >= t �����ֻᵼ�£� l < r �Ƚϲ�׼ȷ����ʱ�� r �� r - 1 
*/

int main()
{
	int i, a[80];
	srand(time(NULL));
	for (i = 0; i<80; i++)
	{
		a[i] = rand() % 100;
		printf("%d\t", a[i]);
	}
	quick(a, 0, 79);
	printf("\n�����\n");
	for (i = 0; i<80; i++)
		printf("%d\t", a[i]);
}
