#include<iostream>
using namespace std;

typedef struct dong
{
	int a[4];
}Dong;
typedef struct dong2
{
	int b;
}Dong2;
typedef struct dong3
{
	int a;
	int b;
}Dong3;
class Dong4
{
public:
	int a;
};
class Dong5
{
public:
	int a;
	int b;
};
class Dong6
{
public:
	int age;
	Dong6(){}
};
class Dong7
{
public:
	int a[4];
};
class Dong8
{
public:
	int a[4];
	Dong8(){}
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////
Dong test()
{
	Dong d;
	d.a[0] = 1;
	return d;
}
Dong2 test2()
{
	Dong2 d2;
	d2.b = 6;//00F851CE  mov         dword ptr [d2],6
	return d2;//000A51D5  mov         eax,dword ptr [d2]    ����ֵʹ��eax��������
}
Dong3 test3()
{
	Dong3 d3;
	d3.a = 2;//00B93ACE  mov         dword ptr [d3],2 
	d3.b = 6;//00B93AD5  mov         dword ptr [ebp-8],6 
	return d3;
	/*
	00B93ADC  mov         eax,dword ptr [d3]
	00B93ADF  mov         edx,dword ptr [ebp-8]		���� eax �� edx �ѷ���ֵ����ȥ
	*/
}
Dong4 test4()
{
	Dong4 d4;
	d4.a = 10;
	return d4;//00B75235  mov         eax,dword ptr [d4]  ͬ��
}
Dong5 test5()
{
	Dong5 d5;
	d5.a = 10;
	d5.b = 20;
	return d5;
	/*
	011A533C  mov         eax,dword ptr [d5]
	011A533F  mov         edx,dword ptr [ebp-8]			ͬ��
	*/
}
Dong6 test6()
{
	Dong6 d6;
	d6.age = 20;
	return d6;
}
Dong7 test7()
{
	Dong7 d7;
	d7.a[0] = 1;
	return d7;
}
Dong8 test8()
{
	Dong8 d8;
	d8.a[0] = 5;
	return d8;
}
void main2()
{
	Dong d = test();
	/*
	011F7F6E  lea         eax,[ebp-104h]
	011F7F74  push        eax				�β���ջ
	011F7F75  call        test (011F13A7h)	�ڵ���֮ǰ����main�п������ڴ棬��������ʱ���󣬲�����ʱ����ĵ�ַ����test()������
	*/
	Dong2 d2 = test2();
	/*
	013A7FC4  call        test2 (013A1429h)			�ڵ���֮ǰû��ѹջ��Ҳ����û�в�������
	*/
	Dong3 d3 = test3();
	/*
	00FA8038  call        test3 (0FA142Eh)			ͬ��
	*/
	Dong4 d4 = test4();
	/*
	00D680BB  call        test4 (0D61433h)			ͬ��
	013D612A  mov         dword ptr [ebp-138h],eax
	013D6130  mov         eax,dword ptr [ebp-138h]
	013D6136  mov         dword ptr [d4],eax
	��d6���������ڣ�Ĭ�Ϲ��캯�����԰�ֵ���������и�ֵ���Զ��幹�캯����������֪����������ʲô�����Բ���������
	*/
	Dong5 d5 = test5();
	/*
	011A812F  call        test5 (011A1438h)			ͬ��
	*/
	Dong6 d6 = test6();
	/*
	010C615C  lea         eax,[d6]
	010C615F  push        eax						�һ���Ϊ��������ʱ���󣬽����ϸһ�����ԣ���ֻ�ǰ�ָ��d6�ڴ�ָ���ѹջ�ˣ�����ȥ�ˣ�Ŀ�ģ���Լ�ڴ棬ֱ���ں����н��й���
	010C6160  call        test6 (010C101Eh)		    �൱�� Dong6 d6 = d6  �ȼ���  Dong6 d6(d6)
	��d4���������ڣ�d6���Զ���Ĺ��캯������Ҫ�����Լ��Ĺ��캯��
	*/
	Dong7 d7 = test7();
	/*
	00A16418  lea         eax,[ebp-14Ch]			���ֺ�d6��������ô��������  ���ﴴ������ʱ����
	00A1641E  push        eax
	00A1641F  call        test7 (0A114D3h)
	*/ 
	Dong8 d8 = test8();
	/*
	00CB649E  lea         eax,[d8]
	00CB64A4  push        eax
	00CB64A5  call        test8 (0CB14DDh)			��d6һģһ��
	*/
	/*
	������Ϳ����ܽ��ˣ���û���Զ��幹�캯����ʱ�򣬺�������һ�������ڴ����8�Ļ�����Ҫ�ڵ��ú����д�����ʱ����
	��������Զ��幹�캯������ôֱ�Ӱ�d8��������ַ����ȥ���ں�������ֱ�Ӿͳ�ʼ���ˣ���������Ҫ��������Ҳ�Ͳ�������ʱ��
	��Ϊʲôû���Զ��幹�죬�ڴ����8�������ʱ����
	�ﶨ���˹��캯�������Բ��������ʱ����
	*/

	/*----------------�����Գ�ʼ������--------------------------------�����Ǹ�ֵ����----------------*/

	Dong4 d41;								//û���Զ��幹�캯��
	d41 = test4();
	/*
	00D85BFD  call        test5 (0D81320h) 
	*/
	Dong7 d71;								// ��d41�ȣ��ڴ����8 �ֽ���
	d71 = test7();
	/*
	00AE9BE4  lea         eax,[ebp-1B8h]
	00AE9BEA  push        eax
	00AE9BEB  call        test7 (0AE14C4h)
	*/
	Dong6 d61;								// ��d41�ȣ����Զ��幹�캯��
	d61 = test6();
	/*
	00D75C08  lea         eax,[ebp-17Ch]
	00D75C0E  push        eax
	00D75C0F  call        test6 (0D7101Eh)
	*/
	Dong8 d81;								//��d61�ȣ��ڴ����8�ֽ�
	d81 = test8();
	/*
	01265C08  lea         eax,[ebp-1E4h]  
	01265C0E  push        eax  
	01265C0F  call        test8 (012612D5h)  
	*/
	/*
	���ܽ᣺��ֵ���㣬ֻҪ���Զ��幹�죬�ͻ������ʱ����û���Զ��幹�죬����8�ֽڲŻ������ʱ����

	���Զ��幹�캯������û���Զ��幹�캯��������
	���Զ��幹�캯������Ҫ�����������ĵ�ַ��Ҳ����thisָ�룬���û���Զ��幹�캯����Ҳ�Ͳ���Ҫ��thisָ�룬Ҳ�Ͳ���Ҫ�������ĵ�ַ
	*/
	getchar();
}
/*
���յ��ܽ᣺��ʼ������------���������������ʱ����ֻ��"û�й��캯��"��"�ڴ����8�ֽ�"�š��ᡱ������ʱ��
			��ֵ����--------�������������ʱ����  ֻ��"û�й��캯��"�ҡ��ڴ�С��8�ֽڡ��š����ᡱ������ʱ��
*/