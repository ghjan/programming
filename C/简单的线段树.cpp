//��������   �޷�ʵ��  ���������   ֻ��ʵ�ֲ������� 
#include<stdio.h>
struct{
	int r,l,sum;
}a[100];
int b[100]={1,2,1,2,1,2,0};
void init(int l,int r,int i)
{
	a[i].l = l;//��¼������ 
	a[i].r = r;//��¼������ 
	 
	if(r == l)
	a[i].sum = b[l];
	else
	{
		int mid = (l+r)/2;
		init(l,mid,2*i);
		init(mid+1,r,2*i+1);
		
		a[i].sum = a[i*2].sum + a[2*i+1].sum;
	}
}
int find_sum(int l,int r,int i)
{
	if(a[i].l == l && a[i].r == r)
	return a[i].sum;
	
	int mid = (a[i].l+a[i].r)/2;
	if(r<=mid)				//��һ�������� 
	return find_sum(l,r,2*i);
	else						// �� �ұ߽�  С�� �ܱ߽� ִ�� ��һ��   ����ִ����һ�� 
	return find_sum(l,r,2*i+1);		
}
int main()
{
	init(0,6,1);//��0 λ�� �� 5 λ�� , ���ڵ� Ϊ 1 
	
	for(int i=1;i<13;i++)
	printf("%d  ",a[i].sum);
	
	int x = find_sum(0,3,1);
	printf("\n�ڣ�0-3�������ڵĺ�: %d\n",x);
	
	x = find_sum(4,6,1);
	printf("\n�ڣ�4-6�������ڵĺ�: %d\n",x);
	
	x = find_sum(0,1,1);
	printf("\n�ڣ�0-1�������ڵĺͣ�%d\n",x);
	
	x = find_sum(6,6,1);
	printf("\n�ڣ�6-6�������ڵĺͣ�%d\n",x);
	
}
