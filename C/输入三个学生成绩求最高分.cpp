#include<stdio.h>
int main()
{
struct student
{
	int sno;
	char name[20];
	float score1,score2,score3;
	float sum[4]; 
}s[4];
int i,k;
float max,sum[4];
printf("��������ѧ����  ѧ��\t����\t���ĳɼ�\t��ѧ�ɼ�\t����ɼ�\n");
for(i=1;i<4;i++)
{
	printf("\t\t");
	scanf("%d",&s[i].sno);
	printf("\t");
	scanf("%s",&s[i].name);
	printf("\t");
	scanf("%f",&s[i].score1);
	printf("\t\t");
	scanf("%f",&s[i].score2);
	printf("\t\t");
	scanf("%f",&s[i].score3);
	printf("\n");
sum[i]=s[i].score1+s[i].score2+s[i].score3;
 } 
 k=1;
 max=sum[k];
for(i=1;i<4;i++)
{
	if(max<sum[i+1])
	{
	max=sum[i+1];
	k=i+1;
}
}
printf("���˵��ܳɼ��ֱ��ǣ�%f,          %f,           %f\n�ɼ���ߵ��ǣ�%s   ������%f",sum[1],sum[2],sum[3],s[k].name,sum[k]);
}

