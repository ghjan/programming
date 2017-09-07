#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>//sort 
#include <functional>//greater
using namespace std;
//sort()���Դ���ַ��Ҳ���Դ�������
void stlTest()
{
	vector<int> v;
	srand(time(0));
	for (int i = 0; i<6; ++i)
		v.push_back(rand() % 100);
	sort(v.begin(), v.end());//Ĭ�ϴ�С����
	for (vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
		cout << *it << " ";
	cout << endl;

	sort(v.begin(), v.end(), greater<int>());//�Ӵ�С
	for (vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
		cout << *it << " ";
	cout << endl;
}
void test()
{
	int arr[6];
	for (int i = 0; i<6; ++i)
		arr[i] = rand() % 100;
	sort(arr, arr + 6);//����ַ����Ҳ����
	for (int i = 0; i < 6; ++i)
		cout << arr[i] << " ";
	cout << endl;

	sort(arr, arr + 6,greater<int>());
	for (int i = 0; i < 6; ++i)
		cout << arr[i] << " ";
	cout << endl;
}
int main()
{
	stlTest();
	test();
}

