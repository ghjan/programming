#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <WinSock2.h>
//#include <thread>
//thread��Ҳ��bind����socket��Ҳ��bind   ���ʱ�����ǲ����� using namespace std; ��Ϊ thread �е� bind ����ʱ std::bind  Ĭ�ϻ������� ���������socket�е�bind
#pragma comment(lib,"ws2_32.lib")

//DWORD WINAPI receive(
//	LPVOID lpThreadParameter
//	)
//{
//	char buf[1024];
//	SOCKET cliSocket = (SOCKET)lpThreadParameter;
//	while (1)
//	{
//		memset(buf, 0, sizeof(buf));
//		if (recv(cliSocket, buf, sizeof(buf), 0) <= 0)
//		{
//			std::cout << "û�н��ܵ���Ϣ" << std::endl;
//			return;
//		}
//		std::cout << buf << std::endl;
//	}
//	closesocket(cliSocket);
//}
//DWORD WINAPI delivery(
//	LPVOID lpThreadParameter
//	)
//{
//	char buf[1024];
//	SOCKET cliSocket = (SOCKET)lpThreadParameter;
//	while (1)
//	{
//		std::cout << "���ˣ� ";
//		std::cin.getline(buf, 1024);
//
//		/* send to client */
//		if (send(cliSocket, buf, sizeof(buf), 0) <= 0)
//		{
//			std::cout << "send error" << std::endl;
//			return;
//		}
//	}
//	//closesocket(cliSocket);
//}


int main11()
{
	/* init winsock */
	WSADATA data;
	if (WSAStartup(MAKEWORD(2, 2), &data));

	/* create a tcp socket */
	SOCKET serSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	//����һ���ṹ��
	SOCKADDR_IN addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(6666);
	addr.sin_addr.S_un.S_addr = htons(INADDR_ANY);//����IP

	if (bind(serSocket, (sockaddr*)&addr, sizeof(addr))!=0)//����Ϣ
	{
		std::cout << "��ʧ��" << std::endl;
		return -1;
	}
	if (listen(serSocket, 5) != 0)
	{
		std::cout << "����ʧ��" << std::endl;
		return -1;
	}

	/* waiting for connection */
	SOCKADDR_IN cliAddr;
	int len = sizeof(cliAddr);
	char buf[1024];
	while (1)
	{
		printf("�ȴ�����...\n");
		SOCKET cliSocket = accept(serSocket, (sockaddr*)&cliAddr, &len);//������acceptһ�� �ͷ��˵�ַ��cliAddr��������һ���ͷ���socket
		if (cliSocket <= 0)
		{
			std::cout << "accept ʧ��" << std::endl;
			return -1;
		}
		printf("���ܵ�һ�����ӣ�%s \r\n", inet_ntoa(cliAddr.sin_addr));

		//��������
		buf[0] = '\0';
		int res = recv(cliSocket, buf, sizeof(buf), 0);
		if (res > 0)
		{
			buf[res] = '\0';
			printf(buf);
		}
		//��������
		char* sendData = "��ð����ͷ��ˣ���\n";
		send(cliSocket, sendData, strlen(sendData), 0);
		closesocket(cliSocket);
	}

	/*CreateThread(0, 0, receive, (LPVOID)cliSocket, 0, 0);
	CreateThread(0, 0, delivery, (LPVOID)cliSocket, 0, 0);*/

	return 0;
}

