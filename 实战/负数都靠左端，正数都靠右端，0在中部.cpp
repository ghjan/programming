#include<stdio.h>
int main()
{
	int n;
	printf("��Ҫ���뼸������");
	scanf("%d",&n); 
	int a[n],p,l,r,t;
	printf("������Ҫ�������\n");
	 for(l=0;l<n;l++)
	 scanf("%d",&a[l]);
	r=n-1;
	l=0;
	p=0;
	while(p<r)
	{
		if(a[p]<0)
		{
			t=a[p];
			a[p]=a[l];
			a[l]=t;
			p++;
			l++;
		}
		else if(a[p]>0)
		{
			t=a[p];
			a[p]=a[r];
			a[r]=t;
			r--;
		}
		else
		{
			p++;
		}
	}
	for(l=0;l<n;l++)
	printf("%4d",a[l]);
 } 
