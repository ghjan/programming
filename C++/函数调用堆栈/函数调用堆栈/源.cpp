#include<iostream>
using namespace std;

void _cdecl test1();
void _stdcall test2();

typedef struct dong{
	int a;
	int b;
	int c;
}Dong;

Dong testRetn()
{
	Dong d;
	d.a = 1;
	d.b = 2;
	d.c = 3;
	return d;
}

int main()
{
	cout << sizeof(Dong) << endl;//ռ12���ֽ�

	Dong d = testRetn();
	
	system("pause");
}

void main1()
{
	cout << typeid(test1).name() << endl;
	cout << typeid(test2).name() << endl;

	system("pause");
}
/*
int main()
{
001D8DB5  lea         eax,[d]  			// ��d�ĵ�ַ����lea
001D8DB8  push        eax  			// ��d�ĵ�ַ��ջ    С��8�ֽ����ﲻ����ջ
001D8DB9  call        testRetn (01D14CEh)  	//
00E29357  add         esp,4
00E2935A  mov         ecx,dword ptr [eax]  	// ��d�ĵ�ַȡ���� �ŵ�ecx  ��ʵ����d�ĵ�ַ�ϴ�ľ���1
00E2935C  mov         dword ptr [ebp-0E4h],ecx  // �� 1 ��ֵ�� ebp-0E4h
00E29362  mov         edx,dword ptr [eax+4]  	//
00E29365  mov         dword ptr [ebp-0E0h],edx  // �� 2 ��ֵ�� ebp-0E0h
00E2936B  mov         eax,dword ptr [eax+8]
00E2936E  mov         dword ptr [ebp-0DCh],eax  // �� 3 ��ֵ�� ebp-0E0h

00E29374  mov         ecx,dword ptr [ebp-0E4h]  // �� ebp-0E4h��ֵ �ŵ� ecx �Ĵ����� ֵ����1
00E2937A  mov         dword ptr [dd],ecx  	// ͨ��ecx�ٷŵ�dd���׵�ַ��

00E2937D  mov         edx,dword ptr [ebp-0E0h]	//ͬ��
00E29383  mov         dword ptr [ebp-0Ch],edx

00E29386  mov         eax,dword ptr [ebp-0DCh]  //ͬ��
00E2938C  mov         dword ptr [ebp-8],eax

}

Dong testRetn()
{
001D5190  push        ebp  			// ������һ��������ջ��
001D5191  mov         ebp,esp  			// ������ǰջ��λ��
001D5193  sub         esp,0D8h  		// �����ռ�
001D5199  push        ebx
001D519A  push        esi
001D519B  push        edi  			// ������� ��ջ
001D519C  lea         edi,[ebp-0D8h]  		// edi �з� �����ռ�����λ��
001D51A2  mov         ecx,36h  			// ���� rep ѭ������ 54 ��
001D51A7  mov         eax,0CCCCCCCCh  		// ��ʼ���ڴ�
001D51AC  rep stos    dword ptr es:[edi]  	// ѭ����ʼ����D8 = 216 = 40 * 54 = 216
Dong d;
d.a = 1;
00F75DEE  mov         dword ptr [ebp-10h],1
d.b = 2;
00F75DF5  mov         dword ptr [ebp-0Ch],2
d.c = 3;
00F75DFC  mov         dword ptr [ebp-8],3
return d;
00F75E03  mov         eax,dword ptr [ebp+8]   	 // ȡ��main������d�ĵ�ַ �ŵ�eax�Ĵ�����
00F75E06  mov         ecx,dword ptr [ebp-10h]
00F75E09  mov         dword ptr [eax],ecx  	 // �� 1 �ŵ�  d �׵�ַ��
00F75E0B  mov         edx,dword ptr [ebp-0Ch]
00F75E0E  mov         dword ptr [eax+4],edx  	 // �� 2 �ŵ�  d+4 ��ַ��
00F75E11  mov         ecx,dword ptr [ebp-8]
00F75E14  mov         dword ptr [eax+8],ecx  	 // �� 3 �ŵ�  d+8 ��ַ��
00F75E17  mov         eax,dword ptr [ebp+8] 	 // ��eax�л���d�ĵ�ַ�׵�ַ
}
00F75E1A  push        edx
00F75E1B  mov         ecx,ebp
00F75E1D  push        eax
}
00F75E1E  lea         edx,ds:[00F75E34h]
00F75E24  call        00F7113B
00F75E29  pop         eax
00F75E2A  pop         edx
00F75E2B  pop         edi
00F75E2C  pop         esi
00F75E2D  pop         ebx
00F75E2E  mov         esp,ebp
00F75E30  pop         ebp
00F75E31  ret
*/