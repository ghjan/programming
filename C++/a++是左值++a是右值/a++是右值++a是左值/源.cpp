#include<iostream>
using namespace std;

int main()
{
	int a = 1;
	//00C93ABE  mov         dword ptr [a],1 
	int b = ++a + 10;
	/*
	00C93AC5  mov         eax,dword ptr [a]		
	00C93AC8  add         eax,1  
	00C93ACB  mov         dword ptr [a],eax		���ϸ� a + 1 Ȼ���ڽ�������
	00C93ACE  mov         ecx,dword ptr [a]  
	00C93AD1  add         ecx,0Ah  
	00C93AD4  mov         dword ptr [b],ecx */
	int c = a++ + 10;
	/*
	00C93AD7  mov         eax,dword ptr [a]		�� a �ŵ� eax�Ĵ�����  ռʱ�� eax �е�ֵ����a
	00C93ADA  add         eax,0Ah
	00C93ADD  mov         dword ptr [c],eax
	00C93AE0  mov         ecx,dword ptr [a]
	00C93AE3  add         ecx,1
	00C93AE6  mov         dword ptr [a],ecx		���Ÿ� a + 1
	*/

	//��������������Ǿ����ܽ����
	// a++ = 10 //�����Ǵ���ģ���Ϊa++����ֵ �� a �ŵ���eax �У�eax�д����һ����������һ����ֵ
	a++ + 10;	//�����ǿ��Եġ�eax û����Ϊ��ֵ��ֻ��������� 1 ��
	cout << a << endl;

	system("pause");
}