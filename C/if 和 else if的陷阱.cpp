#include<stdio.h>
int main()
{
	int year=2017;
	if(year>2016)
	{
		printf("year1 = %d\n",year);
		year--;		
	}
	else if(year==2016)
	{
		printf("year2 = %d\n",year);//��һ������᲻��ִ�� 
	}
	if(year == 2016)
	{
		printf("year3 = %d\n",year);//��һ������᲻��ִ�� 
	}
}
