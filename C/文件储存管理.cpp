#include<stdio.h>
typedef struct student
{
	char name[20];
	int chinese;
	int math;
	int english;
}str;
str a[100];
int i=0;
void out()//���ļ��ж������� 
{
	FILE *fp;
	fp=fopen("D:\\dong.dat","a+");
	int j=0;
	while(fread(&a[j],sizeof(str),1,fp)==1)		//  ����ֵ����fread��countֵ    fread(buffer,size,cout,fp) 
	{
		printf("������%s\n",a[j].name);
		printf("���ĳɼ���%d\n",a[j].chinese);
		printf("��ѧ�ɼ���%d\n",a[j].math);
		printf("����ɼ���%d\n",a[j].english);
		j++;
		printf("\n");
	}
	fclose(fp);
}
void save()//������ļ� 
{
	FILE *fp;
	fp=fopen("D:\\dong.dat","w+");
	int j=0;
	
	//�ⲻ�������� while(fread(&a[j],sizeof(str),1,fp)==1)����������Ϊa[100]��ȫ�ֱ��� int ��==0  ���ǳ�ʼ���˵�   ����һֱд���ļ�fwrite����ֵһֱΪ1 
	for(j;j<=i;j++)
	fwrite(&a[j],sizeof(str),1,fp);

	fclose(fp);
}
int main()
{
	int j,n;
	out();
	printf("����Ҫ���뼸�����ݣ�");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	printf("������������");
	scanf("%s", a[i].name);
	printf("���������ĳɼ���");
	scanf("%d", &a[i].chinese);
	printf("��������ѧ�ɼ���");
	scanf("%d", &a[i].math);
	printf("����������ɼ���");
	scanf("%d", &a[i].english);		
	}
	save();
 } 
