#include <iostream>
#include <cstddef>
using namespace std;

/*
int &dd  �͵ȼ���  int * const dd 

���� ���ò���ָ���   int* const dd ����ָ��� 
*/
int main()
{
	int d = 10;
	int e = 20;
	
	int &dd = d;
	int * const dd2 = NULL;

	//int &dd = NULL;
	
//	*dd2 = e;
//	dd = e;
//	
//	cout<<dd<<endl;
//	cout<<*dd2<<endl;
	
}
/*

*/
