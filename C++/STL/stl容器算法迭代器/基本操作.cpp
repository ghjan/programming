#include <iostream>
#include <vector>
#include <string>
using namespace std;


void test4()
{
	vector<int> v(2);//��ʼ������Ϊ10������  ����ֵΪ0
	cout << v.size() << endl;

	v.push_back(9);
	v.push_back(10);

	cout << v.back() << endl;

	v.pop_back();

	cout << v.back() << endl;
	cout << v.front() << endl;
}

//��ʼ���ļ��ַ���
void test5()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	vector<int> v2 = v;
	for (int i = 0; i < 4; i++)
	{
		cout << v2[i] << endl;
	}

	cout << "------------" << endl;
	vector<int> v3(v);
	for (int i = 0; i < 4; i++)
	{
		cout << v3[i] << endl;
	}

	cout << "------------" << endl;
	vector<int> v4(v.begin() + 1, v.begin() + 3);//��1 ��ʼ  �� 3ǰ�� copy
	for (vector<int>::iterator it = v4.begin() ; it != v4.end(); it++)
	{
		cout << *it << endl;// 2 3
	}

	cout << "------------" << endl;
	vector<int> v5(5, 1);			//��ʼ����������Ϊ5  ����ȫ����ֵΪ1
	for (int i = 0; i < 5; i++)
	{
		cout << v5[i] << endl;
	}
}
//���Բ���ÿ�ζ�push��ȥ
void test6()
{
	vector<int> v(10);
	for (int i = 9; i >= 0; i--)
	{
		v[i] = 10 - i;//������ֵҲ�ǿ��Եġ������и�ǰ�᣺�������빻
	}

	v[5] = 1000;

	for (int i = 0; i < 10; i++)
	{
		cout << v[i] << endl;
	}

	cout << "--------------" << endl;
	//���������
	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
	{
		cout << *it << endl;
	}

	//������
	//		1	2	3
	//      ��					//v.begin()��λ��
	//			    	��		//v.end()��λ��
	cout << "--------------" << endl;
	for (vector<int>::iterator it = v.end() - 1; it != v.begin(); it--)	//v.begin() - 1 ��� �������������������Ҫ���������ʼ��Ԫ��
	{
		cout << *it << endl;
	}
	cout << v.front() << endl;

}
//ɾ��
void test7()
{
	vector<int> v(10);

	for (int i = 0; i < 10; i++)
	{
		v[i] = i;
	}
	v.push_back(5);

	
	//����ɾ��
	v.erase(v.begin() + 1, v.begin() + 3);//���� Ԫ��  1 2 �ͱ�ɾ����

	//��λ��ɾ��
	v.erase(v.begin());//����0 �ͱ�ɾ����


	cout << "--------------" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}

	cout << "--------------" << endl;
	//ɾ��ָ����ֵ
	for (vector<int>::iterator it = v.begin(); it != v.end(); )
	{
		if (*it == 5)
		{
			it = v.erase(it);//erase ����һ����������ָ����һ��λ�á��������ﲻ����it++�ˣ���Ȼ������һ��Ԫ�ز���飬����������Ԫ����ĩβ��ֱ�ӹҵ�
		}
		else
		{
			it++;
		}
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}
}
//����
void test8()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	//pushֻ�ܲ��뵽β���������������ͷ����Ԫ�أ���ô����insert
	v.insert(v.begin(), 100);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}
	cout << "--------------" << endl;

	//���ҿ���������λ�ò���
	v.insert(v.begin() + 2, 999);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}
	cout << "--------------" << endl;
}