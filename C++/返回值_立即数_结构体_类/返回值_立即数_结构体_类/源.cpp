#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <typeinfo>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////
int test()
{
	static int a = 10;
	return a;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct dong
{
	int data;
}Dong;
Dong test2()
{
	static Dong d = { 10 };
	return d;/*						00FC51E5  mov         eax,dword ptr [d]  Ҳ��ͨ��eax�Ĵ����ѷ���ֵ����ȥ
			 �������ϵ�static    001C51DE  mov         eax,dword ptr ds:[001CF00Ch]  ��һ�� eax�Ĵ�������ȥ*/
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
class A				/*û���Զ��幹�캯�����࣬���൱�ڽṹ�壬�����Զ�������*/
{
public:

	int data;
};
A test3()
{
	static A a;
	return a;/*0102524E  mov         eax,dword ptr ds:[0102F358h] */
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
class B
{
public:
	int data;
	B(){}		//�Զ���һ���չ��캯�� ��ϵͳĬ�ϵĹ��캯��һ��  ����ĽṹҲ�Ǵ�һ��
};
B test4()
{
	static B b;
	return b;
}
int main()
{
	//int &a = test();		//ʹ��eax�Ĵ�����������ֵ����һ����������զ���ܱ�����

	Dong &d = test2();		//���Ϊʲô������
	/*
	00995398  call        test2 (09911CCh)
	0099539D  mov         dword ptr [ebp-0E4h],eax		��return ֮�������һ����ʱ�� �� eaxֵ�������ʱ��
	009953A3  mov         eax,dword ptr [ebp-0E4h]
	009953A9  mov         dword ptr [ebp-18h],eax
	009953AC  lea         ecx,[ebp-18h]
	009953AF  mov         dword ptr [d],ecx
	*/

	A &a = test3();
	/*
	01027F42  call        test3 (0102142Eh)
	01027F47  mov         dword ptr [ebp-0FCh],eax		��return ֮�������һ����ʱ�� �� eaxֵ�������ʱ��
	01027F4D  mov         eax,dword ptr [ebp-0FCh]
	01027F53  mov         dword ptr [ebp-30h],eax
	01027F56  lea         ecx,[ebp-30h]
	01027F59  mov         dword ptr [a],ecx
	*/

	B &b = test4();
	/*
	00267F8C  lea         eax,[ebp-48h]
	00267F8F  push        eax
	00267F90  call        test4 (0261438h)		�ڽ��뺯��֮ǰ�����ѽ�������һ����ʱ����������ʱ��ѹջ����Ϊ�������ݸ�����
	00267F95  add         esp,4
	00267F98  lea         ecx,[ebp-48h]
	00267F9B  mov         dword ptr [b],ecx
	*/


	getchar();
}