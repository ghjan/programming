#include<stdio.h>
void convert(int n,int base,int offset)
{
	char t[16] = {'0','1','2','3',
				  '4','5','6','7','8',
				  '9','A','B','C','D',
				  'E','F'};
	char arr[32];
	int i=0;
	
	//ΪʲôҪ���� &&i<32/offset �أ�  �𣺿����������λ�� ��������� n �������λ�� 0�������˳�ѭ����\
															����Ǹ����������λ�� 1  �����ӿ����������λ������������ѭ����  
	while(n!=0&&i<32/offset)
	{
		int temp = n&base; 
		arr[i++] = t[temp];
		n>>=offset;
	}
	while(--i>=0)//����arr�����е���  ����洢�� 
	printf("%c",arr[i]);	
 } 
 
void toHex(int n)
 {
 	printf("toHex:");
 	convert(n,15,4);
 }
 
void to8(int n)
 {
 	printf("to8:");
 	convert(n,7,3);
 }
 
void toBin(int n)
 {
 	printf("toBin:");
 	convert(n,1,1);
 }
 
int main()
{ 
	int n;
	while(1)
	{
		scanf("%d",&n);
		toHex(n);
		printf("\n");
		to8(n);
		printf("\n");
		toBin(n);
		printf("\n");
	}
} 
  		

