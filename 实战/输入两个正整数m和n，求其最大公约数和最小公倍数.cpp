#include<stdio.h>
int main()
{
	int i,t,m,n;
	printf("������������");
	scanf("%d%d",&n,&m);
	if(n>m)
	{
		t=m;
		m=n;
		n=t;
	}
	for(i=n;i>0;i--)
	{
		if(m%i==0&&n%i==0)
		{
			printf("���Լ����%d\n��󹫱�����%d",i,m*n/i);
			break;
		}
	}
}
