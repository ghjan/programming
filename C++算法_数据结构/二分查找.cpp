#include <iostream>
#include <vector>
using namespace std;
//��ͨ
int BinarySearch(vector<int> v, int key){
	int l = 0, r = v.size() - 1, mid;
	while (l <= r){
		mid = (l + r) / 2;
		if (key > v[mid]){
			l = mid + 1;
		}
		else if (key < v[mid]){
			r = mid - 1;
		}
		else{
			return mid;
		}
	}
	return -1;
}
//���ҵ�һ����key���Ԫ��
int BinarySearch2(vector<int> v, int key){
	int l = 0, r = v.size() - 1, mid;
	while (l <= r){
		mid = (l + r) / 2;
		if (key > v[mid]){
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	if (l >= v.size()){
		l = -1;
	}
	return l;
}
int main() {
	int arr[] = { 203, 39, 186, 207, 83, 80, 89, 237, 247 };
	int n = sizeof(arr) / sizeof(int);
	vector<int> v(arr, arr + n);
	cout << BinarySearch2(v, 248) << endl;
	system("pause");
}
