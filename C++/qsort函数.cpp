#include <iostream>
#include <cstdlib> 			//qsort������������ͷ�ļ��� 
using namespace std;

int comp(const void *a,const void *b)//const����ʡ�� 
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int arr[] = {3,4,5,7,8,9};
	int n = sizeof(arr)/sizeof(arr[0]);
	qsort(arr,n,sizeof(int),comp);
	for(int i = 0;i<n;++i)
		cout<<arr[i]<<" ";
}
