#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>
using namespace std;

void myCopy()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	//����1λ
	int len = sizeof(arr) / sizeof(arr[0]);
	copy(arr + 1, arr + len,arr);//����ͷ��������β�������� + len 
	for (int i = 0; i < len; ++i)
		cout << arr[i] << " ";
	cout << endl;
}
void myCopy2()
{
	int ia[] = { 0, 1, 1, 3, 5, 8, 13 };
	vector<int> vec(ia, ia + 7);//����ͷ��������β
	ostream_iterator< int > ofile(cout, " ");
	copy(vec.begin(), vec.end(), ofile);
	cout << endl;
	// ���� 1 λ
	copy(ia + 1, ia + 7, ia);
	copy(ia, ia + 7, ofile);
	cout << endl;
	// ���� 2 λ
	copy(vec.begin() + 2, vec.end(), vec.begin());
	copy(vec.begin(), vec.end(), ofile); cout << '\n';
}