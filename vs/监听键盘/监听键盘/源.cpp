#include<Windows.h>

void key()
{
	keybd_event(VK_LWIN, 0, 0, 0);//���̰���
	keybd_event(VK_LWIN, 0, 2, 0);//�����ɿ�
}
void zuhe1()
{
	//��ϼ�
	keybd_event(VK_LWIN, 0, 0, 0);//���̰���
	keybd_event('E', 0, 0, 0);//E������
	keybd_event('E', 0, 2, 0);//E���ɿ�
	keybd_event(VK_LWIN, 0, 2, 0);//�����ɿ�
}
void zuhe2()
{
	//��ϼ�
	keybd_event(VK_LWIN, 0, 0, 0);//���̰���
	keybd_event('R', 0, 0, 0);//R������
	keybd_event('R', 0, 2, 0);//R���ɿ�
	keybd_event(VK_LWIN, 0, 2, 0);//�����ɿ�
}
void zuhe3()
{
	//��ϼ�
	keybd_event(VK_LWIN, 0, 0, 0);//���̰���
	keybd_event('R', 0, 0, 0);//R������
	keybd_event('R', 0, 2, 0);//R���ɿ�
	keybd_event(VK_LWIN, 0, 2, 0);//�����ɿ�

	Sleep(1000);

	keybd_event('C', 0, 0, 0);
	keybd_event('C', 0, 2, 0);
	keybd_event('A', 0, 0, 0);
	keybd_event('A', 0, 2, 0);
	keybd_event('L', 0, 0, 0);
	keybd_event('L', 0, 2, 0);
	keybd_event('C', 0, 0, 0);
	keybd_event('C', 0, 2, 0);
	keybd_event(VK_RETURN, 0, 0, 0);//�س���
	keybd_event(VK_RETURN, 0, 2, 0);
}

void main()
{
	zuhe3();
	Sleep(5000);
	keybd_event(VK_MENU, 0, 0, 0);
	keybd_event(VK_F4, 0, 0, 0);
	keybd_event(VK_F4, 0, 2, 0);
	keybd_event(VK_MENU, 0, 2, 0);
}