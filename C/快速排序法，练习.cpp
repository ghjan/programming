#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void quick(int a[],int left,int right)		//����ֻ��һ���Զ��庯�� 
{
	int r,l,t;
	l=left,r=right;
	t=a[l];
	if(l<r)
	{  
		while(l!=r)	//l<r �� l!=r Ч��һ������������򷨵�����ѭ����ʱ��  һ���� l = r ��ʱ�򣬣����еĿ���������  l = r ���� l = r+1 Ҳ���� l>r��������ѭ�� 
		{
			while(l<r&&a[r]>=t)		//�ֳ��� ��,,��סһ���е��ڣ���Ȼ�������������ֵһֱ��������ѭ�� 
			r--;
			a[l]=a[r];
			while(l<r&&a[l]<=t)
				l++;
			a[r]=a[l];
		}
		a[l]=t;
		//�������򷨸о�����ͦ�ã������׳�������Ϊ����ѭ��  һ���� l = r��ʱ�� ���� ���� l-1 �����Ի��� r-1   
		quick(a,left,l-1);
		quick(a,l+1,right);		//right���ܸ�Ϊ49,��Ϊ��һ�εݹ����û�£��ڶ��εݹ�right�Ͳ�����79  ������l-1 
	}
}
int main()
{
	int i,a[80];
	srand(time(NULL));
	for(i=0;i<80;i++)
	{
		a[i]=rand()%100;
		printf("%d\t",a[i]);
	}
	quick(a,0,79);
	printf("\n�����\n");
	for(i=0;i<80;i++)
		printf("%d\t",a[i]);
}
