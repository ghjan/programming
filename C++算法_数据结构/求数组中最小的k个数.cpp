#include <iostream>
#include <set>
#include <vector>
#include <functional>
using namespace std;

//����������С��k����
//��õĽⷨ�ǣ�����һ���ռ䣬����ռ�ֻ�����С��k����������ÿ����һ�������п��ܶ���Ƭ�ڴ������Ķ�
//��Ƭ�ڴ�������뵽������һ�����ѣ����Ƕ�ʱ�����Ǻ���ʵ�֣�����������Թ�û��Ҫ����ʹ��stl�����ǿ�����multiset���ϣ��ײ��õ��Ǻ���� 

//																�ⱨ��vs��û���� 
void GetLeastNum(const vector<int>& data, multiset<int, greater<int>> &maxNum, int k)
{
	if (k < 1 || data.size() < k)
		return;
	maxNum.clear();
	for (vector<int>::const_iterator it = data.begin(); it != data.end(); it++)
	{
		if (maxNum.size() < k)
			maxNum.insert(*it);
		else
		{
			if (*it < *maxNum.begin())
			{
				maxNum.erase(maxNum.begin());
				maxNum.insert(*it);
			}
		}
	}

	for (multiset<int, greater<int>>::iterator it = maxNum.begin(); it != maxNum.end(); it++)
		cout << *it << " ";
	cout << endl;
}

int main()
{
	multiset<int, greater<int>> maxNum;
	vector<int> data;
	for (int i = 10; i >= 0; i--)
	{
		data.push_back(i);
	}
	GetLeastNum(data, maxNum, 4);
	getchar();
}
