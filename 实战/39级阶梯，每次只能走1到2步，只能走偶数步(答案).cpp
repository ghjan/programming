#include<stdio.h>
//�����ҽŵ����ơ�
const int N=39;
int f(int m,int n)
{
	if(m==0||n==0)
		return 1;
	
	return(f(m-1,n)+f(m,n-1));//�ݹ�Ĺؼ��ڴˣ����ģ��ת��ΪС��ģ��
}

int main()
{
	int x=N/2,y;		//x��ʾ�������Ĵ�����y��ʾ��һ���Ĵ�����
	int i,sum=0;
	
	for(i=x;x>=0;x-=2)		//Ϊ�˱���ż����������xÿ�εݼ�2��������1��(xҪx>=0,����x>0)��x=0�����ż��̨�ס�
	{
		y=N-2*x;
		sum+=f(x,y);		//�������;
	}
	printf("%d",sum);
	return 0;
}
