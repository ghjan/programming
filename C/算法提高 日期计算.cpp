/*��������
 *��֪2011��11��11���������壬��YYYY��MM��DD�������ڼ���ע�⿼�����������������Ƿ���겻�򣬷�400����������
 */
 //ͨ��������ѯ��2016��1��1��Ҳ�� ������ 
#include<stdio.h>
int judge(int year)
{
	if(year%4==0 && year%100!=0 || year%400==0)
	return 1;
	return 0;
}
int get_year(int year)
{
	int sum = 0;
	if(year>=2016)
	{
		while(year!=2016)
		{
			year--;//�����ǰһ�������  ���� 2017 �꣬��ô������ 2017 �������  Ӧ����2016 ������� 
			if(judge(year))
			sum += 366;
			else
			sum += 365;			
		}	
	}
	else
	{
		while(year!=2016)
		{
			if(judge(year))
			sum += 366;
			else
			sum += 365;
			year++;
		}		
	}
	return sum;
}
int main()
{
	while(1)
	{
		int year,mon,day,sum=0;
		int month[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
		scanf("%d%d%d",&year,&mon,&day);
		if(year >= 2016)
		{
			sum = get_year(year);
			if(!judge(year))
			month[2] = 28;
			
			while(mon!=1)
			sum += month[--mon];//����ҲҪע��һ�£�����ǰһ���µ����� 
	
			sum += day-1+5;
			sum%=7;
			if(sum==0)
			sum = 7;
			printf("%d\n",sum);
		}
		else
		{
			sum = get_year(year);
			if(!judge(year))
			month[2] = 28;
			while(mon!=1)
			sum -= month[--mon];
			
			sum -= day ;
			sum %= 7;
			
						   //*************�ص�************// 
			sum = 5-1-sum;//��������� ���� 5 ����   ��Ϊ�Ǵ� ��ǰ ������ ����ʱ����
						  //Ϊʲô���1�أ���2015/1/1 �� 2015/12/31 �� 365 �졢��������2015/12/31 �� 2016/1/1 �� 1 �� 
			if(sum <= 0)
			sum+=7;
			printf("%d\n",sum);
		 } 
	}
	 return 0;
}
/*�ʼû�й��죬get_year()���������������Щ�𰸶�  ��Щ�𰸴� 
**ԭ������ڣ�����ֱ����year-- or year++ ����ÿ�� if(!judge(year)) ������ִ�� ��������
**�����������  �Ϳ����� һ��  �滻 year�ı����� 
*/
