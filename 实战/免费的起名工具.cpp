#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int main()
{
	char q[10];
	printf("����������ʲô�����س�����������");
	scanf("%s",q);
	printf("�������Ҹ���������ȡ������\n"); 
	char **p;
	p=(char **)malloc(25*sizeof(char *));
	for(int b=0;b<25;b++)
	*(p+b)=(char *)malloc(6*sizeof(char));
	strcpy(p[0],"��");
	strcpy(p[1],"��");
	strcpy(p[2],"��");
	strcpy(p[3],"��");
	strcpy(p[4],"��");
	strcpy(p[5],"ţ");
	strcpy(p[6],"ǿ");
	strcpy(p[7],"˧");
	strcpy(p[8],"ΰ");
	strcpy(p[9],"��");
	strcpy(p[10],"��");
	strcpy(p[11],"��");
	strcpy(p[12],"��");
	strcpy(p[13],"��");
	strcpy(p[14],"ˬ");
	strcpy(p[15],"��");
	strcpy(p[16],"��");
	strcpy(p[17],"��");
	strcpy(p[18],"��");
	strcpy(p[19],"ŷ");
	strcpy(p[20],"��");
	strcpy(p[21],"��");
	strcpy(p[22],"��");
	strcpy(p[23],"��");
	strcpy(p[24],"��");
	srand(time(0));
	int a=rand()%2;
		printf("%s",q); 
	for(int i=0;i<=a;i++)
	{
	int j=rand()%18+1;
	printf("%s",p[j]);
    };
    printf("\n");
    system("pause"); 
 } 
