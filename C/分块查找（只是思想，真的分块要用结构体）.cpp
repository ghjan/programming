#include<stdio.h>
int main()
{
	int x,i,j,a[]={2,3,4,6,7,8,9,10,12,13,14,15,16,20,24};
	for(i=0;i<15;i++)
		printf("%d\t",a[i]);
	printf("\nqing shu ru yi ge shu: ");
	scanf("%d",&x);
	for(i=2;i<15;i+=3)		//i=1,i+=3��3������һ�飬һ��5�� ��������Խ�٣�������if��������Խ�� 
	{
		if(x<=a[i])
		{
		if(x==a[i])					//�ֿ���ҵ�˼�룬if����Ĵ���ִֻ��һ�Σ���Լ��ʱ�� 
		{
			printf("�ǵ�%d��Ԫ��",i+1);
			break;
		}
		else if(x==a[i-1])
			{
			printf("�ǵ�%d��Ԫ��",i);
			break;
		}
		else if(x==a[i-2])
			{
			printf("�ǵ�%d��Ԫ��",i-1);
			break;
		}
		else 
		{
			i=-1;
		break;
		} 
	}
	}
	if(i==-1) printf("û�����Ԫ��");
}
