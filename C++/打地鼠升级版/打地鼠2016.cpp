#include <graphics.h>
#include <conio.h>
#include<time.h>
#include<stdio.h>
#define PI 3.14159265
int x1, y1, y2, Speed = 10;
char Target1;
char str1[20], str2[20], str3[40];
int sum1 = 0, sum2 = 0;
char str5[20], str6[20], str7[40];
void jiqi()
{
	setorigin(600, 300);
	setbkcolor(WHITE);
	cleardevice();
	setfillcolor(RGB(7, 190, 234));	
	setlinecolor(BLACK);
	fillroundrect(-135, -206, 135, 54, 248, 248);

	setfillcolor(WHITE);								// ��
	fillellipse(-115, -144, 115, 46);

	fillroundrect(-63, -169, 0, -95, 56, 56);			// ����
	fillroundrect(0, -169,  63, -95, 56, 56);			// ����

	setfillcolor(BLACK);
	solidcircle(-16, -116, 6);							// ������
	solidcircle( 16, -116, 6);							// ������

	setfillcolor(RGB(201, 62, 0));						// ����
	fillcircle(0, -92, 15);

	line(0, -77, 0, -4);								// ����
	arc(-108, -220, 108, -4, PI * 5 / 4, PI * 7 / 4);	// ��

	line(-42, -73, -90, -91);							// ����
	line( 42, -73,  90, -91);
	line(-41, -65, -92, -65);
	line( 41, -65,  92, -65);
	line(-42, -57, -90, -39);
	line( 42, -57,  90, -39);


	// ������
	line(-81, 32, -138, 72);					// �ֱ�(��)
	line( 81, 32,  138, 72);
	line(-96, 96, -116, 110);					// �ֱ�(��)
	line( 96, 96,  116, 110);

	line(-96, 85, -96, 178);					// �����
	line( 96, 85,  96, 178);
	arc(-10, 168, 10, 188, 0, PI);				// ���ڲ�

	setfillcolor(WHITE);						// ��
	fillcircle(-140, 99, 27);
	fillcircle( 140, 99, 27);
	fillroundrect(-2, 178, -112, 205, 24, 24);	// ��
	fillroundrect( 2, 178,  112, 205, 24, 24);

	setfillcolor(RGB(7, 190, 234));				// ���������ɫ
	floodfill(0, 100, BLACK);

	setfillcolor(WHITE);						// ��Ƥ
	fillcircle(0, 81, 75);
	solidrectangle(-60, 4, 60, 24);				// �ð�ɫ���β�������Ķ�Ƥ

	pie(-58, 23, 58, 139, PI, 0);				// �ڴ�


	// ������
	setfillcolor(RGB(169, 38, 0));				// ����
	fillroundrect(-100, 23, 100, 42, 12, 12);

	setfillcolor(RGB(245, 237, 38));			// ��������
	fillcircle(0, 49, 19);

	setfillcolor(BLACK);						// �����ϵĶ�
	solidellipse(-4, 50, 4, 57);
	setlinestyle(PS_SOLID, 3);
	line(0, 57, 0, 68);

	setlinestyle(PS_SOLID, 1);					// �����ϵ���·
	line(-16, 40, 16, 40);
	line(-18, 44, 18, 44);
	sprintf(str3, " ��ǰ�ܷ�Ϊ��%d��", sum1 - sum2);
	settextstyle(45, 0, "����");
	outtextxy(-180, -280, str3);
	settextstyle(30, 0, "����");
	outtextxy(-200, 300, "��û�������(200)�ߣ�����Ŭ��");
	system("pause");
}
int star()
{
	initgraph(1300, 650);
	cleardevice();
	int nColor = 255;
	int a;
	while (1)
	{
		setbkcolor(RGB(100, 100, 100));
		cleardevice();
		setcolor(BLUE);
		settextstyle(60, 0, "����");
		outtextxy(240, 20, "welcome to dong dong �����");
		setcolor(YELLOW);
		settextstyle(40, 0, "����");
		outtextxy(450, 90, "��������û�е���");
		setcolor(RED);
		settextstyle(32, 0, "����");
		outtextxy(100, 180, "1-����ĸ");
		outtextxy(550, 180, "2-����");
		outtextxy(1000, 180, "3-������");
		settextstyle(30, 0, "����");
		outtextxy(1080, 600, "��Esc�˳�");
		while (!_kbhit())
		{
			settextstyle(30, 0, "����");
			setcolor(RGB(0, nColor, nColor));
			outtextxy(350, 450, "����Ϸ�����ߣ������������á���������˧����");
			setcolor(RGB(nColor, 0, 0));
			outtextxy(450, 580, "��ѡ����Ϸģʽ���س�������");
			Sleep(10);
			nColor -= 5;
		}
		a = _getch();
		if (a <= 51 && a >= 49)
		{
			return a - 48;
		}
		else if (27 == a)
		{
			return a;
		}
		else
		{
			outtextxy(520, 500, "�����������������");
			Sleep(500);
			cleardevice();
		}
	}
}
void shang()
{
	for (y2 = 650; y2 >= 0; y2 -= Speed, y1 += Speed)
	{
		settextstyle(25, 0, "����");
		outtextxy(1080, 600, "��Esc���沢�˳�");
		setcolor(BLUE);
		settextstyle(25, 0, "����");
		outtextxy(x1, y2, Target1);
		outtextxy(x1, y1, Target1);
		Sleep(40);
		bar(x1, y2, x1 + 30, y2 + 30);
		bar(x1, y1, x1 + 30, y1 + 30);
		if (y2 <= y1)
			break;
	}
}
void zhuan1()
{
	int Input = 0;
	 sum1 = 0, sum2 = 0;
	srand((unsigned int)time(NULL));
	while (1)
	{
		setorigin(0, 0);
		setbkcolor(RGB(202, 133, 106));
	setfillcolor(RGB(202, 133, 106));
	cleardevice();
		Target1 = 'A' + rand() % 26;
		x1 = rand() % 1300;
		for (y1 = 0; y1 <= 650; y1 += Speed)
		{
			setcolor(BLUE);
			settextstyle(25, 0, "����");
			sprintf(str1, "��ǰ����Ϊ��%d", sum1);
			outtextxy(10, 20, str1);
			sprintf(str2, "��ǰMISSΪ��%d", sum2);
			outtextxy(10, 50, str2);
			settextstyle(25, 0, "����");
			outtextxy(1080, 600, "��Esc���沢�˳�");
			settextstyle(30, 0, "����");
			outtextxy(x1, y1, Target1);
			Sleep(80);
			bar(x1, y1, x1 + 30, y1 + 30);
			if (_kbhit())
			{
				Input = _getch();
				if (Input == Target1 || Input == Target1 + 32)
				{
					sum1++;
					shang();
					if (sum1 % 5 == 0)
					{
						Speed += 5;
					}
					break;
				}
				else if (Input == 27)
					break;
			}
		}
		if(sum1%8==0)
		{
			jiqi();
		}
		if (y1 >= 650)
		{
			sum2++;
		}
		if (Input == 27)
		{
			break;
		}
		cleardevice();
	}
	setorigin(0, 0);
	cleardevice();
	sprintf(str3, "game over ��ǰ�ܷ�Ϊ��%d��", sum1 - sum2);
	settextstyle(45, 0, "����");
	outtextxy(350, 250, str3);
	settextstyle(30, 0, "����");
	outtextxy(400, 330, "��û�������(200)�ߣ�����Ŭ��");
	outtextxy(460, 540, "������� ���ɷ��ز˵�");
	system("pause");
}
void zhuan2()
{
	setbkcolor(RGB(50, 100, 250));
	cleardevice();
	for (int i = 255;; i -= 10)
	{
		setcolor(RGB(0, i, 0));
		settextstyle(60, 0, "����");
		outtextxy(390, 200, "��ʱ��û��Ƴ���");
		setcolor(RGB(i, 0, 0));
		settextstyle(40, 0, "����");
		outtextxy(450, 300, "�밴���� 2 ����ļ�");
		Sleep(20);
		if (_kbhit())
			break;
	}
}
void zhuan3()
{
	sum1 =0, sum2 = 0;
	int x, Input;
	srand((unsigned int)time(NULL));
	setbkcolor(RGB(50, 133, 106));
	setfillcolor(RGB(50, 133, 106));
	setfillcolor(RGB(50, 133, 106));
	cleardevice();
	Speed = 10;
	while (1)
	{
		x1 = rand() % 1300;
		x = rand() % 9;
		for (y1=0; y1<= 650; y1 += Speed)
		{
			setorigin(0, 0);
	setbkcolor(RGB(50, 133, 106));
	setfillcolor(RGB(50, 133, 106));
	setfillcolor(RGB(50, 133, 106));
	cleardevice();
			setcolor(BLUE);
			settextstyle(25, 0, "����");
			sprintf(str5, "��ǰ����Ϊ��%d", sum1);
			outtextxy(10, 20, str5);
			sprintf(str6, "��ǰMISSΪ��%d", sum2);
			outtextxy(10, 50, str6);
			settextstyle(25, 0, "����");
			outtextxy(1080, 600, "��Esc���沢�˳�");
			settextstyle(30, 0, "����");
			sprintf(str3, "%d", x);
			outtextxy(x1, y1, str3);
			Sleep(80);
			bar(x1, y1, x1 + 30, y1 + 30);
			if (_kbhit())
			{
				Input = _getch();
				if (Input == x + 48)
				{
					sum1++;
					if (sum1 % 5 == 0)
					{
						Speed += 5;
					}
					break;
				}
				else if (Input == 27)
					break;
			}
		}
		if(sum1%8==0)
		{
			jiqi();
		}
		if (y1 >= 650)
		{
			sum2++;
		}
		if (Input == 27)
		{
			break;
		}
	}
	setorigin(0, 0);
	cleardevice();
	sprintf(str7, "game over ��ǰ�ܷ�Ϊ��%d��", sum1 - sum2);
	settextstyle(41, 0, "����");
	outtextxy(350, 252, str7);
	settextstyle(30, 0, "����");
	outtextxy(410, 331, "��û�������(300)�ߣ�����Ŭ��");
	outtextxy(461, 541, "������� ���ɷ��ز˵�");
	system("pause");
}
void main()
{
	int a;
	while (1)
	{
		a = star();
		if (1 == a)
		{
			zhuan1();
		}
		if (2 == a)
		{
			zhuan2();
		}
		if (3 == a)
		{
			zhuan3();
		}
		if (27 == a)
		{
			break;
		}
	}
}