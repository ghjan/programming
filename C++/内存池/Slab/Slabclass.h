#include <iostream>
#include <vector>
using namespace std;

class Slab
{
private:
	union{
		Slab *head;
		Slab *next;
	};
	int slabSize;//slab������
	int perslab;//ÿ�� slab �����зֳɶ��ٸ� chunk
	int chunkSize;
public:
	vector<Slab *> slab_list;//ÿ����Slab����ʼ��ַ
	int memAll;//������
	int memAvail;//��������
	int count;//new�˼���Slab
private:
	void addMem()
	{
		try
		{
			head = (Slab *)new char[slabSize];
		}
		catch (const bad_alloc &err)
		{
			cout << "new Slabʧ��" << endl;
			return;
		}
		Slab *temp = head;
		for (int i = 0; i < perslab - 1; ++i)
		{
			temp->next = (Slab *)((char *)temp + chunkSize);
			temp = temp->next;
		}
		temp->next = NULL;
		slab_list.push_back(head);
		++count;
		memAll += slabSize;
		memAvail += slabSize;
	}
public:
	Slab(){}
	~Slab()
	{
		for (vector<Slab*>::iterator it = slab_list.begin(); it != slab_list.end(); ++it)
			delete (char *)*it;
	}
	bool init(int slabSize, int chunkSize)
	{
		this->slabSize = slabSize;
		this->chunkSize = chunkSize;
		this->memAll = 0;
		this->memAvail = 0;
		this->count = 0;
		this->head = NULL;
		perslab = slabSize / chunkSize;
		if (perslab <= 0)
			return false;
		//////////////����������ʹ�õ�ʱ����new�ڴ�(�ͺ�����ʽ�Ͷ���ʽ˼����)�����ö���ʽ////////////////
		addMem();
		return true;
	}
	void *getChunk()
	{
		if (!head)
			addMem();
		Slab *cur = head;
		head = head->next;
		memAvail -= chunkSize;
		return (void *)cur;
	}
	void removeChunk(void *ptr)
	{
		Slab *pre = (Slab *)ptr;
		pre->next = head;
		head = pre;
		memAvail += chunkSize;
		ptr = NULL;
	}
	int getChunkSize()
	{
		return chunkSize;
	}
	int getSlabSize()
	{
		return slabSize;
	}
	int getPerslab()
	{
		return perslab;
	}
};

class SlabAlloction
{
private:
	Slab *slabClass;
	int slabClassNum;
	double ratio;//ÿ��slabClass �����ı���
public:
	SlabAlloction(int chunkSize = 64, int slabSize = 1024 * 1024, int slabClassNum = 10, double ratio = 1.5)//һ��SlabĬ��1M��С
		:slabClassNum(slabClassNum), ratio(ratio)
	{
		if (chunkSize < 4)
			chunkSize = 4;//�������4B
		try
		{
			slabClass = new Slab[slabClassNum];
		}
		catch (const bad_alloc &err)
		{
			cout << "new slabClassʧ��" << endl;
			return;
		}
		for (int i = 0; i < slabClassNum; ++i)
		{
			if (!slabClass[i].init(slabSize, chunkSize))
			{
				cout << "slabClass" << i << "����ʧ�� �� chunkSize > slabSize ��" << endl;
				return;
			}
			chunkSize *= ratio;
		}
	}
	~SlabAlloction()
	{
		delete[]slabClass;
	}
	int findSuitSlab(int size)
	{
		int i = 0;
		for (; i < slabClassNum; ++i)
			if (slabClass[i].getChunkSize() >= size)
				break;
		return i;
	}
	void *salloc(int size)
	{
		int suitslab = findSuitSlab(size);
		if (suitslab == slabClassNum)
		{
			cout << "Slab�ڴ治����" << endl;
			return NULL;
		}
		return slabClass[suitslab].getChunk();
	}
	void sfree(void *ptr)
	{
		int size = ((Slab *)ptr)->getChunkSize();
		for (int i = 0; i < slabClassNum; ++i)
		{
			int count = slabClass[i].count;
			for (int j = 0; j < count; ++j)
			{
				if (slabClass[i].slab_list[j] < ptr &&
					slabClass[i].slab_list[j] + slabClass[i].getSlabSize() > ptr)
				{
					slabClass[i].removeChunk(ptr);
					ptr = NULL;
					return;
				}
			}
		}
		cout << "����0x" << ptr << "�ڴ�ʧ��" << endl;
	}
	int getSlabClassNum()
	{
		return slabClassNum;
	}
	void showSlabClassChunk()
	{
		for (int i = 0; i < slabClassNum; ++i)
		{
			cout << "slabClass" << i << endl;
			cout << "��������" << slabClass[i].memAll << endl;
			cout << "����������" << slabClass[i].memAvail << endl;
			cout << "new�˼���Slab��" << slabClass[i].count << endl;
			cout << "SlabSize:" << slabClass[i].getSlabSize() << endl;
			cout << "ChunkSize:" << slabClass[i].getChunkSize() << endl;
			cout << "Perslab:" << slabClass[i].getPerslab() << endl;
			cout << "--------------------------------------" << endl;
		}
	}
};