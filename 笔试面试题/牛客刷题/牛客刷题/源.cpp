/*
�����ж���������ݣ�����ÿ�����ݣ���������N������С�������������������Ľ����ÿ����ռһ�С�
��������:
3
11111111111111111111111111111
2222222222222222222222222222222222
33333333

�������:
33333333
11111111111111111111111111111
2222222222222222222222222222222222
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool comp(string a, string b)
{
	if (a.length() < b.length())
		return true;//����true˵����һ����Ҫ���ڵڶ���ǰ��
	else if (a.length() > b.length())
		return false;
	//˵��һ����
	return a < b;//string����ֱ�ӱȴ�С�����ֵ�����бȽϣ�a<b Ϊ�淵��true
}

int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> v(n);
		for (int i = 0; i < n; ++i)
			cin >> v[i];
		sort(v.begin(), v.end(),comp);
		//copy(v.begin(), v.end(), ostream_iterator<string>(cout, "\n"));
		for (vector<string>::iterator it = v.begin(); it != v.end(); ++it)
			cout << *it << endl;
	}
	return 0;
}