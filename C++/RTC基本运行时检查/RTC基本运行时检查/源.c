
//#include <stdio.h>
//void fun1()
//{
//	int a = 48;
//}
//void fun2()
//{
//	int b;
//	printf("%d", b);
//}

//#pragma runtime_checks( "scu", off )
//#pragma runtime_checks( "cu", off )
void func(void)
{
	int data[0x10];
	//data[0x10] = 0;					// 1 * 16 * 4 = 64;
	//data[0x11] = 0;
	data[0x10] = 0xcccccccc;
}
//������δ�����vs2013���벻����ֻҪ����δ��ʼ����ֵ��ֱ�Ӿ���error  ��ǰ��waring
#pragma runtime_checks( "s", off )
void func2()
{
	int data1, data2;
	data1 = data2;
}
int main()
{
	func2();

	getchar();
}
/*
#pragma runtime_checks( "scu", off )
void func(void)
{
011C1260  push        ebp
011C1261  mov         ebp,esp
011C1263  sub         esp,80h		// 80h
011C1269  push        ebx
011C126A  push        esi
011C126B  push        edi
int data[0x10];
}

#pragma runtime_checks( "cu", off )
void func(void)
{
012013C0  push        ebp
012013C1  mov         ebp,esp
012013C3  sub         esp,108h					// 108h = 264
012013C9  push        ebx
012013CA  push        esi
012013CB  push        edi
012013CC  lea         edi,[ebp-108h]			
012013D2  mov         ecx,42h					// 4 * 16 + 2 = 68  ���� 68 ��
012013D7  mov         eax,0CCCCCCCCh			// eax��4byte  ���� 68 * 4 = 272  ����ֻ��Ҫ264byte�ռ䣬���ǿ�����272�ռ䣬����8byte
012013DC  rep stos    dword ptr es:[edi]
int data[0x10];
}
012013DE  push        edx
012013DF  mov         ecx,ebp
012013E1  push        eax
012013E2  lea         edx,ds:[12013F8h]
012013E8  call        @_RTC_CheckStackVars@8 (01201087h)	//RTC_CheckStackVars�ĵ���
012013ED  pop         eax
012013EE  pop         edx
012013EF  pop         edi
012013F0  pop         esi
012013F1  pop         ebx
012013F2  mov         esp,ebp
012013F4  pop         ebp
int data[0x10];
}
*/
/*
vs2008�ṩ��һ����/RTC��ѡ����Կ��Ʊ������Ƿ��������ʱ��飬���ѡ����C/C++ => �������� => ��������ʱ��� �п��Խ���ѡ�񣬸������˵��������msdn���ҵ������Ǹ�����Ȥ���������ʵ��������ܵġ�
����дһ���򵥵�C���룺
#pragma runtime_checks( "scu", off )
void func(void)
{
int data[0x10];
}
����Ĵ��������#pragma��vs������ʱ���ȫ���رա���Ϊ�������ʱ����ջ��أ��������Ǽ���ջ�϶�����һ�����������������ɵĻ����룺
#pragma runtime_checks( "scu", off )
void func(void)
{
00401020 55               push        ebp
00401021 8B EC            mov         ebp,esp
00401023 83 EC 40         sub         esp,40h
int data[0x10];
}
00401026 8B E5            mov         esp,ebp
00401028 5D               pop         ebp
00401029 C3               ret
�������ǵ��ڴ������򵥵ؽ�ESPָ�����¼���40h���ֽڣ���Ҳ�����Ƕ����data����Ĵ�С��
1.1    ��ջ֡���

�������Ǵ򿪶�ջ֡�ļ�飬�ٿ����Ĵ��룺
#pragma runtime_checks( "cu", off )
void func(void)
{
00401020 55               push        ebp
00401021 8B EC            mov         ebp,esp
00401023 83 EC 48         sub         esp,48h
00401026 57               push        edi
00401027 8D 7D B8         lea         edi,[ebp-48h]
0040102A B9 12 00 00 00   mov         ecx,12h
0040102F B8 CC CC CC CC   mov         eax,0CCCCCCCCh
00401034 F3 AB            rep stos    dword ptr es:[edi]
int data[0x10];
}
00401036 52               push        edx
00401037 8B CD            mov         ecx,ebp
00401039 50               push        eax
0040103A 8D 15 4C 10 40 00 lea         edx,[ (40104Ch)]
00401040 E8 8B 00 00 00   call        _RTC_CheckStackVars (4010D0h)
00401045 58               pop         eax
00401046 5A               pop         edx
00401047 5F               pop         edi
00401048 8B E5            mov         esp,ebp
0040104A 5D               pop         ebp
0040104B C3               ret
���Կ��������ʱ��ջ�Ĵ�С�Ӵ���48h����������Ҫ�Ķ���8���ֽڣ������������ջ�ռ�ȫ����0xcc������䡣�ں�������󻹶���һ����RTC_CheckStackVars�ĵ��á�
������Խ��ʱ��������func�����������²�����
data[0x10] = 0;
���˳�������ʱ��VS������һ��assert�Ի��򣬸�����data��������������ˡ���������˼���ǣ����ʹ������ĸ�ֵ��䣬VSȴ���ᱨ��
data[0x11] = 0;
ͬ����Խ�磬���ֲ�ͬ�Ľ�����ɴ˿ɼ���VSӦ�û�Ϊ��������һ��Ԫ�صĿռ䣬��ֻ�����������һ��Ԫ�ؿռ��Ƿ�Ϊ0xcc��
�����������������������һ��Ԫ�ص�ֵ��
data[0x10] = 0xcccccccc;
ͬ����VSҲ���ᱨ��
ԭ���������أ�VSҲ������ʵ����һ���ǳ��򵥵ļ�飬�������ÿ��Լ���
1.2    δ��ʼ���ı������

������δ��ʼ���ı�����飬д�δ��룺
#pragma runtime_checks( "s", off )
void func(void)
{
00401020 55               push        ebp
00401021 8B EC            mov         ebp,esp
00401023 83 EC 0C         sub         esp,0Ch
00401026 C6 45 F7 00      mov         byte ptr [ebp-9],0
int data1, data2;
data1 = data2;
0040102A 80 7D F7 00      cmp         byte ptr [ebp-9],0
0040102E 75 0D            jne         func+1Dh (40103Dh)
00401030 68 47 10 40 00   push        offset  (401047h)
00401035 E8 C6 06 00 00   call        _RTC_UninitUse (401700h)
0040103A 83 C4 04         add         esp,4
0040103D 8B 45 F8         mov         eax,dword ptr [data2]
00401040 89 45 FC         mov         dword ptr [data1],eax
}
���Կ������������ڸ�ֵ���ĺ��������һ��εĻ����룬��Ϊ�ڱ����ʱ�����и�ֵ�����һ�����棺
f:/projects/test/cpptest/cpptest.cpp(15) : warning C4700: ʹ����δ��ʼ���ľֲ�������data2��
���������������о���ĵط��Ż������Ĵ��룬��data2��һ����ֵ��
#pragma runtime_checks( "s", off )
void func(void)
{
00401020 55               push        ebp
00401021 8B EC            mov         ebp,esp
00401023 83 EC 08         sub         esp,8
int data1, data2 = 0;
00401026 C7 45 F8 00 00 00 00 mov         dword ptr [data2],0
data1 = data2;
0040102D 8B 45 F8         mov         eax,dword ptr [data2]
00401030 89 45 FC         mov         dword ptr [data1],eax
}
��Ȼ���ٲ�����صĴ��롣
����data2���Ǿֲ���������ȫ�ֱ��������������ģ�
int data2;
#pragma runtime_checks( "s", off )
void func(void)
{
00401020 55               push        ebp
00401021 8B EC            mov         ebp,esp
00401023 51               push        ecx
int data1;
data1 = data2;
00401024 A1 8C 71 40 00   mov         eax,dword ptr [data2 (40718Ch)]
00401029 89 45 FC         mov         dword ptr [data1],eax
}
���ʱ��VSͬ�������������롣
*/