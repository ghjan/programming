#include<stdio.h>
int main()
{
	struct date
	{
		int year;
		int month;
		int day;
	};
	struct student
	{
		int num;
		char name[20];
		struct date birth;
	}stu[2]={{110,"����",1996,02,22},{119,"����",1996,01,04}};
	int i;
		printf("1^^^ѧ��    ����    ��������\n");
	for(i=0;i<2;i++)
	{
	    printf("    %d      %s      %d-%d-%d\n",stu[i].num,stu[i].name,stu[i].birth.year,stu[i].birth.month,stu[i].birth.day);
	}
		printf("2^^^ѧ��    ����    ��������\n");
	for(i=0;i<2;i++)
	{
	    printf("    %d      %s      %d-%d-%d\n",stu[i].num,stu[i].name,stu[i].birth.year,stu[i].birth.month,stu[i].birth.day);
	}
 } 
