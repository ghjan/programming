#include <iostream>
using namespace std;

int main()
{
	typedef int(dong)[10];
	typedef int (chen)[10]; //�Ӳ��ӿո�һ����������������� 
	chen arr1;
	dong arr2;
	cout<<sizeof(arr1)<<"   "<<sizeof(arr2)<<endl;
}
