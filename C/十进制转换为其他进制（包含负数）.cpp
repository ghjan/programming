#include<stdio.h>
int toHex(int n)
{
	char t[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'} ;//16���Ƶı� 
	char arr[32];
	int i=0;
	
	while(n!=0&&i<8)//���� ת��Ϊ ʮ������ ��8λ ��32/4 = 8�� 
	{
		int temp = n&15; 
		arr[i++] = t[temp];//�����±�  ֱ�Ӳ����һһ��Ӧ�Ĺ�ϵ�� 
		n>>=4;
	}
	printf("toHex:");
	while(--i>=0)
	printf("%c",arr[i]);
 } 
 int toBin(int n)
 {
 	char t[2] = {'0','1'};
 	char arr[32];
 	int i=0;
	
	while(n!=0&&i<32)//���� ת��Ϊ ������ ��32λ 
	{
		int temp = n&1; 	//ȡ���λ 
		arr[i++] = t[temp];//�����±�  ֱ�Ӳ����һһ��Ӧ�Ĺ�ϵ�� 
		n>>=1;
	}
	printf("toBin:");
	while(--i>=0)
	printf("%c",arr[i]);//�����±�  ֱ�Ӳ����һһ��Ӧ�Ĺ�ϵ�� 	
} 
int main()
{
	int n;
	while(1)
	{
		scanf("%d",&n);
		toHex(n);
		printf("\n");
		toBin(n);
		printf("\n");
	}
} 
