#include <iostream>
#include <vector>
using namespace std;

void test(vector<int> &v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end();)
	{
		if (*it % 2 == 0)
			it = v.erase(it);//���ﲻ��++
		else
			it++;
	}
}
void test2(vector<int> &v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end();)
	{
		if (*it % 3 == 0)
		{
			v.insert(it,10);//ע����������3��ǰ�����10   ��Ȼ����������ʧЧ������++it�ֱ����3 ��ѭ��������Ҫ++����
			++it;
			++it;
		}
		else
			it++;
	}
	//�������ļ�д��ʽ
	for (vector<int>::iterator it = v.begin(); it != v.end();++it)
	{
		if (*it % 3 == 0)
			v.insert(it++, 10);//ע����������3��ǰ�����10   ��Ȼ����������ʧЧ������++it�ֱ����3 ��ѭ��������Ҫ++����
	}
}
void print(vector<int> &v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		cout << *it << endl;
}
int main2()
{
	vector<int> v;

	for (int i = 0; i < 6; ++i)
		v.push_back(i);
	//for (int i = 0; i < 6; ++i)
	//	v[i] = i;//�����ýǱ꣬�ʼû���ڴ棬�ýǱ����ַ���Խ�磬��������������ڴ��������

	test(v);
	print(v);
	cout << "-------------------------" << endl;
	test2(v);
	print(v);

	system("pause");
	return 0;
}