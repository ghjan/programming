#include<stdio.h>
#include<time.h>
#include<stdlib.h>
// merge  ���� 
// �鲢��˼����� ���� ������������ϲ� ��ԭ���ϲ����й���ģ����Ǽ���ӣ� 
// ���Ǹ��������鲻������  ������ľ��ǰ����д�С�������г��� 
// ÿ�ΰ� ���� ����һ��  ǰһ�� �ͺ�һ�� ���й鲢  �����п��� ���������л���û�����
// ���͵ĵݹ�  ��취������ ������     �����뵽��������һ������ֻ��һ������ʱ��  �ǿ϶���������ģ����� 
void mergearrage(int arr[],int start,int mid,int end,int temp[])
{
	int a,b,c,k=0;
	a=start;
	b=mid+1;
	while(a<=mid&&b<=end)			// b +1  ����ζ�Ű� mid  �����ǰ���Ǹ����� 
	{
		if(arr[a]>arr[b])
		temp[k++]=arr[b++];
		else
		temp[k++]=arr[a++];
	}
	while(a<=mid)
	temp[k++]=arr[a++];
	
	while(b<=end)
	temp[k++]=arr[b++];
	
	int i;
	for(i=0;i<k;i++)
	arr[start+i]=temp[i];		//  �����Ĵ���ֻ���Լ���Ż�֪��  ��������  ��   �տ�ʼ start + i  ����� i   һֱ���� 
}
 
void mergesort(int arr[],int start,int end,int temp[])
{
	if(start<end)					// start����һ�����еĵ�һ��  end �������е����һ��   ������Ҫ�ľ�������ֻ��һ����  ��ֻ�е�һ�����������һ������ʱ�� 
	{																					// �� start ==  end ��ʱ�� �ݹ�Ͳ�ִ�� �� 
		int mid=(start+end)/2;
		mergesort(arr,start,mid,temp);//����   ʵ�ְѴ����л���С����  ֪����󻯳�һ����  ������ 
		mergesort(arr,mid+1,end,temp);//����   ͬ�� 
		mergearrage(arr,start,mid,end,temp);//��ֻ����һ������  �������кϲ�  Ȼ�� �Ѻ����������� �������кϲ�  ֪��  ���������� 
	}
 } 
 
// ����Ĵ���Ͳ����� �鲢�� 
int main()
{
	int i,a[100],b[100];
	srand(time(NULL));		// ��ȡ��������� 
	for(i=1;i<=50;i++)
	{
		a[i]=rand()%10+10;
		printf("%d\t",a[i]);
		if(i%10==0)
		printf("\n");
	}
	mergesort(a,1,50,b);
	printf("\nThe following are sorted\n\n\a");
	for(i=1;i<=50;i++)
	{
		printf("%d\t",a[i]);
		if(i%10==0)
		printf("\n");
	}
 } 
