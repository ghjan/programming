#include<iostream>
using namespace std;
int main()
{
	int i,b[10];
	for(i=0;i<10;i++)
	{
		b[i]=i*10-i;
		cout<<b[i]<<"\t";
	 } 
	 cout<<endl; 
	 int *a=new int[10];		//��̬���飬new������� 
	for(i=0;i<10;i++)
	{
		a[i]=i*10-i;
		cout<<a[i]<<"\t";
	}
	delete []a;					//delete������ֶ��ͷ� 
	cout<<endl;
	return 0;
}
