#include <iostream>
#include <cstring>
using namespace std;

void swap(char *a, char *b)
{
	char t = *a;
	*a = *b;
	*b = t;
}
//���������ǲ��е�                           Ϊʲô�أ�д�������Դ����֪���� 
//void perm(char *str, int start, int end)
//{
//	if (start >= end)
//		cout << str << endl;
//	else
//		for (int i = start ;i <= end ; i++)
//		{
//			if(str[start] != str[i] || start == i)
//			{
//				swap(str+start,str + i);
//				perm(str,start + 1,end);
//				swap(str+start,str + i);
//			} 
//		}
//}

//�ڽ���֮ǰ�ж�һ�£�end��ǰ����ľ�к��Լ�һ���������еĻ��Ͳ�������
bool IsSwap(char *arr,int start,int end)
{
	while(start < end)
		if(arr[start++] == arr[end])
			return false;
	return true;
}
void perm(char *str, int start, int end)
{
	if (start >= end)
	{
		static int i = 1;
		cout << i++ << ":" << str << endl;
	}
	else
		for(int i = start; i <= end; i++)
			if(IsSwap(str,start,i))
			{
				swap(str+start,str + i);
				perm(str,start + 1,end);
				swap(str+start,str + i);	
			}
}
int main()
{
	char str[] = "1100";
	perm(str, 0, strlen(str) - 1);
}
