#include <iostream>
using namespace std;
//��ת���֣�123 -�� 321 		 -123 -�� -321 
int reverse(int x)
{
	int res = 0;
	while(x)
	{
		res *= 10;
		res += x % 10;					//ע��   -123 % 10 = -3 ������������������ 
		if(res > 0x7fffffff)
			return 0;
		x /= 10;
	}
	return res;
}

int main()
{
//	cout<<0x7fffffff<<endl;
//	cout<<0x7fffffff + 1<<endl;
	int x;
	while(1)
	{
		cin>>x;
		cout<<reverse(x)<<endl;
	}
}
