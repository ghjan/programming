#include <iostream>
using namespace std;
//__cdecl �� C Declaration ����д����ʾ C �� C++ Ĭ�ϵĺ�������Լ������C/C++��MFCX��Ĭ�ϵ���Լ����
int _cdecl mul(int a, int b)	//c����Լ��
{
	return a*b;
}
//_stdcall��Standard Call����д����C++�ı�׼���÷�ʽ, ��Ȼ����΢����ı�׼��__stdcallͨ������Win32 API��(�ɲ鿴WINAPI�Ķ���)��
int _stdcall aaa(int a, int b)	//windows��׼�ĵ���Լ��
{
	return a + b;
}
//_fastcall���õ���Ҫ�ص���ǿ죬��Ϊ����ͨ���Ĵ��������Ͳ����ġ�
//��ע��ͨ���Ĵ������͵����������Ǵ������ҵ�
int _fastcall bbb(int a, int b)	//���ٵ���Լ��
{
	return a + b;
}

int main()
{
	int a = 1;
	int b = 2;
	int c;
	cout << sizeof(int *) << endl;
	c = bbb(a, b);

	system("pause");
	return 0;
}
//
//�ܽ�
//
//������Ҫ�ܽ�һ��_cdecl��_stdcall��__fastcall����֮�������
//
//Ҫ��				__cdecl				__stdcall				__fastcall
//�������ݷ�ʽ		��->��				��->��					��߿�ʼ������������4�ֽڣ�DWORD���Ĳ����ֱ����ECX��EDX�Ĵ���������Ĳ�����������ѹջ����
//����ջ��			����������			�����ú�������			�����ú�������
//���ó���		C/C++��MFC��Ĭ�Ϸ�ʽ; �ɱ������ʱ��ʹ��;		Win API	Ҫ���ٶȿ�
//C��������Լ��		_functionname		_functionname@number	@functionname@number