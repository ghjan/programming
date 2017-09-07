#define  _CRT_SECURE_NO_WARNINGS
#pragma once
#pragma excution_character_set("utf-8")

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Student
{
public:
	string name;
	Student(string _name)
	{
		name = _name;
	}
	Student(const Student &s)
	{
		cout << "�������� ���ǣ�"<<s.name << endl;
		//name = s.name;	//���
		
		name = s.name.c_str();//ǳ����		//string.c_str��Borland��װ��String���е�һ�������������ص�ǰ�ַ��������ַ���ַ��
	}
};
class Student2
{
public:
	char* name;
	Student2(char* _name)
	{
		name = _name;
	}
	Student2(const Student2 &s)
	{
		cout << "�������� ���ǣ�" << s.name << endl;

		name = s.name;//ǳ����
	}
};



void test3()
{
	Student* s1 = new Student("������");
	Student* s2 = new Student("����");
	vector<Student*> v;
	v.push_back(s1);//ֱ�Ӵ��ĵ�ַ��ȥ������û�е��ÿ������죩(Ҳ����˵��ǳ����)
	v.push_back(s2);

	for (vector<Student*>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << (*it)->name << "  ";
		if ((*it)->name == "����")
		{
			(*it)->name = "����";
		}
	}
	cout << endl;

	cout << s1->name << "  " << s2->name << endl;
}

void test2()
{
	Student s1("������");
	Student s2("����");
	Student s3("�����");
	vector<Student> v;
	v.push_back(s1);//���������
	v.push_back(s2);
	v.push_back(s3);
	cout << "---------------------" << endl;
	for (vector<Student>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << (*it).name << "  ";
		if ((*it).name == "����")
		{
			(*it).name = "����";
		}
	}
	cout << endl;
	cout << s1.name << "  " << s2.name << "  " << s3.name << endl;

	//	�������� ���ǣ�������
	//	�������� ���ǣ�������
	//	�������� ���ǣ�����				// 1
	//	�������� ���ǣ�������
	//	�������� ���ǣ�����
	//	�������� ���ǣ������			// 2  ���������ط����Կ��������õ�������洢��ʽ��ÿ�μ�һ��Ԫ�أ�����Ԫ�ض�Ҫ�ƶ�����Ҫ�������
	//	----------------------
	//	������  ����  �����
	//	������  ����  �����
}

void test1()
{
	vector<int> v;
	for (int i = 0; i < 9; i++)
	{
		v.push_back(i);
	}
	v.push_back(5);
	v.push_back(5);
	v.push_back(6);

	//������
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}
	//�㷨
	int num1 = count(v.begin(), v.end(), 5);//�� 5  �ĸ���
	int num2 = count(v.begin(), v.end(), 6);//�� 6  �ĸ���
	cout << endl << "---------------------------" << endl;
	cout << "5�ĸ��� = " << num1 << endl;
	cout << "6�ĸ��� = " << num2 << endl;

}


