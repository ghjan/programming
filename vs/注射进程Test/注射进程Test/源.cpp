
#include <Windows.h>
#include <iostream>
#include <ctime>

extern "C" _declspec(dllexport) bool APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH://����ӳ��
		// attach to process
		// return FALSE to fail DLL load
		break;

	case DLL_PROCESS_DETACH://����ж��
		// detach from process
		MessageBoxA(0, "�벻Ҫ�붫��Ϊ��", "����", MB_OK | MB_ICONINFORMATION);
		break;

	case DLL_THREAD_ATTACH://�߳�ӳ��
		// attach to thread
		ShellExecuteA(0, "open", "http://blog.csdn.net/program_anywhere", 0, 0, 2);//����ҳ
		srand((unsigned)time(NULL));/*������*/
		Sleep(2000);
		SetCursorPos(490, 507);
		Sleep(50);
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);//ģ����갴��
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//ģ����굯��

		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

		MessageBoxA(0, "O(��_��)O����~\n������ж���\n�����ڱ���Ϸ\n����ϵ��������æ\nQQ:379168491", "�����޴�����", MB_OK | MB_ICONINFORMATION);
	
		for (int i = 0; i < 5; i++)
		{
			SetCursorPos(0, 760);
			Sleep(1000);
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);//ģ����갴��
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//ģ����굯��

			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		}
		break;

	case DLL_THREAD_DETACH://�߳�ж��
		// detach from thread
		break;
	}
	return TRUE; // succesful
}