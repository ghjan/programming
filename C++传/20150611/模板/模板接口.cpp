#include<iostream>
using namespace std;

void show(int num)
{
	cout << num << endl;
}

//���ͽӿڣ��κ��������ͣ������κκ���ָ�붼����
template<class T,class F>
void run(T t, F f)
{
	f(t);
}

template<class T>
void show2(T t)
{
	cout << t << endl;
}
void main()
{
	//run(520, show);
	run(520, show2<int>);
	run("love", show2<const char *>);

	cin.get();
}