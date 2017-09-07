#include <memory>
#include <vector>
/*����ָ���������һ��vector������Ҫcopy��ʱ��Ĭ�϶���ǳ��������ֻ������ָ�������++  ��vector����copyһ��*/
template<typename T>
class MyVector
{
private:
	typedef typename std::vector<T>::size_type size_type;
	std::shared_ptr<std::vector<T>> data;
	
public:
	MyVector() :data(make_shared<vector<T>>()){}

	/*�����������ʵ��û����ϵ��ֻ��Ϊ�˹�����ȫһ��*/
	void check(size_type size, const char *msg)const//���data[i]���Ϸ��׳��쳣
	{
		if (size >= data->size())
			throw out_of_range(msg);
	}
	bool empty() const{ return data->empty(); }
	void push_back(const T &t)
	{ 
		data->push_back(t);
	}
	void pop_back()
	{
		check(0, "pop on empty");
		data->pop_back();
	}
	T &front()
	{
		check(0, "front on empty");
		return data->front();
	}
	T &back()
	{
		check(0, "back on empty");
		return data->back();	
	}
};
