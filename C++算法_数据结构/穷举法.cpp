#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*��Ŀ������һ����άƽ���ϵ�n���㣬�ҵ�λ��ͬһֱ���ϵĵ�������Ŀ*/
/*
˼·����ÿһ����������ĵ������б�ʣ����ܵõ����������ܺͼ�������ͬһ��ֱ���� 
*/

class Point
{
public:
	int x,y;
	Point(int x = 0,int y = 0):x(x),y(y){}	
};

int getMaxPoint(vector<Point> &v)
{
	int size = v.size();
	if(0 == size) return 0;
	else if(1 == size) return 1;
	
	int res = 0;
	for(int i = 0; i < size; ++i)
	{
		map<double,int> map;//б�ʣ����� 
		int vcnt = 0; //��ֱ��
        int dup = 1; //�ظ���
        int curmax = 0;
		for(int j = i + 1; j < size; ++j)
		{
			if(v[i].x == v[j].x)
			{
				if(v[i].y == v[j].y)
					++dup;
				else
					++vcnt;
				curmax > vcnt ?: curmax = vcnt;
			}
			else
			{
				double k = (double)(v[i].y - v[j].y) / (v[i].x - v[j].x);//ע��������int / int = int   ��Ҫǿת double / int = double 
				curmax > ++map[k] ?: curmax = map[k];
			}
		}
		curmax += dup;
		res > curmax ?: res = curmax;
	}
	return res;
} 

int main()
{
	
}
