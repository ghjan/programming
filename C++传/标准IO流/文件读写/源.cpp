#define  _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include "Teacher.h"
using namespace std;

int main3()
{
	char* path = "C:\\Users\\37916\\Desktop\\dong.txt";
	Teacher* t1 = new Teacher("������", 20);
	Teacher* t2 = new Teacher("����ӱ", 28);
	Teacher* t3 = new Teacher("����", 50);
	//д�ļ�
	FILE* fp = fopen(path, "a+");
	fwrite((void *)t1, sizeof(Teacher), 1, fp);
	fwrite((void *)t2, sizeof(Teacher), 1, fp);
	fwrite((void *)t3, sizeof(Teacher), 1, fp);

	fseek(fp, 0, SEEK_SET);


	Teacher* t = new Teacher;
	//while (!feof(fp))
	//{
	//	fread((void*)t, sizeof(Teacher), 1, fp);	//��������ط��ͷ���fread�����ˣ���fwriteͬʱʹ�ã���Ϊ����֪����С
	//	t->show();	//����һ�����һ���� ������Ϊ���Ǽ����һ�ζ���EOFû��,�����ͻᵼ�¶��һ��
	//}	
	//�������ȼ�飬�ٶ����ٵ���

	//����д�ܽ����������⣨�������ȶ���Ȼ���ڼ�飬����ٵ��ã�
	fread((void*)t, sizeof(Teacher), 1, fp);
	while (!feof(fp))
	{
		t->show();
		fread((void*)t, sizeof(Teacher), 1, fp);
	}

	fclose(fp);
	system("pause");
	return 0;
}

int main2()
{
	//��c��д
	char* path = "C:\\Users\\37916\\Desktop\\hello.txt";
	char ch;
	int len = 0;

	//д�ļ�
	FILE* fp = fopen(path, "a");
	fputc('I',fp);
	fputs(" love ������\n", fp);
	fclose(fp);

	//fseek(fp, 0, SEEK_SET); //ָ���ƶ�

	//���ļ�
	FILE* fpp = fopen(path, "r");
	
	//while (!feof(fpp))//�����ļ�βʱ������ֵ   //�������ǿ���ȫ����������  ��һ�ַ���
	//{
	//	fgets(buf, 1024, fpp);
	//	printf("%s", buf);
	//}

	while (!feof(fpp))							//������Ҳ�ǿ���ȫ����������  �ڶ��ַ���
	{
		ch = fgetc(fpp);						
		if (ch == 'M')							//���ַ�����һ���ô������ǿ���ɸѡ������Ҫ���ַ�
			continue;
		printf("%c", ch);
	}
	
	//char buf[1024];
	//while (!feof(fpp))
	//{
	//	fread(buf, 1, strlen(buf), fpp);			//�������������ͱ���ָ�����ȣ�����һ�����Ƕ���֪������
	//	printf("%s", buf);
	//}
	
	fclose(fpp);
	system("pause");
	return 0;
}

int main1()
{
	char* path = "C:\\Users\\37916\\Desktop\\hello.txt";
	char ch;

	//д�ļ�
	//ofstream fout(path);//ÿ�ζ����������д��Ĭ����ofstream fout(path,ios::out)  ��Ҫ׷��Ҫ�� app
	ofstream fout(path,ios::app);//��׷�ӵķ�ʽд��
	fout << "hello��������Im KangKang����" << endl;
	fout << "nice to meet you" << endl;
	fout.close();

	//���ļ�
	ifstream fin(path);
	while (fin.get(ch))
	{
		cout << ch;
	}
	fin.close();
	system("pause");
	return 0;
}