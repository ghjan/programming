//Ҫʵ�������ȫ����  ������������  ��1 2 3 ��ô���Ǵ�С��������   3 2 1 ���ǴӴ�С
// ����������Ҫ  ���Զ�����������������   Ȼ���� dfs ���� 
#include<stdio.h>
int a[100],aa[100],b[100],n;		// aa[] ���ǰ������a[]�������ס 
void dfs(int t)
{
	if(t==n)
	{
		for(int i=0;i<n;i++)
		printf("%d",a[i]);
		printf("\n");
	}
	else
	{
		for(int j=0;j<n;j++)//ÿ�εݹ�  j �������0  ��ʼ �����һ�� b[j]Ϊ 0 �ĵط�ֹͣ��aa[]��δ��1���ǵ���Сֵ��  ������������ 
		if(!b[j])
		{
			b[j]=1;
			a[t]=aa[j]; 
			dfs(t+1); 
			b[j]=0;
		}
	}
}
int main()
{
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		aa[i]=a[i];	
	}
	dfs(0);
	
	
	return 0;
 } 
