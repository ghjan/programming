#include <iostream>
using namespace std;

void display(int a[],int n)
{
	for(int i = 0;i<n;i++)
	{
		cout<<a[i];
	}
}
void zijieInsert(int a[],int n)
{
	int temp,j;
	for(int i=1;i<n;i++)
	{
		temp = a[i];
		for(j = i;j>0&&temp<a[j-1];j--)//��ǰԪ�ر���ǰһ��Ԫ��ҪС 
		{
			a[j] = a[j-1];//ǰһ�������ƶ� 
		}
		a[j] = temp;//�ѱȽ�Ԫ�ط��� ��Ӧ�ô��ڵ�λ�� 
		display(a,9);
		cout<<endl;
	}
}

int main()
{
	int a[] = {8,5,6,7,4,9,1,2,3};
	zijieInsert(a,9);
	display(a,9);
}
