#include <iostream> 
using namespace std;

class A
{
	int age;
public:
	A(int a = 0) :age(a)
	{
		cout << "gou zhao" << endl;
	}
	A(const A &a)
	{
		cout << "��������" << endl;
	}
	void operator=(const A &a)
	{
		cout << "operator = " << endl;
		age = a.age;
	}
	~A()
	{
		cout << "����" << endl;
	}
	int get()
	{
		return age;
	}
};


A test(A a)
{
	A aa(a.get());
	return aa;
}
A& test2(A a)
{
	A aa(a.get());
	return aa;
}
void dong()
{
	A a(10);
	A a2;
	a2 = test(a);
	cout << "----" << endl;
	A a3;
	a3 = test2(a);
	cout << "---------------------" << endl;
	/*
	gou zhao
	gou zhao
	��������		�βο�������
	gou zhao		
	��������		��aa������main��������ʱ����ȥ��Ҳ���ǳ�ʼ����ʱ����
	����		�ֲ���������
	����		�β�����
	operator =
	����			��ʱ������  ��ʱ����������a2 = test(a);���֮���������
	----			
	gou zhao
	��������
	gou zhao
	����
	����			//���ڷ���ֵ������Ҫ�������������ص������ã����Բ���������ʱ���󣬿����淴���
	operator =
	---------------------
	����
	����
	����
	*/
}
/*�Ժ�Ҫ����һ�����������������д����Ч*/
A test3(A &a)
{
	int value = a.get();
	return A(value);		//��ֱ����ʱ�����й��죬������� 1�����˴���һ���¶����ʱ��  2������һ������ copy ����һ�������ʱ��
}
void dong2()
{
	A a(10);
	A a2;
	a2 = test3(a);
	/*
	gou zhao
	gou zhao
	gou zhao		��ʱ������
	operator =
	����			��ʱ������
	����
	����
	*/
}
void dong3()
{
	A a(10);
	A a2 = test3(a);//����д���������ʱ������Ϊ��ֱ����copy��a2�ڴ��ϣ�ֱ�ӳ�ʼ����dong2�Ǹ��и�ֵ
	/*
	gou zhao
	gou zhao
	����
	����
	*/
}
int main2()
{
	//dong();
	//dong2();
	dong3();

	getchar();
	return 0;
}

/*
a2 = test(a);
010C633F  lea         eax,[a]
010C6342  push        eax
010C6343  lea         ecx,[ebp-14Ch]-------------------��������ʱ���� ���ڴ�
010C6349  push        ecx------------------------------����ʱ������ڴ洫��ȥ
010C634A  call        test (010C1212h)
010C634F  add         esp,8
010C6352  mov         dword ptr [ebp-154h],eax
010C6358  mov         edx,dword ptr [ebp-154h]
010C635E  mov         dword ptr [ebp-158h],edx
010C6364  mov         byte ptr [ebp-4],2
010C6368  mov         eax,dword ptr [ebp-158h]
010C636E  push        eax
010C636F  lea         ecx,[a2]
010C6372  call        A::operator= (010C11B3h)
010C6377  mov         byte ptr [ebp-4],1
010C637B  lea         ecx,[ebp-14Ch]
010C6381  call        A::~A (010C128Fh)-------------------->��main������������
a3 = test2(a);
010C63BD  lea         eax,[a]
010C63C0  push        eax------------------------Ȼ���⣬ɶҲû��
010C63C1  call        test2 (010C1235h)
010C63C6  add         esp,4
010C63C9  push        eax
010C63CA  lea         ecx,[a3]
010C63CD  call        A::operator= (010C11B3h)
*/