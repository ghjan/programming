#include<stdio.h>
int conv(long a,long b)//ת��Ϊ b ���� 
{
	if(a==0)
	return true;
	else
	{
		if(a%b>9)//������� ���� 9 ���� 0 
		return false;
		return conv(a/b,b);//����������� ��С�� 9 ���� true 
	}
}
int main()
{
	int i,j,t,temp;
	long real,sum=0;
	char ide[19];
	scanf("%ld",&real);
	scanf("%s",ide);
	for(i=0,t=10;;i++,t++)
	{
		temp =1;
		for(j=1;;j++)
		{
			if(ide[j]==NULL)
			break;
			temp *= t;
		}
		for(j=0;;j++)
		{
			if(ide[j]==NULL)
			break;
			sum += (ide[j] - '0')*temp;
			temp /=t;
			//printf("temp = %d\t ide = %d\t sum =%d\n",temp,ide[j],sum);
			//printf("sum = %d\n",sum);
		}
		if(sum > real)
		break;
		sum = 0;
	}
	//���������  ���� ���� t
	//������ �� t ��ʼ��t--�� ��� �Ƿ��������  
	for(i=t;i>9;i--)
	{
		if(conv(real,i)==1)
		break;
	}
	printf("%d",i);
	return 0;
 } 
 /*��Ŀ 
 Forever Young
Time limit: 1 second
My birthday is coming up. Alas, I am getting old and would like to feel young again. Fortunately, I have
come up with an excellent way of feeling younger: if I write my age as a number in an appropriately
chosen base b, then it appears to be smaller. For instance, suppose my age in base 10 is 32. Written in
base 16 it is only 20!
However, I cannot choose an arbitrary base when doing this. If my age written in base b contains digits
other than 0 to 9, then it will be obvious that I am cheating, which defeats the purpose. In addition, if
my age written in base b is too small then it would again be obvious that I am cheating.
Given my age y and a lower bound ` on how small I want my age to appear, find the largest base b such
that y written in base b contains only decimal digits, and is at least ` when interpreted as a number in
base 10.
Input
The input consists of a single line containing two base 10 integers y (10  y  1018 �C yes, I am very
old) and ` (10  `  y).
Output
Display the largest base b as described above.

Sample Input 1 Sample Output 1
32 20 16
Sample Input 2 Sample Output 2
2016 100 42
 */
