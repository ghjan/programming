//��ԭ�������һ��ֻ�������ߡ������߻������ߡ�ǡ����N���Ҳ��������ߵĵ㹲�ж������߷� 
// �� ����1 ������� 
#include<stdio.h>
int main()
{
	int i,n,f[2],t;
	while(1)
	{
		f[0]=3,f[1]=7;
		scanf("%d",&n);
		if(n==1)
			printf("3\n");
		else if(2==n)
			printf("7\n");
		else
		{
			for(i=3;i<=n;i++)//���⿪ʼ����  ���� f(n)=2*f(n-1)+f(n-2)
			{
				t=	2*f[1] + f[0];
				f[0] = f[1];
				f[1] = t; 
			}
			printf("%d\n",f[1]);
		}
	}
	return 0;
}
