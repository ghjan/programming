#include<iostream>
using namespace std; 
class dong
{
public:
	static void add(int a)
	{
		*p=a;
		p++;
	}
	static void print();
	static void sort();
	static int date[20];//������̬�ڴ�ռ�
	static int *p;		//������ָ̬���Ա
};
int dong::date[20];   //ʵ�ʶ��壬Ĭ�ϵĳ�ֵΪ0
int *dong::p=date;	//ʵ�ʶ��壬���ֵΪdate������׵�ַ
void dong::print()					//ʵ������
{
	for(int i=0;i<(p-date);i++)
		cout<<date[i]<<",";
	cout<<endl;
}
void dong::sort()				//ʵ������
{
	int n=p-date;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		if(date[i]>date[j])
		{
			int t=date[i];
			date[i]=date[j];
			date[j]=t;
		}
}
int main()
{
	int dong::date[20];
	int *dong::p=date;
	int n=p-date; 
	for(int i=0;i<n;i++)
	{
		cin>>a;
		dong::add(a);
	}
	dong::sort ();
	dong::print ();		//��ӡ���Ѿ�����õ���
	return 0;
}
