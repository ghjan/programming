#include<stdio.h>
struct dong{
	int l,r,
	sum,//������¼ ���������ĺ� 
	m;//������¼ ��������������һ�� 
}a[1000000];
int max(int a,int b)
{
	return a>b?a:b;
 } 
int init(int l,int r,int i)
{ 
	a[i].l  = l;
	a[i].r 	= r;
    a[i].m = 0;
    a[i].sum = 0;	
	if(l!=r)
	{
		int mid = (l+r)/2;
		init(l,mid,2*i);
		init(mid+1,r,2*i+1);
	}
}
void insert(int l,int n,int i)
{
	if(a[i].l == l && a[i].r == l)
	{
		a[i].m = a[i].sum = n;
		return ;
	}
        
	int mid = (a[i].r +a[i].l)/2;
	if(l>mid)
		insert(l,n,2*i+1);//���ұ���
	else
		insert(l,n,2*i);//�������	
	
	a[i].sum = a[i*2].sum + a[i*2+1].sum; 
	a[i].m   = max(a[i*2].m,a[i*2+1].m);
}
int find_sum(int l,int r,int i)
{
	if(a[i].l == l && a[i].r == r)
	return a[i].sum;
	
	int mid = (a[i].l + a[i].r)/2;
	if(l>mid)//��������ڣ����ڵ�ʱ����������� 
		return find_sum(l,r,2*i+1);//���ұ���
	else if(r<=mid)
		return find_sum(l,r,2*i);//�������
	else
		return find_sum(l,mid,2*i) + find_sum(mid + 1, r,2*i+1);//�ڰٶ��ϵõ���ʾ��ԭ������������  ��ʾ�������� ��������mid��l��r֮��ʱ 
	//��mid��l��r֮��ʱ ������������Һܾã�����Ϊ �����ֲַ�Ͳ��ܱ�ʾ�Ǹ������ˡ�����ԭ�����һ����� 
 } 
int find_max(int l,int r,int i)
{
	if(a[i].l == l && a[i].r == r)
	return a[i].m;
	
	int mid = (a[i].l + a[i].r)/2;
	if(l>mid)
		return find_max(l,r,2*i+1);//���ұ���
	else if(r<=mid)
		return find_max(l,r,2*i);//�������
	else
		return max(find_max(l,mid,2*i) , find_max(mid + 1,r,2*i+1));
}
int main()
{
	int n,m,i,j,x,y,z;
	scanf("%d%d",&n,&m);
	
	init(1,n,1);
    for(i = 1; i<=n; i++)
    {
        scanf("%d",&j);
        insert(i,j,1);
    }
    while(m--) 
	{
		scanf("%d%d%d",&x,&y,&z);

		if(x == 1)
			insert(y,z,1);		
		
		else if(x == 2)
			printf("%d\n",find_sum(y,z,1));
		else if(x == 3)
			printf("%d\n",find_max(y,z,1));
	}		
	return 0;
 } 
/*
��n�����ӣ������ҷų�һ�ţ����Ϊ1-n��

����m�β�������3�ֲ������ͣ�

1.�޸�һ�����ӵ�Ȩֵ��

2.������һ�θ���Ȩֵ�ͣ�

3.������һ�θ��ӵ����ֵ��

����ÿ��2��3���������������Ľ����

�����ʽ
��һ��2������n��m��

������һ��n��������ʾn�����ӵĳ�ʼȨֵ��

������m�У�ÿ��3������p,x,y��p��ʾ�������ͣ�p=1ʱ��ʾ�޸ĸ���x��ȨֵΪy��p=2ʱ��ʾ������[x,y]�ڸ���Ȩֵ�ͣ�p=3ʱ��ʾ������[x,y]�ڸ�������Ȩֵ��

�����ʽ
�������У���������p=2��3�Ĳ���������

ÿ��1����������Ӧ��ÿ��p=2��3�����Ľ����

��������
4 3
1 2 3 4
2 1 3
1 4 3
3 1 4
�������
6
3
���ݹ�ģ��Լ��
����20%������n <= 100��m <= 200��

����50%������n <= 5000��m <= 5000��

����100%������1 <= n <= 100000��m <= 100000��0 <= ����Ȩֵ <= 10000��
*/
