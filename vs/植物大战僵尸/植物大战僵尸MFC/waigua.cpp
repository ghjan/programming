#include "stdafx.h"

HANDLE hProcess;//���̾��
BOOL initWaigua(HANDLE *h)
{
	//findwindow  lpClassName����ָ��������lpWindowNameָ�򴰿����������ָ���������ʹ��ڵ��������ʾ�ɹ�����һ�����ڵľ�������򷵻��㡣
	HWND hwnd = FindWindow(NULL, TEXT("Plants vs. Zombies 1.2.0.1073 RELEASE"));
	if (NULL == hwnd)
	{
		//AfxMessageBox(TEXT("��ȡ����ʧ��"));
		return false;
	}
	//ͨ�����ڻ�ȡ����id��Ҳ����PID
	DWORD dwProcessId;
	GetWindowThreadProcessId(hwnd, &dwProcessId);


	//��ȡ���̾��  1.//�����õ��ķ���Ȩ�ޣ���־��2. �Ƿ�̳о��  3.���̱�ʾ��
	*h = OpenProcess(PROCESS_ALL_ACCESS, NULL, dwProcessId);
	if (!*h)
	{
		AfxMessageBox(TEXT("���ܴ򿪽���"));
		return false;
	}
	hProcess = *h;
	return true;
}

//int base = 0x007794f8;
int *get2Point(int base, int p1, int p2)
{
	//ReadProcessMemory  ���ڴ棬�ŵ�������������
	int Base,P1, *P2;
	if (!ReadProcessMemory(hProcess, (LPVOID)base,&Base,4,NULL))//���� Nonzero indicates success.Zero indicatesfailure.
	{
		return NULL;
	}
	if (!ReadProcessMemory(hProcess, (LPVOID)(Base + p1), &P1, 4, NULL))//1.�����2.��ַ��3.װ���ݵĵ�ַ��4.��С
	{
		return NULL;
	}
	P2 = (int *)(P1 + p2);
	return P2;
}
int *get3Point(int base, int p1, int p2, int p3)
{
	int Base, P1, P2, *P3;
	if (!ReadProcessMemory(hProcess, (LPVOID)base, &Base, 4, NULL))//���� Nonzero indicates success.Zero indicatesfailure.
	{
		return NULL;
	}
	if (!ReadProcessMemory(hProcess, (LPVOID)(Base + p1), &P1, 4, NULL))
	{
		return NULL;
	}
	if (!ReadProcessMemory(hProcess, (LPVOID)(P1 + p2), &P2, 4, NULL))
	{
		return NULL;
	}
	P3 = (int *)(P2 + p3);
	return P3;
}

//�޸�����
void modifySun()
{
	int *sun = get2Point(0x007794f8, 0x868, 0x5578);
	int sunValue = 500;
	//����ֵ ����ֵ����ɹ���
	WriteProcessMemory(hProcess, sun, &sunValue,4,NULL);
}

//�޸Ľ�Ǯ
void modifyMoney()
{
	int *m = get2Point(0x007794f8, 0x950, 0x50);
	int mValue = 5000;
	WriteProcessMemory(hProcess, m, &mValue, 4, NULL);
}

void modifyPass(int pass)
{
	int *p = get2Point(0x007794f8, 0x950, 0x4C);
	WriteProcessMemory(hProcess, p, &pass, 4, NULL);
}

//�޸���ȴ
void modifyCD()
{
	int	*pCount = get3Point(0x007794f8, 0x868, 0x15c, 0x24);//��ȡ��Ʒ����
	int *pFirst = get3Point(0x007794f8, 0x868, 0x15c, 0x4c);//ֲ�ﵱǰ��ȴֵ:  +868 + 15c + 4c
	if (pCount == NULL)
	{
		Sleep(1000);
	}
	int count;
	ReadProcessMemory(hProcess, pCount, &count, 4, NULL);//��Ҫ��ȡ��Ʒ����
	for (int i = 0; i < count; i++)
	{
		if (pFirst == NULL || pFirst + 1 == NULL)
		{
			break;
		}
		//pFirst[0] = pFirst[1];
		int read;
		ReadProcessMemory(hProcess, pFirst + 1, &read, 4, NULL);
		WriteProcessMemory(hProcess, pFirst, &read, 4, NULL);
		pFirst = (int *)((int)pFirst + 0x50);//+868 + 15c + 4c + 50��һ��ֲ��
	}
	Sleep(100);
}

//�޸���ͣ
void pauseYes(unsigned char *pCode, unsigned char code[])
{
	DWORD dwOldProtect;
	//�޸��ڴ�����	1. Ŀ���ַ��ʼλ��  2. ��С  3. ����ı�����ʽ 4. �����ϵı�����ʽ
	//VirtualProtect(pCode, 3, PAGE_READWRITE, &dwOldProtect);//PAGE_READWRITE ����ɱ�Ӧ�ó����д
	VirtualProtectEx(hProcess, pCode, 3, PAGE_READWRITE, &dwOldProtect);

	//д��retn 4;
	WriteProcessMemory(hProcess, pCode, code, 3, NULL);

	//�����ԸĻ�ȥ
	VirtualProtectEx(hProcess,pCode, 3, dwOldProtect, NULL);
}
void pauseNo(unsigned char *pCode, unsigned char code[])
{
	DWORD dwOldProtect;
	//�޸��ڴ�����	1. Ŀ���ַ��ʼλ��  2. ��С  3. ����ı�����ʽ 4. �����ϵı�����ʽ
	//VirtualProtect(pCode, 3, PAGE_READWRITE, &dwOldProtect);//PAGE_READWRITE ����ɱ�Ӧ�ó����д
	VirtualProtectEx(hProcess, pCode, 3, PAGE_READWRITE, &dwOldProtect);

	//д��retn 4;
	WriteProcessMemory(hProcess, pCode, code, 3, NULL);

	//�����ԸĻ�ȥ
	VirtualProtectEx(hProcess, pCode, 3, dwOldProtect, NULL);
}

