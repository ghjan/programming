//С����һ��Բ��������ԭ���Բ��С��֪��Բ�İ뾶��ƽ����С����Ϊ��Բ�ϵĵ���Һ������궼�������ĵ������ŵģ�С��������Ѱ��һ���㷨��������ŵĵ�ĸ������������������
//���磺�뾶��ƽ�����Ϊ25
//���ŵĵ���У�(+/ -3, +/ -4), (+/ -4, +/ -3), (0, +/ -5) (+/ -5, 0)��һ��12���㡣
//�������� :
//����Ϊһ����������ΪԲ�뾶��ƽ��, ��Χ��32λint��Χ�ڡ�
//
//
//������� :
//���Ϊһ����������Ϊ���ŵĵ�ĸ���

#include<iostream>
#include<cmath>
using namespace std;

//caseͨ����Ϊ100.00%
int main()
{
	int r2, sum = 0;
	cin >> r2;
	int r = sqrt(r2);//����һ��ʡ��С���İ뾶
	if (r2 == r*r)
		sum = 4;
	int jj = r;//�Ż��õı���������Ҫÿ�ζ���r��ʼ
	for (int i = 1; i <= r; i++)
	{
		for (int j = jj; j > 0; j--)
		{
			int len2 = i*i + j*j;
			if (len2 == r2)
			{
				sum+=4;
				jj = j;
				break;
			}
			if (len2 < r2)
				break;
		}
	}
	cout << sum << endl;
	system("pause");
	return  0;
}
//ͨ����80%
int main3()
{
	int r2, sum = 0;
	cin >> r2;
	int r = sqrt(r2);//����һ��ʡ��С���İ뾶
	for (int i = -r; i <= r; i++)
	{
		for (int j = r; j >=0; j--)
		{
			if (i*i + j*j == r2)
			{
				sum++;
				if (j != 0)
					sum++;
				break;//����ҵ�һ����ô�����������y���ٳ�����
			}
		}
	}
	cout << sum << endl;

	system("pause");
	return  0;
}
//ͨ����80%
int main2()
{
	int r2, sum = 0;
	cin >> r2;
	int r = sqrt(r2);//����һ��ʡ��С���İ뾶
	for (int i = -r; i <= r; i++)
	{
		for (int j = 0; j <= r; j++)
		{
			if (i*i + j*j == r2)
			{
				sum++;
				if (j != 0)
					sum++;
			}
		}
	}
	cout << sum << endl;

	system("pause");
	return  0;
}

//ͨ����  70%
int main1()
{
	int r2, sum = 0;
	cin >> r2;
	int r = sqrt(r2);//����һ��ʡ��С���İ뾶
	for (int i = -r; i <= r; i++)
	{
		for (int j = -r; j <= r; j++)
		{
			if (i*i + j*j == r2)
				sum++;
		}
	}
	cout << sum << endl;

	system("pause");
	return  0;
}