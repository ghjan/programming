#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

void msg()
{
	while (1)
	{
		MessageBoxA(0, "������1000���", "game", 0);
		Sleep(2000);
	}
}

void main()
{
	int x = 100;
	printf("x��ַ��%x������������ַ��%x\n", &x, msg);
	//msg();//���򿪣������tool��
	while (1)
	{
		printf("������%d���\n", x);
		Sleep(2500);
	}
}