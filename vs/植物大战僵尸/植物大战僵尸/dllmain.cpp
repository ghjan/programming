// dllmain.cpp : ���� DLL Ӧ�ó������ڵ㡣
#include "stdafx.h"
#include <thread>

//��ַ�ϴ����b����ĵ�ַ��b����ĵ�ַ ����868����a����ĵ�ַ
//	 b			a		   sum
//	 &b   868   &a	5578   &sum
//	��ַ

//int base = 0x007794f8;
int *get2Point(int base, int p1, int p2)
{
	//BOOL IsBadReadPtr(CONST VOID *lp,UINT_PTR ucb); ����:�������Ƿ���Ȩ�޷���ָ�����ڴ��  ������ý�����Ȩ�޷��ʸ��ڴ棬����0 
	int P1, P2;
	if (IsBadReadPtr((LPVOID)base, 4))//������Ҫ�жϣ���Ƭ�ڴ�ɲ��ɶ�����Ϊһ�������Ժ��ڴ���
	{
		return NULL;
	}
	P1 = *(int*)base;//�����b������ b�ĵ�ַ	Ϊ�˲������ұ�ȡ��ַ���ˣ�̫�����ˣ������������õ�ֻ�����ǵĵ�ַ������Ҫ����
	if (IsBadReadPtr((LPVOID)(P1 + p1), 4))
	{
		return NULL;
	}
	P2 = *(int *)(P1 + p1);// aҲһ��
	if (IsBadReadPtr((LPVOID)(P2 + p2), 4))
	{
		return NULL;
	}
	int *res = (int *)(P2 + p2);//res û�г�������ֻ��Ҫ���һ��Ķ������޸�����ֵ
	if (IsBadWritePtr((LPVOID)res, 4))//����Ҫ�����ĵ�ַ����Ҫ����Ƿ��д
	{
		return NULL;
	}
	return res;
}
int *get3Point(int base, int p1, int p2,int p3)
{
	int P1, P2, P3;
	if (IsBadReadPtr((LPVOID)base, 4))
	{
		return NULL;
	}
	P1 = *(int*)base;
	if (IsBadReadPtr((LPVOID)(P1 + p1), 4))
	{
		return NULL;
	}
	P2 = *(int *)(P1 + p1);
	if (IsBadReadPtr((LPVOID)(P2 + p2), 4))
	{
		return NULL;
	}
	P3 = *(int *)(P2 + p2);
	if (IsBadReadPtr((LPVOID)(P3 + p3), 4))
	{
		return NULL;
	}
	int *res = (int *)(P3 + p3);
	if (IsBadWritePtr((LPVOID)res, 4))//����Ҫ�����ĵ�ַ����Ҫ����Ƿ��д
	{
		return NULL;
	}
	return res;
}

//�޸�����
void modifySun()
{
	int *sun = get2Point(0x007794f8, 0x868, 0x5578);
	if (sun)
		*sun = 5000;

}
//�޸Ľ�Ǯ
void modifyMoney()
{
	int *m = get2Point(0x007794f8, 0x950, 0x50);
	if (m)
		*m = 50000;
}

//��һ��������ָ��SECURITY_ATTRIBUTES��̬�Ľṹ��ָ�롣��Windows 98�к��Ըò�������Windows NT�У�������ΪNULL��
//�ڶ����������������̵߳ĳ�ʼ��ջ��С��Ĭ��ֵΪ0�����κ�����£�Windows������Ҫ��̬�ӳ���ջ�Ĵ�С��
//������������ָ���̺߳�����ָ�ꡣ��������û�����ƣ����Ǳ�����������ʽ������
//DWORD WINAPI ThreadProc(PVOID pParam);
//���ĸ�����Ϊ���ݸ�ThreadProc�Ĳ������������̺߳ʹ����߳̾Ϳ��Թ������ݡ�
//���������ͨ��Ϊ0�������������̲߳�����ִ��ʱΪ���CREATE_SUSPENDED���߳̽���ֱͣ������ResumeThread���ָ��̵߳�ִ��Ϊֹ��
//������������һ��ָ�ָ꣬�����ִ����IDֵ�ı�����
DWORD WINAPI run(
	LPVOID lpThreadParameter
	)
{
	while (1)
	{
		modifySun();//����Ҫ�漸�Σ�ÿ�����Ƕ�Ӧ���޸Ľ�Ǯֵ

		int	*pCount = get3Point(0x007794f8, 0x868, 0x15c, 0x24);//��ȡ��Ʒ����
		int *pFirst = get3Point(0x007794f8, 0x868, 0x15c, 0x4c);//ֲ�ﵱǰ��ȴֵ:  +868 + 15c + 4c
		if (pCount == NULL)
		{
			Sleep(1000);
			continue;
		}
		for (int i = 0; i < *pCount; i++)
		{
			if (pFirst == NULL || pFirst + 1 == NULL)
			{
				break;
			}
			pFirst[0] = pFirst[1];//�ǰ��ȴֵ=��ȴʱ��(�ﵽ��ȴʱ������ַ�ֲ��)   ֲ����ȴʱ�� : +868 + 15c + 50
			pFirst = (int *)((int)pFirst + 0x50);//+868 + 15c + 4c + 50��һ��ֲ��
		}
		Sleep(200);
	}
}

//�޸���ȴ
void modifyCD()
{
	CreateThread(0, 0, run, 0, 0, 0);
}

//�޸���ͣ
void modifyPause()
{
	unsigned char *pCode = (unsigned char*)0x00472B50;//Ҫд��ĵ�ַ
	DWORD dwOldProtect;
	//�޸��ڴ�����	1. Ŀ���ַ��ʼλ��  2. ��С  3. ����ı�����ʽ 4. �����ϵı�����ʽ
	VirtualProtect(pCode, 3, PAGE_READWRITE,&dwOldProtect);//PAGE_READWRITE ����ɱ�Ӧ�ó����д

	//00472B50 retn 4 ������ C2 0400	������Ҫ�ں�����ͷ�ĵط��ͣ�ֱ��return ��������ͣ����
	//00472B50 ԭ���� ������ 55 88EC
	pCode[0] = 0xC2;
	pCode[1] = 0x04;
	pCode[2] = 0x00;
	//�����ԸĻ�ȥ
	VirtualProtect(pCode, 3, dwOldProtect, NULL);
}

void modifyPass()
{
	int *p = get2Point(0x007794f8, 0x950, 0x4C);
	if (p)
		*p = 36;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		modifyCD();
		modifyPause();
		modifyPass();
		modifyMoney();
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

