#include <iostream>
using namespace std;
/*
������������������ˣ���Ӧ���������������¶������еĻ���汾��
�������������ֻ���¶���һ���汾�������汾���ᱻ���أ�����������޷�ʹ�����ǡ�
*/
class A{
public:
	void test()
	{
		cout << "Atest" << endl;
	}
};

class B : public A{
public:
	void test(int i)			//�����˸����test�������������test���������ͱ������� 
	{
		cout << "Btest" << i << endl;
	}
};

class C{
public:
	void test(int i){
		cout << "Ctest1" << i << endl;
	}
	void test(){
		cout << "Ctest1" << endl;
	}
};
class D : public C{
public:
	void test(int i){					//ֻҪ���㲻�����ظ���ĺ�����ֻ���ض����˸���ĺ���Ҳ�����ظ���ļ������غ���
		//test();//����D��û��test
		C::test();//����
		cout << "Dtest1" << i << endl;
	}
};
int main()
{
	//B().test();				//��������ΪB�и���û��test���޲κ��� 
	B().A::test();				//�������ǿ���ָ�����ø���ķ��� 
	D().test(100);

	system("pause");
}