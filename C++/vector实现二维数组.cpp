#include <iostream> 
#include <vector>
using namespace std;

int main()
{
	int row = 5;
	int col = 6;
	/* ��vector һ�仰��ɶ�ά����Ľ���+��ʼ��*/
	vector<vector<int> > v(row,vector<int>(col,0));//ע��dev���� >> �������� > >�ӿո�ͺ� 
	
	for(int i = 0;i<row;++i)
	{
		for(int j = 0;j<col;++j)
			cout<<v[i][j]<<" ";
		cout<<endl;
	}
	
}

