#include <iostream>
#include <stack>
#include <assert.h>
using namespace std;

//Ҫ��ÿ�ε��� pop() push() min() ������ʱ�临�Ӷȶ���O(1)   min()ÿ�ζ��������ջ�е���СԪ�� 

template<class T>
class StackWithMin
{
public:
	void push(T value);
	void pop();
	T min() const;
public:
	int minData;
	stack<T> m_data;
	stack<T> m_min; 			//����ջ��������������ֵ 
};

template<class T>
void StackWithMin<T>::push(T value)
{
	m_data.push(value);
	if (m_min.empty() || minData > value)
	{
		minData = value;
		m_min.push(value);
		return;
	}
	m_min.push(minData);
}

template<class T>
void StackWithMin<T>::pop()
{
	m_data.pop();
	m_min.pop();
}

template<class T>
T StackWithMin<T>::min() const
{
	//assert(m_min.size() > 0);  //���Ե�ʱ�����д�� 
	return m_min.top();
}

int main()
{
	StackWithMin<int> s;
	s.push(3);
	cout << s.min() << endl;
	s.push(4);
	cout << s.min() << endl;
	s.push(2);
	cout << s.min() << endl;
	s.push(6);
	cout << s.min() << endl;
	s.push(1);
	cout << s.min() << endl;
	cout << "-------------ɾ��-----------------" << endl;
	s.pop();
	cout << s.min() << endl;
	s.pop();
	cout << s.min() << endl;
	s.pop();
	cout << s.min() << endl;
	s.pop();
	cout << s.min() << endl;
	s.pop();
	cout << s.min() << endl;
}
