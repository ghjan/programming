#include<stdio.h>
int search(int a[],int x)
{
	int low=0,high=49,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(x==a[mid])
		return mid+1;
		else if(x>a[mid])
			low=mid;
		else
			high=mid;
	}
	return 0;
}
int main()
{
	int a[50],x,i,z;
	for(i=0;i<50;i++)
	{
		if(i!=0&&i%5==0) printf("\n");
		a[i]=i+30;
			printf("%d\t",a[i]);
	}
	printf("������Ҫ�ҵ���:");
	scanf("%d",&x);
	z=search(a,x);
	if(z==0)
		printf("��Ҫ�ҵ������ڴ�����");
	else
		printf("�ǵ�%d��Ԫ��",z);
}
