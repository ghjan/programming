/*��������
����һ�����У�ÿ��ѯ�������е�l��������r�����е�K��������ĸ���

�����ʽ
��һ�а���һ����n����ʾ���г��ȡ�

�ڶ��а���n������������ʾ���������С�

����������һ��������m����ʾѯ�ʸ�����

������m�У�ÿ��������l,r,K����ʾѯ�����д������ҵ�l��������r�����У��Ӵ���С��K��������ĸ�������Ԫ�ش�1��ʼ��š�

�����ʽ
�ܹ����m�У�ÿ��һ��������ʾѯ�ʵĴ𰸡�
��������
5
1 2 3 4 5
2
1 5 2
2 3 2
�������
4
2
���ݹ�ģ��Լ��
����30%�����ݣ�n,m<=100��

����100%�����ݣ�n,m<=1000��

��֤k<=(r-l+1)�������е���<=106��*/
#include<stdio.h>
#include<string.h>
void quick(int a[],int left,int right)
{
	int l = left;
	int r = right;
	int t = a[l];
	
	if(l<r)
	{
		while(l<r)
		{
			while(l<r&&a[r]<=t)
			r--;
			a[l] = a[r];
			while(l<r&&a[l]>=t)
			l++;
			a[r] = a[l];
			if(l>=r)
			break;
		}
		a[l] = t;
		quick(a,left,r-1);
		quick(a,l+1,right);		
	}
}


int main()
{
	int i,j,a[1000],b[3],c[1000],d[1000],n,No;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	scanf("%d",&No);
	for(i=0;i<No;i++)
	{
		for(j=0;j<3;j++)
		scanf("%d",&b[j]);
		
		memcpy(c,a,sizeof(a));		
		quick(c,b[0]-1,b[1]-1);
		d[i] = c[b[0]-1+b[2]-1];
	}
	
	for(i=0;i<No;i++)
	printf("%d\n",d[i]);
	return 0;
 } 
