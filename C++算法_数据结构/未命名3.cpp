//����Ȼ��N�ֽ�����ɸ�������ͬ��������֮�ͣ�ʹ�˻����

#include <iostream>
using namespace std;

/*�ҵ�һ����������������֮��*/
int maxmul(int min, int max)
{
	int sum = 1;
	for (; min <= max; min++)
		sum *= min;
	return sum;
}
int findMaxMul(int n)
{
	int min = 0, max = 1, sum = 1;
	while(min <= n / 2)
	{
		if(sum == n)
			return maxmul(min,max);
		else if(sum > n)
		{
			sum -= min;
			++min;
		}
		else
			sum += ++max;
	}
	return 0;
}

int main()
{
	int n;
	cin>>n;
	cout<<findMaxMul(n)<<endl;
}
