#include <fstream>
#include <iostream>
#include <string>
#include "Teacher.h"
using namespace std;

int main()
{
	char* path = "E:\\programming\\C++����\\��׼IO��\\�ļ���д\\TeacherProperty.txt";

	Teacher* t1 = new Teacher("������", 20);
	Teacher* t2 = new Teacher("����ӱ", 28);
	Teacher* t3 = new Teacher("����", 50);

	ofstream fout(path, ios::binary);//��2���Ʒ�ʽ�洢
	fout.write((char*)t1, sizeof(Teacher));
	fout.write((char*)t2, sizeof(Teacher));
	fout.write((char*)t3, sizeof(Teacher));
	fout.close();

	ifstream fin(path);
	Teacher* t = new Teacher;
	fin.read((char*)t, sizeof(Teacher));
	while (!fin.eof())
	{
		t->show();
		fin.read((char*)t, sizeof(Teacher));
	}
	fin.close();


	system("pause");
	return 0;
}