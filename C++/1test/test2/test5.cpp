#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <list>
using namespace std;

extern int a;//����
int b;//������������
extern int c = 20;//����

void test5()
{
	//extern int d = 20;	//���ܶԴ��п鷶Χ���ⲿ�������г�ʼ��
}

char findMax(string s,int &index)
{
	char max = 0;
	int len = s.length();
	for (int i = 0; i < len; ++i)
	{
		if (max < s[i])
		{
			max = s[i];
			index = i;
		}
	}
	return max;
}
void test6()
{
	vector<string> v;
	string input;
	char cur, pre, next;
	int arr[1000][2];
	int n = 1;//�ڼ�����
	int maxstr[2];//���Ǹ������ĸ�λ��
	char max = 0;//�����Ǹ���
	int index = 0;//λ��
	while (cin >> input && input[0] != '\n')
	{
		if (max < findMax(input,index))
		{
			maxstr[0] = n;
			maxstr[1] = index;
			max = findMax(input, index);
		}
		++n;
		v.push_back(input);
	}
}