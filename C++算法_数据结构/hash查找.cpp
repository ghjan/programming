/*
��ϣ������ͨ����������Ԫ�صĴ洢��ַ���в��ҵ�һ�ַ�����O(1)�Ĳ��ң�����ν����ɱ����ϣ���ҵı������Ƚ�����ӳ������Ĺ�ϣֵ����ϣ���ҵĺ����ǹ���һ����ϣ����������ԭ��ֱ�ۡ����������ӳ��Ϊ����ȥ�ƺ��������һЩ������
��ϣ���ҵĲ������裺

1)       �ø����Ĺ�ϣ���������ϣ��

2)       ����ѡ��ĳ�ͻ�����������ַ��ͻ��

3)       �ڹ�ϣ��Ļ�����ִ�й�ϣ���ҡ�

��ʵ���õ�����ϣ���ַ��С����֡���

��һ�֣���ֱ�Ӷ�ַ������

��������⣬key=Value+C�������C"�ǳ�����Value+C��ʵ����һ���򵥵Ĺ�ϣ������

�ڶ��֣�������ȡ�෨����

��������⣬ key=value%C;

(1)   ���ŵ�ַ������(�����⣬��һ������ɾ����ʱ���ٴβ��ң����Ҳ���������������ܲ��ҵ����ں���)  ��Ӧ�ñ��� 

�����������Ԫ�صĹ�ϣֵ��ͬ�����ڹ�ϣ����Ϊ����������Ԫ������ѡ��һ�������������ҹ�ϣ��ʱ�����û���ڵ�һ����Ӧ�Ĺ�ϣ�������ҵ����ϲ���Ҫ�������Ԫ�أ�����ͻ����������ң�ֱ���ҵ�һ�����ϲ���Ҫ�������Ԫ�أ���������һ���յı������

(2)   ����ַ��		(�뿴hash����2.cpp)

����ϣֵ��ͬ������Ԫ�ش����һ�������У��ڲ��ҹ�ϣ��Ĺ����У������ҵ��������ʱ������������Բ��ҷ�����
*/

//ʵ�ֹ�ϣ����Ϊ������ȡ�෨���������ͻΪ�����ŵ�ַ����̽�ⷨ�����������£�
#include <iostream>
#include <cstring>
#include <assert.h>
using namespace std;


//����hash����
template<class T>
int InsertHash(T *hashTable, int hashLen, T data)
{
	int addr = data % hashLen;
	int i = 0;
	//�����ͻ
	while (hashTable[addr] && i++ < hashLen)
	{
		if(hashTable[addr] == data)
			return -1;
		addr = ++addr % hashLen;
	}
	if (addr < hashLen)
	{
		hashTable[addr] = data;
		return addr;
	}
	return -1;
}
//��ֵ 
template<class T>
int FindInHashTable(T *hashTable, int hashLen, T data)
{
	int addr = data % hashLen;
	int i = 0;
	while (hashTable[addr] != data && i++ < hashLen)
	{
		addr = ++addr % hashLen;
	}
	if (addr < hashLen)
	{
		hashTable[addr] = data;
		return addr;
	}
	return -1;
}

int main()
{
	int len = 10;//���� 
	int *hashTable = new int[len];//��ϣ��
	memset(hashTable, 0, sizeof(int) * len);

	int arr[] = { 11, 2, 31, 5, 21, };
	for (int i = 0; i<sizeof(arr) / sizeof(arr[0]); i++)
	{
		InsertHash<int>(hashTable, len, arr[i]);
	}

	cout << FindInHashTable<int>(hashTable, len, 11) << endl;
	cout << FindInHashTable<int>(hashTable, len, 21) << endl;
}

