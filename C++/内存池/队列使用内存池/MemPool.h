#include <iostream>
template<typename T>
class MemPool
{
public:
	MemPool(){ cout << "����" << endl; }
	MemPool(T data) :data(data){ cout << "���� data" << endl; }
	~MemPool(){ cout << "����" << endl; }
	//������������������Ĭ�ϴ����static����
	void *operator new(size_t size)
	{
		MemPool *pCur;
		if (!pHead)//����ڴ治���ˣ���ϵͳ�����ڴ�
		{
			int allocsize = size * MEM_POOL_SIZE;
			cout << "��" << ++count << "��ϵͳ������" << allocsize << "�ֽ��ڴ�" << endl;
			pHead = (MemPool*)new char[allocsize];
			for (pCur = pHead; pCur < pHead + MEM_POOL_SIZE - 1;++pCur)
				pCur->pNext = pCur + 1;
			pCur->pNext = NULL;
		}
		pCur = pHead;
		pHead = pHead->pNext;
		return pCur;//����ֻ�ǰ�����һƬ�ڴ���û��ˣ��û�������ͨ�� ->pNext �õ���һƬ�ڴ������
	}
	/*����ᷢ���ڴ��������Ϊ������û���ͷţ����ҿ���memcached��˵*/
	void operator delete(void *ptr)
	{
		cout << "MemPool delete" << endl;
		if (!ptr) return;
		MemPool *cur = (MemPool*)ptr;
		cur->pNext = pHead;
		pHead = cur;
	}
public:
	MemPool *pNext;
	static const unsigned int MEM_POOL_SIZE = 10;
	static MemPool *pHead;
	static int count;
	T data;
};
template<typename T>
MemPool<T> *MemPool<T>::pHead = NULL;
template<typename T>
int MemPool<T>::count = 0;