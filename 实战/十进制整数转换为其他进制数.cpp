#include<stdio.h>
void dong(int a,int b)
{	
	int shang=a,yu;
	if(shang!=0)
	{
		yu=a%b;
		shang=a/b;
		dong(shang,b);
		printf("%d",yu);
	}
}
int main()
{
	int a,b;
	printf("����һ��ʮ������:\n����Ҫת������:\n");
	scanf("%d%d",&a,&b);
	dong(a,b);
}

