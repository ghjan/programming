#include <iostream>
using namespace std;

class A{
public:
	int value;
	static int num;
	int max;
	char ch[10];
	int min;
	A(int x = 0) :value(x), max(x + 10), min(x + 20){}
	void fun(){ cout << "Afun" << endl; }
};
int A::num = 0;

int main1()
{
	int *p = NULL;			//0x00000000
	int A:: *s = NULL;		//0xffffffff    Ϊʲô��������أ� �£�ת�����з������ξ��� -1 ����s��û��ָ��A������������A���ͣ�������-1
	int *z;
	p = &A::num;			//0x013df320 ��.data �� ������е�ַ
	s = &A::value;			//0x00000000	��value����ʼ��ַ�� ��ʱ��ʹ���A���͵�0��ַ��
	
	cout << s << endl;//ֱ�Ӵ�ӡ��ӡ��������s�ϴ�ĵ�ַ������Ϊ��ָ�������Ե�ַ����û��Ϊ�������ַ
	cout << (int )*(int **)&s << endl;//��һ�����ľ��ǰ�s�ϴ�ĵ�ַ���һ��int���ͣ���Ҫ��sȡ��ַ
	s = &A::max;			//0x00000004	��max����ʼ��ַ��	��ʱ��ʹ���A���͵�4��ַ��
	cout << (int)*(int **)&s << endl;
	s = &A::min;			//0x00000014	��min����ʼ���ʴ�	��ʱ��value(4) + max(4) + ch(12) = 20 = 0x14
	cout << (int)*(int **)&s << endl;

	p += 1;
	//s += 1;			//�����������������int A::* ������    �Ҳ£� ������������֪�� int A::*Ҫ�������ֽڣ����Գ���
	//void(A:: *ptr)() = &A::fun;	//��gcc���ǲ������
	system("pause");
	return 0;
}