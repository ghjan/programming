#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class TowArray{
public:
	int x, y;
	TowArray(int x, int y) :x(x), y(y){}
	bool operator < (const TowArray &ta){
		if (x < ta.x){
			return true;//1��ʾta.x����ǰ
		}
		else if (x > ta.x){
			return false;
		}
		else{
			if (y <= ta.y){
				return false;
			}
			else if (y > ta.y){
				return true;
			}
		}
	}
};
//�Զ�Ԫ�����򣬣�x,y�� ��x����y��������
bool SortTowArray(const TowArray &ta1, const TowArray &ta2) {
	return true;
}
int main() {
	int x, y;
	vector<TowArray> v;
	while (cin >> x >> y){
		TowArray *ta = new TowArray(x, y);
		v.push_back(*ta);
	}
	sort(v.begin(), v.end());

	auto it = v.begin();
	while (it != v.end()){
		cout << "(" << (*it).x << "," << (*it).y << ")" << endl;
		it++;
	}
	system("pause");
}
/*
5 5
3 2
3 6
5 3
1 2
1 2
^Z
*/
