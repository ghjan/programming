//��0--9 ���д�С����ȫ���� 
#include<stdio.h>
#define LONG 5		//����
#define M 5			//0 - 5     0 - 9 ̫���� 
int a[10], b[10], sum = 0;
void sort(int n)
{
	if (n == M)
	{
		for (int i = 0; i<n; i++)
			printf("%d ", a[i]);
		printf("\n");
	}
	else
	{
		for (int j = 0; j <= M; j++)
		{
			if (b[j] == 0)			//ע��  ������b[j] ����b[n]  ��ϸ��һ�¾ͻ�֪�� j �仯�Ĵ����� n ��Ķ�   �ʼÿ�����ǰ�涼����ֻ�к��漸λ��� 
			{
				a[n] = j;				//	 ����������Ϊ j �ı仯�����   n ÿ�εݹ�ֻ����һ�� 
				b[j] = 1;
				sort(n + 1);
				b[j] = 0;
			}
		}
	}
}
int main()
{
	sort(0);
	return 0;
}
