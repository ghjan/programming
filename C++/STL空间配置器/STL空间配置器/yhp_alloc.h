#ifndef YHP_ALLOC_H
#define YHP_ALLOC_H

namespace yhp
{
#if 0
#include<new>
#define __THROW_BAD_ALLOC throw std::bad_alloc()
#elif !defined(__THROW_BAD_ALLOC)
#include<iostream>
#define __THROW_BAD_ALLOC std::cerr<<"out of memory"<<std::endl; exit(1)
#endif

/*һ���ռ�������*/
template<int inst>
class __malloc_alloc_template
{
private:
	/*�����������������ڴ治��ʱ���õ�*/
	static void *oom_malloc(size_t n)
	{
		void(*my_malloc_handler)() = NULL;
		void *result = NULL;
		for (;;)
		{
			my_malloc_handler = __malloc_alloc_oom_handler;
			if (NULL == my_malloc_handler)
			{
				__THROW_BAD_ALLOC;
			}
			(*my_malloc_handler)();
			result = malloc(n);
			if (NULL != result)
				return result;
		}
	}
	static void *oom_realloc(void *p, size_t n)
	{
		void(*my_malloc_handler)() = NULL;
		void *result = NULL;
		for (;;)
		{
			my_malloc_handler = __malloc_alloc_oom_handler;
			if (NULL == my_malloc_handler)
			{
				__THROW_BAD_ALLOC;
			}
			(*my_malloc_handler)();
			result = realloc(p, n);
			if (NULL != result)
				return result;
		}
	}
	/*�������ָ�����ָ��һ�������ͷ��ڴ�ĺ��������������������ж�������ͷ��ڴ�ĺ����͵����������*/
	static void(*__malloc_alloc_oom_handler)();
public:
	static void *allocate(size_t n)
	{
		void * result = malloc(n);
		if (result == NULL)
		{
			result = oom_malloc(n);
		}
		return result;
	}
	static void deallocate(void *p, size_t/* n*/)
	{
		free(p);
	}
	static void *reallocate(void *p, size_t /*old_sz*/, size_t new_sz)
	{
		void *result = realloc(p, new_sz);
		if (NULL == result)
		{
			result = oom_realloc(p, new_sz);
		}
		return result;
	}

	static void(*set_malloc_handler(void(*f)()))()
	{
		void(*old)() = __malloc_alloc_oom_handler;
		__malloc_alloc_oom_handler = f;
		return old;
	}
};

typedef __malloc_alloc_template<0> malloc_alloc;

#if 0
//�������û��Ҫ�ͷ��ڴ�Ͱ�__malloc_alloc_oom_handler = NULL
template<int inst>
void(*__malloc_alloc_template<inst>::__malloc_alloc_oom_handler)() = NULL;
#else
//��������ڴ�غ��п������벻���ڴ�
char *preMem = new char[1024 * 1024 * 10];//������new��10M�ڴ����
void delPreMem()
{
	delete preMem;//�ͷ��ʼ������ڴ�
}
template<int inst>
void(*__malloc_alloc_template<inst>::__malloc_alloc_oom_handler)() = delPreMem;
#endif

/*�����ռ�������*/
enum { __ALIGN = 8 };							//ÿ��chunk֮��ļ�� 0 8 16 24
enum { __MAX_BYTES = 128 };						//����chunk
enum { __NFREELISTS = __MAX_BYTES / __ALIGN };	//list�����м���chunk
template<bool threads, int inst>
class __default_malloc_template
{
private:
	union obj
	{
		union obj * free_list_link;				//��һ����ͬchunk��С�ĵ�ַ
		char client_data[1];
	};

	static obj * volatile free_list[__NFREELISTS];//��������һ��16��Ԫ��
	/*�ϵ�bytes��8�ı���*/
	static size_t ROUND_UP(size_t bytes)
	{
		return (bytes + __ALIGN - 1) & ~(__ALIGN - 1);//��  (bytes + 7) / 8 * 8;ԭ��һ��,�������ƶ�3λ�������ƶ�3λ �� ��0x11111000��Ч��һ��
	}
	/*�ҵ�bytes��free_list�е�λ��*/
	static size_t FREELIST_INDEX(size_t bytes)
	{
		//return (bytes + __ALIGN - 1) / __ALIGN - 1;//STL����������д�Ĳ�����������������
		return ((bytes + __ALIGN - 1) >> 3) - 1;
	}

	static char * start_free;//�ڴ����ʼ��ַ
	static char * end_free;//�ڴ��ĩβ��ַ
	static size_t heap_size;//�Ѿ����ٵĶѴ�С
	/*
	ר�Ÿ�free list�ṩ�ڴ��"�ڴ��"
	����һ���ռ�(size * nobjs) size���û�������Ҫ�Ĵ�С(�������ǲ����û���Ҫ���ٸ����ٰ�������һ������ڴ���й���)
	���������ǰ�ڴ���еĿ����ڴ�û����ô��nobjs��ȡ���پ�ȡ����(�������ܲ���Ҫmalloc�����ڴ��˰�)
	*/
	static char *chunk_alloc(size_t size, int &nobjs)
	{
		char * result = NULL;
		size_t total_bytes = size * nobjs;
		size_t bytes_left = end_free - start_free;/*��ǰ���ӻ�ʣ�����ڴ�*/
		if (bytes_left >= total_bytes)/*�������ô�����*/
		{
			result = start_free;
			start_free += total_bytes;
			return result;
		}
		else if (bytes_left >= size) /*û����ô���Ҿ��˶�����Σ�ֻҪ�����뵽�ͺ�*/
		{
			nobjs = bytes_left / size;
			total_bytes = size*nobjs;
			result = start_free;
			start_free += total_bytes;
			return result;
		}
		else/*��������ڴ涼���벻������Ҫmalloc��*/
		{
			/*ÿ�����붼��ο���ǰheap�е��ڴ��С����Ҫ��Խ������Խ��*/
			size_t bytes_to_get = 2 * total_bytes + ROUND_UP(heap_size >> 4);
			/*��ǰ�����ʣ�����ڴ�͸�һ�����ʵ�free list��Ϊÿ��free����8�ı���������һ���к��ʵ�free list*/
			if (bytes_left > 0)
			{
				obj * volatile * my_free_list = free_list + FREELIST_INDEX(bytes_left);
				((obj*)start_free)->free_list_link = *my_free_list;
				*my_free_list = (obj*)start_free;
			}
			/*����heap�ռ䣬�����ڴ��*/
			start_free = (char*)malloc(bytes_to_get);
			if (NULL == start_free)
			{
				int i;
				obj * volatile * my_free_list,*p;
				/*mallocʧ�����ǻ�����������free list�����ڴ�*/
				for (i = size; i <= __MAX_BYTES; i += __ALIGN)
				{
					my_free_list = free_list + FREELIST_INDEX(i);
					p = *my_free_list;
					if (NULL != p)
					{
						/*���ĳ��free list�����ڴ����һ��chunk����ǰfree list*/
						*my_free_list = p->free_list_link;//ָ����һ��chunk
						start_free = (char *)p;
						end_free = start_free + i;
						/*�ҵ���һ���ڴ棬�ݹ����*/
						return chunk_alloc(size, nobjs);
					}
				}
				/*���free list��û���ڴ��ˣ��͵���һ����������out-of-memory�����ܷ񾡵����ͷŵ��ڴ�*/
				start_free = (char*)malloc_alloc::allocate(bytes_to_get);
			}
			heap_size += bytes_to_get;
			end_free = start_free + bytes_to_get;
			return chunk_alloc(size, nobjs);
		}
	}
	/*free list�е�chunk�����˵��������亯��*/
	static void *refill(size_t n) // 16
	{
		int nobjs = 20;//Ĭ��20��chunk
		char * chunk = chunk_alloc(n, nobjs);
		obj * result = NULL;
		obj * current_obj, *next_obj;
		int i;
		/*���ֻ������һ��chunk��ôֱ�ӷ���*/
		if (nobjs == 1)
			return chunk;
		/*�����˶������Ҫ�Ѻ����chunk������*/
		obj * volatile * my_free_list = free_list + FREELIST_INDEX(n);
		result = (obj*)chunk;
		*my_free_list = next_obj = (obj*)(chunk + n);
		for (i = 1;; ++i)
		{
			current_obj = next_obj;
			next_obj = (obj*)((char*)next_obj + n);
			if (i == nobjs - 1)
			{
				current_obj->free_list_link = NULL;
				break;
			}
			current_obj->free_list_link = next_obj;
		}
		return result;
	}
public:
	/*�ռ����ú���*/
	static void *allocate(size_t n)// n // 20
	{
		obj * volatile * my_free_list = NULL;
		obj * result = NULL;
		/*����128����һ��������*/
		if (n > (size_t)__MAX_BYTES)
		{
			return malloc_alloc::allocate(n);
		}
		/*Ѱַ16��free list������ʵ�һ��*/
		my_free_list = free_list + FREELIST_INDEX(n);
		result = *my_free_list;
		if (NULL == result)
		{
			/*��ǰfree listû��chunk��������free list*/
			void *r = refill(ROUND_UP(n));
			return r;
		}
		*my_free_list = result->free_list_link;//��ǰfree list�ĵ�һ��chunk��Ҫ�����ȥ������ָ����һ��chunk
		return result;
	}
	/*�ռ��ͷź���*/
	static void deallocate(void *p, size_t n)
	{
		obj * volatile * my_free_list = NULL;
		obj * q = (obj*)p;
		/*����128����һ���������ͷ�(��ʵ����ֱ��free��)*/
		if (n > (size_t)__MAX_BYTES)
		{
			malloc_alloc::deallocate(p, n);
			return;
		}
		/*�ҵ���Ӧ��free list�ѵ�ǰ�黹��chunk����ͷ�巨*/
		my_free_list = free_list + FREELIST_INDEX(n);
		q->free_list_link = *my_free_list;
		*my_free_list = q;
	}
	/*�����ڴ��С*/
	static void *reallocate(void *p, size_t old_sz, size_t new_sz)
	{
		void *  result;
		size_t copy_sz;

		if (old_sz > (size_t)__MAX_BYTES && new_sz > (size_t)__MAX_BYTES)
		{
			return(malloc_alloc::reallocate(p, old_sz, new_sz));
		}
		if (ROUND_UP(old_sz) == ROUNDP_UP(new_sz))
			return(p);
		result = allocate(new_sz);
		copy_sz = new_sz > old_sz ? old_sz : new_sz;
		memcpy(result, p, copy_sz);
		deallocate(p, old_sz);
		return(result);
	}

};
template<bool threads, int inst>
typename __default_malloc_template<threads, inst>::obj * volatile
	__default_malloc_template<threads, inst>::free_list[__NFREELISTS] = { NULL };

template<bool threads, int inst>
char * __default_malloc_template<threads, inst>::start_free = NULL;

template<bool threads, int inst>
char * __default_malloc_template<threads, inst>::end_free = NULL;

template<bool threads, int inst>
size_t __default_malloc_template<threads, inst>::heap_size = 0;

/*��������׼�ӿ�*/
#ifdef __USE_MALLOC
	typedef __malloc_alloc_template<0> malloc_alloc;
	typedef malloc_alloc alloc;
#else
	typedef __default_malloc_template<0, 0> alloc;//Ĭ��ʹ�ö���������
#endif

template<class T, class Alloc>
class simple_alloc
{
public:
	static T * allocate(size_t n)	 // new []
	{
		return n == 0 ? NULL : (T*)Alloc::allocate(n * sizeof(T));
	}
	static T * allocate()			// new
	{
		return (T*)Alloc::allocate(sizeof(T)); 
	}
	static void deallocate(void *p, size_t n)//delete[]
	{
		if (n == 0) return;
		Alloc::deallocate(p, n*sizeof(T));	
	}
	static void deallocate(void *p)			//delete
	{
		Alloc::deallocate(p, sizeof(T));
	}
};

};

#endif