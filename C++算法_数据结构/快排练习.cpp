#include <iostream>
using namespace std;

//����
void quick(int *arr,int left,int right)
{
	if(left >= right)
		return;
	int l = left;
	int r = right;
	//�Ӵ�С
	int temp = arr[l];//����ͻȻ���֣�������� ���� �Ǳ���������ߵ�ֵ����ô�������Ǳ����� ���ҿ�ʼ���� ************************
	while(l < r)
	{
		while(l < r && temp < arr[r])
			r--;
		arr[l] = arr[r];
		while(l < r && temp >= arr[l])	// >= ����д�� > 
			l++;
		arr[r] = arr[l];
	}
	arr[l] = temp;
	quick(arr,left,l - 1);
	quick(arr,r + 1,right);
}

void print(int *arr,int n)
{
	for(int i = 0;i < n;i++)
		cout<<*arr++<<" ";
	cout<<endl;
}

int main()
{
	int arr[] = {4,5,6,4,1,9,2,3,7,8,11,0};
	int size = sizeof(arr)/sizeof(arr[0]);
	quick(arr,0,size - 1);
	print(arr,size);
}
