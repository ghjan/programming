#include <iostream>
using namespace std;

/*����������С��*/
/*����arr[i]����ǰԪ�أ�arr[j]����������*/
/*�ѵĲ���*/
void insert(int *arr,int i)
{
	int j = (i - 1) / 2;//���ڵ��±�
	int temp = arr[i];//��Ҫ����ĵ�
	while (j >= 0 && i > 0)//���ڵ�϶���>=0�ģ���ǰ�ڵ�϶�Ҳ��>0�� ������ i>0����ʡ����Ȼ�����i=j=0��ѭ��
	{
		if (temp > arr[j])//��ǰ�ڵ�ȸ��ڵ��
			break;

		/*˵���ӱȸ�С����Ҫ�ƶ�*/
		arr[i] = arr[j];//���ڵ�����
		i = j;
		j = (i - 1) / 2;
	}
	arr[i] = temp;
}
/*ͷ����³�*/
void heapFixdown(int *arr, int i, int n)
{
	int j = 2 * i + 1;//��ߵ��ӽڵ�
	int temp = arr[i];
	while (j < n)//�����ӽڵ�ҪС��n					��д���ˣ� i<n ����������Խ��  �ӽڵ�϶�������
	{
		if (j + 1 < n && arr[j + 1] < arr[j]) //�����Һ���������С��(����Һ��Ӹ�С����ôȡ�Һ���)
			j++;
		if (temp < arr[j])
			break;
		arr[i] = arr[j];
		i = j;
		j = 2 * i + 1;
	}
	arr[i] = temp;
}

void swap(int &a, int &b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}

/*��С������*/
/*һ��õ��Ķ��ǵݼ�����*/
void SortDown(int *arr, int n)
{
	/*ȫ�����룬���Եõ�һ����С����*/
	for (int i = 0; i < n; i++)
		insert(arr, i);
	/*ÿ�ζ���������Ԫ�أ�ÿ�ζ��ܵõ���ǰ��С�ѵ���СԪ�أ����õ��������� �Ӵ�С ���е�*/
	for (int i = n - 1; i > 0; i--)
	{
		swap(arr[i], arr[0]);
		heapFixdown(arr, 0, i);
	}
}

/*���������������������������������������������������������������
										�������ݿ��Բ��������ǲ���
���������������������������������������������������������������*/


/*Ҳ���Եĵ����������С���������������������������ã���Ϊ����copy,��Ҫ��Ϊ��ָ���û�£�ָ��ҲҪ����������
ƽʱ���Ǹĵ���ָ��ָ������ݣ����Ծ��ô�ָ����ܸı�ֵ����ʵ����û�иı�ָ�뱾�����Ҫ�ı�ָ�뱾���ָ�򣬱����������*/
void SortUp(int *&arr, int n)
{
	int *a = new int[n];

	for (int i = 0; i < n; i++)
		insert(arr, i);

	for (int i = 1; i < n; i++)
	{
		a[i - 1] = arr[0];
		arr[0] = arr[n - i];
		heapFixdown(arr, 0, n - i);
	}
	a[n - 1] = arr[0];
	arr = a;						//ͼ���㣬ֱ�Ӹı�ָ��ָ��ĵ�ַ��ƽʱ����û�иı��ַ����ֻ�Ǹı��ַ�ϵ����ݰ���
}

void test1()
{
	int arr[] = { 5, 8, 1, 6, 3, 4, 2, 9, 7 };

	SortDown(arr, sizeof(arr) / sizeof(arr[0]));

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		cout << arr[i] << "\t";
		if (i == 0 || i == 2 || i == 6)
			cout << endl;
	}
	cout << endl;
}

void test2()
{
	int *arr = new int[9]{ 5, 8, 1, 6, 3, 4, 2, 9, 7 };//��ΪҪ�ĵ�ַ���������ﻹ����������

	SortUp(arr,9);

	for (int i = 0; i < 9; i++)
	{
		cout << arr[i] << "\t";
		if (i == 0 || i == 2 || i == 6)
			cout << endl;
	}
	cout << endl;
}

int main()
{
	test1();
	cout << "------------------------------" << endl;
	test2();

	getchar();
}