#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int arr[20];
void swap(int a,int b)
{
	int t= arr[a];
	arr[a]=arr[b];
	arr[b]=t;
}
void quick(int star,int end)
{
	int a=star,b=end;
	if(a<b)
	{
		while(1)
	{
		while(a<b&&arr[a]<arr[star]) a++;	//  ����д�� <= �����������ߵ�ֵ  ��û�б仯��һֱ������ 
		while(a<b&&arr[b]>=arr[star]) b--;	//  ����д�� >= ��д�Ļ������ ����к͵�һ������ȵ���  �������ѭ�� 
		if(a>=b) break;
		swap(a,b);
	}
	//��Щ�������򷨣���ϸ΢���������������ѭ���п����� a = b+1  Ҳ�п����� a=b ���� ���� ����a-1 ����д��һ��a-1 һ��b+1 (����ͬʱ����a��b) 
	quick(star,a-1);
	quick(a+1,end);
	//ע������ a-1 �� a+1 ����ͬʱд�� a ��������a �Ļ� arr[a]����� ������ ��� ������ �ұ� �����������ȫ������ 
	}
}
int main()
{
	srand((unsigned )time(NULL));
	for(int i=0;i<20;i++)
	arr[i]=rand()%20;
	for(int j=0;j<20;j++)
	printf("%d  ",arr[j]);
	
	quick(0,19);
	printf("\n");
	for(int j=0;j<20;j++)
	printf("%d  ",arr[j]);
}    
