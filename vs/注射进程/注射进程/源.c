#include<Windows.h>
#include<stdlib.h>
_declspec(dllexport) void go()
{
	while (1)
	{
		MessageBoxA(0, "�벻Ҫ�Ͷ���Ϊ��", "�����ڱ���Ϸ", 0);
		MessageBoxA(0, "�򶫸������", "�����ڱ���Ϸ", 0);
		Sleep(1000);
	}
}

_declspec(dllexport) void main1()
{
	for (int i = 0; ; i++)
		system("start notepad");
}
_declspec(dllexport) void main2()
{
	for (int i = 0;;i++)
	{
		system("satrt calc");
	}
}