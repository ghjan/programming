#include<windows.h>
#include<stdlib.h>
DWORD WINAPI mymsg(LPVOID lp)
{
	return MessageBoxA(0, "chen ming dong", "hello", 0);//visual studio ���ü�return 
}
void main()
{
	HANDLE hthread;
	DWORD threadid;//�����̱߳��
	for (int i = 0; i < 4; i++)
	{
		hthread = CreateThread(
			NULL,//��ȫ����
			NULL, //��ջ��С
			mymsg,//�߳����
			NULL,//��������
			0,//����ִ��
			&threadid);//�����߳�id
	}

	system("pause");
}