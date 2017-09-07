#include <iostream>
#include <list>
using namespace std;

class MemPool
{
private:
	void addMem()
	{
		if (chunkSize < 4)
			chunkSize = 4;
		int allocsize = chunkSize * size;//���ٵ��ܴ�С
		pHead = (Chunk *)new char[allocsize];
		Chunk *pCur = pHead;
		for (int i = 0; i < size - 1;++i)
		{
			pCur->pNext = (Chunk *)((char *)pCur + chunkSize);
			pCur = pCur->pNext;
		}
		pCur->pNext = NULL;
		//memList.push_back(pHead);
		cout << "��" << ++count << "��ϵͳ������" << allocsize << "�ֽ��ڴ�" << endl;
	}
public:
	MemPool(unsigned int size = 5, unsigned int chunkSize = 1024)
		:size(size), count(0), chunkSize(chunkSize)
	{ cout << "����" << endl; }
	~MemPool()
	{
		cout << " ����" << endl;
		/*for (list<Chunk *>::iterator it = memList.begin(); it != memList.end(); ++it)
			delete *it;*/
	}
	void *getMem()
	{
		Chunk *pCur;
		if (!pHead)//����ڴ治���ˣ���ϵͳ�����ڴ�
			addMem();
		pCur = pHead;
		pHead = pHead->pNext;
		return (void *)pCur;
	}
	void delMem(void *ptr)
	{
		if (!ptr) return;
		Chunk *cur = (Chunk *)ptr;
		cur->pNext = pHead;
		pHead = cur;
	}
	class Chunk
	{
	public:
		Chunk *pNext;
	};
public:
	//list<Chunk *> memList;//����Ҫ�������Ϊ�����������ڴ�й©��ֻ��new�������������û��delete���ѣ���������ڴ�й©���ڴ�й©�ǻᵼ��ϵͳ�����ڴ汻ռ����
	unsigned int size;//chunk����
	unsigned int chunkSize;//chunk��С
	Chunk *pHead;
	Chunk *pNext;
	int count;
};