#include <iostream>
using namespace std;

int main()
{
	int *arr = new int[20];				//����ֻ�������˿ռ䣬�����ֵ������ģ�û�г�ʼ���� 
	for(int i = 0 ;i<20;i++)
	{
		if(i%5 == 0)
			cout<<endl;
		cout<<arr[i]<<"\t";
	}
	cout<<endl<<"-------------------------------------------"<<endl;
	int *array = new int[20]();			//���ﲻ�������˿ռ䣬�����ֵ��ȫ����ʼ��Ϊ0�� 
	for(int i = 0 ;i<20;i++)
	{
		if(i%5 == 0)
			cout<<endl;
		cout<<array[i]<<"\t";
	}
	
}
