#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
typedef struct student
{
	char name[20];
	int chinese;
	int math;
	int english;
}str;
int i = 0;
str a[100];
int input()
{
	for (i = 0; i <= 100; i++)
	{
		printf("������������");
		scanf_s("%s", a[i].name, sizeof(a[i].name));
		printf("���������ĳɼ���");
		scanf_s("%d", &a[i].chinese);
		printf("��������ѧ�ɼ���");
		scanf_s("%d", &a[i].math);
		printf("����������ɼ���");
		scanf_s("%d", &a[i].english);
		char b[20];
		getchar();
		while (1)
		{
			printf("dong�Ƿ�������  y/n\n");
			scanf_s("%s", &b, sizeof(b));
			getchar();
			if (!strcmp(b, "y") || !strcmp(b, "Y"))
				break;
			else if (!strcmp(b, "n") || !strcmp(b, "N"))
				return i;
			else
			{
				continue;
			}
		}
	}
	return i;
}
void output()
{
	if (i != 0)
	{
		for (int j = 0; j <=i; j++)
		{
			printf("%d-------------\n", j + 1);
			printf("������%s\n", a[j].name);
			printf("���ģ�%d\n��ѧ��%d\n���%d\n\n", a[j].chinese, a[j].math, a[j].english);
		}
	}
	else
		printf("��û������\n\n");
}
void chazhao(char c[20])
{
	int j;
	for (j = 0; j <=i; j++)
	{
		if (!strcmp(a[j].name, c))
		{
			printf("%d-------------\n",j+1);
			printf("������%s\n", a[j].name);
			printf("���ģ�%d\n��ѧ��%d\n���%d\n", a[j].chinese, a[j].math, a[j].english);
			break;
		}
	}
	if (j - 1 == i)
	{
		printf("û�������\n\n");
	}
}
void charu()
{
	int b,c;
	printf("Ҫ���뵽�ڼ�����");
	scanf_s("%d", &b, sizeof(int));
	for (c=i; b-1 <=c; c--)
	{
		strcpy(a[c + 1].name, a[c].name);
		a[c + 1].chinese = a[c].chinese;
		a[c + 1].math = a[c].math;
		a[c + 1].english = a[c].english;
	}
	i++;
	printf("������ѧ����Ϣ��\n");
	printf("������������");
	scanf_s("%s", a[b-1].name, sizeof(a[b].name));
	printf("���������ĳɼ���");
	scanf_s("%d", &a[b-1].chinese);
	printf("��������ѧ�ɼ���");
	scanf_s("%d", &a[b-1].math);
	printf("����������ɼ���");
	scanf_s("%d", &a[b-1].english);
}
void shanchu()
{
	int c;
	printf("Ҫɾ���ڼ�����");
	scanf_s("%d", &c, sizeof(int));
	for (c = c - 1; c < i;c++)
	{
		strcpy(a[c].name, a[c+1].name);
		a[c].chinese = a[c+1].chinese;
		a[c].math = a[c+1].math;
		a[c].english = a[c+1].english;
	}
	i--;
}
char* xingming()
{
		char **p;
		char xingming[20];
		xingming[0] = '\0';
		p = (char **)malloc(19 * sizeof(char *));
		for (int b = 0; b<19; b++)
			*(p + b) = (char *)malloc(6 * sizeof(char));
		strcpy(p[0], "��");
		strcpy(p[1], "��");
		strcpy(p[2], "��");
		strcpy(p[3], "��");
		strcpy(p[4], "��");
		strcpy(p[5], "ţ");
		strcpy(p[6], "ǿ");
		strcpy(p[7], "˧");
		strcpy(p[8], "ΰ");
		strcpy(p[9], "��");
		strcpy(p[10], "��");
		strcpy(p[11], "��");
		strcpy(p[12], "��");
		strcpy(p[13], "��");
		strcpy(p[14], "ˬ");
		strcpy(p[15], "��");
		strcpy(p[16], "��");
		strcpy(p[17], "��");
		strcpy(p[18], "��");
		srand(time(0));
		int c = rand() % 2+1;
		for (int d = 0; d <= c; d++)
		{
			int j = rand() % 18 + 1;
			strcat(xingming, p[j]);
		};
			return xingming;
}
void yuanshi()
{
	int b;
	srand(time(0));
	for (i = 0; i < 10; i++)
	{
		strcpy(a[i].name, xingming());
		b = rand() % 10+ 1;
		a[i].chinese = b;
		Sleep(350);
		printf(".");
		b = rand() % 100 + 1;
		a[i].math = b;
		Sleep(350);
		printf(".");
		b = rand() % 100 + 1;
		a[i].english = b;
		Sleep(350);
		printf(".");
	}
	i--;
	printf("\n");
}
int main()
{
	int n;
	char name[20];
	while (1)
	{
		printf("1-��������ɼ�\t2-������гɼ�\t3-����\t4-����\t5-�Զ�����(��Ҫ11��)\t6-ɾ��\t\t9-�˳�\t\t���벻Ҫ�Ұ���\n");
		scanf_s("%d", &n, 4);
		if (n == 1)
			int i = input();
		if (2 == n)
			output();
		if (3 == n)
		{
			printf("������Ҫ���ҵ��ˣ�");
			scanf("%s", name, sizeof(name));
			chazhao(name);
		}
		if (4 == n)
		{
			charu();
		}
		if (5 == n)
		{
			yuanshi();
		}
		if (6 == n)
		{
			shanchu();
		}
		if (9 == n)
			break;
	}
	system("pause");
	return 0;
}
