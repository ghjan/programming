#include<iostream>
using namespace std;

namespace str1
{
	char s1[10] = "dong";
}
namespace str2
{
	char s2[10] = "hello";
}
namespace str1//�������Ǹ�str1 ��ͬһ�������ռ�
{
	char s3[10] = "world";
	void show()
	{
		cout << str1::s1 << endl;
	}
}
//�����ռ��������Ƕ��
namespace nesting1
{
	namespace nesting2
	{
		namespace str1//�������str1 ��ͬ
		{
			char s[10]{"dong"};
		}
		namespace str1
		{
			void show(int num)
			{
				cout << num << endl;
				cout << s << endl;
			}
		}
	}
}

void main()
{
	cout << str1::s1 << endl;
	cout << str2::s2 << endl;
	cout << str1::s3 << endl;
	str1::show();

	nesting1::nesting2::str1::show(1234);

	cin.get();
}