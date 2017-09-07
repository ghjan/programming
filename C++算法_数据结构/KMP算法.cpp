#include <iostream>
#include <cstring>
using namespace std;

//���˽�KMP�㷨֮ǰ�������˽�bf�㷨

int bf(char *str, char *substr, int index)	// index���û�ָ����str�����������λ�ÿ�ʼƥ��
{
	int slen = strlen(str);
	int sublen = strlen(substr);
	int i = index;
	int j = 0;
	while (j<sublen)
	{
		if (i >= slen)
			return -1;
		if (str[i] == substr[j])
		{
			i++; j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	return i - j;
}
//KMP�㷨
//  a b c a b c a b c a b c d a b c d e
//  x 0 0 0 1 2 3 4 5 6 7 8 9 0 1 2 3 0
//////////////////////////////////////////////////////////////////////////////////////////////////
/* ����next�����м�¼���ǣ����ƥ��ʧ��֮��jӦ�û��˵�kλ��ȥ    ע�⣺i�������*/
void getNext(char *substr, int *&next)
{
	int sublen = strlen(substr);
	if (sublen == 0)
		return;
	next = new int[sublen];
	next[0] = -1;//��һ���Ǳ�����Ĭ�ϳ�ʼ��Ϊ-1 
	if (sublen == 1)
		return;
	next[1] = 0;//�ڶ����Ǳ��ʼ��Ϊ0
	 
	/*Ū�����Ǳ������һǰһ�������i + 1λ��ƥ��ʧ��Ӧ�û��˵�λ��*/ 
	int i = 1, k = 0; 
	while (i < sublen)
	{
		if (-1 == k || substr[k] == substr[i])// i + 1 λ��ƥ��ʧ�ܵ��� i λ�ú� k λ���ַ���� 
			next[++i] = ++k;
		// else				//				   ������� a b c a b a b c
			// next[i] = 0; 				//	   	   -1 0 0 0 1 2 1 2  ���Բ�����ÿ�ζ��ص� 0 λ��  ����ͻص���1 
		else
			k = next[k];// i+1λ����ƥ��ʧ���ˣ�����i λ�� �� k λ�ò���ȣ����Ǿ�Ҫ���˵� ��kλ��ƥ��ʧ�ܡ�����˵�λ����ȥ
						//���൱�ڰ�k��ǰ�Ĵ��������Ӵ���i��ǰ�Ĵ������˸��� ��Ϊʲô������������kλ��ƥ��ʧ�ܻ��˵�λ�������Ѿ�֪����,k��С��i�ġ� 
	}
}
int KMP1(char *str, char *substr, int index)
{
	int slen = strlen(str);
	int sublen = strlen(substr);
	int i = index;
	int j = 0;
	int *next;
	getNext(substr, next);
	while (j<sublen)
	{
		if (i >= slen)
			return -1;
		if (-1 == j || str[i] == substr[j])
		{
			i++; j++;
		}
		else
			j = next[j];
	}
	return i - j;
}
//////////////////////////////////////////////////////////////////////////////////////////////////
/* 
����nextVal��next�������汾 ������substr="aaaaab" ����������������Ч
										  x01234  
	��str = "aaaacaaaaab" ����ƥ�䵽c��ʱ��ʧ�ܣ������next��ôӦ���ܵ�k = 3��λ����ȥ��
	��ʵ����3λ��Ҳ�ǡ�a�����´αȽϾ�������Ч�Ƚϣ����ǻ��ٴλص���һ��k,��������nextVal�����Ż�		a a a a a b a a b a
																									   -1 0 0 0 0 1 0 0 2 0
*/
void getNextVal(char *substr, int *&nextVal)
{
	int sublen = strlen(substr);
	if (sublen == 0)
		return;
	nextVal = new int[sublen];
	nextVal[0] = -1;
	if (sublen == 1)
		return;
	nextVal[1] = 0;
	int i = 1;
	int k = 0;
	while(i<sublen)
	{
		if(-1 == k || substr[k] == substr[i]) 
		{
			if(substr[i + 1] == substr[i])
				nextVal[i + 1] = nextVal[i];
			else
				nextVal[i + 1] = ++k;
			++i;
		}
		else
			k = nextVal[k];
	}
}
int KMP2(char *str, char *substr, int index)
{
	int slen = strlen(str);
	int sublen = strlen(substr);
	int i = index;
	int j = 0;
	int *nextVal;
	getNextVal(substr,nextVal);
	while (j<sublen)
	{
		if (i >= slen)
			return -1;
		if (-1 == j || str[i] == substr[j])
		{
			i++; j++;
		}
		else
		{
			j = nextVal[j];
		}
	}
	return i - j;
}
int main()
{
	char *str = "ababcabcdabcde";
	char *substr = "abcd";
	int res = bf(str, substr, 0);
	cout << "bf :" << res << endl;
	res = bf(str, substr, 6);
	cout << "bf :" << res << endl;

	res = KMP1(str, substr, 0);
	cout << "KMP :" << res << endl;
	res = KMP1(str, substr, 6);
	cout << "KMP :" << res << endl;

	str = "aaabcaaabcabcf";
	substr = "aaabcabcf";
	//		  x001230
	res = KMP1(str, substr, 0);
	cout << "KMP1 :" << res << endl;

	res = KMP2(str, substr, 0);
	cout << "KMP2 :" << res << endl;
}
