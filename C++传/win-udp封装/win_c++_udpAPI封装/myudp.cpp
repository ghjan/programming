#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "myudp.h"
#include<string.h>
#include<stdio.h>
#ifndef LINUX
#include<WinSock2.h>
#else
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#define SOCKET int
#endif
myudp::myudp()
{
#ifndef LINUX
	//��ʼ��socket
	DWORD ver;//typedef unsigned long       DWORD;
	WSADATA wsaData;
	ver = MAKEWORD(1, 1);//����windows���õ���ʲô�汾
	WSAStartup(ver, &wsaData);//��һ������������������
#endif
	//����һ��socket   1.ָ��socket���ĸ�Э��
	st = socket(AF_INET,//��tcp/ipЭ��
		SOCK_DGRAM,//Ҫ��myudpЭ��
		0);//Ĭ��Ϊ0
}


myudp::~myudp()
{
#ifdef LINUX
	close(st);
#else
	closesocket(st);//�ر�socket
	WSACleanup();//�ͷ�win socket��Դ
#endif
}

int myudp::socket_send(const char*IP, char buf[], int len, int port)
{
	struct  sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));//��ʼ��
	addr.sin_family = AF_INET;//����Ҫ���ĸ�Tcp/IPЭ��
	addr.sin_port = htons(port);//host to net short
	addr.sin_addr.s_addr = inet_addr(IP);

	size_t rc = sendto(st, buf, len + 1, 0, (struct sockaddr *)&addr, sizeof(addr));

	return rc;//���˶��ٳ�ȥ
}

int myudp::socket_bind(int port)
{
	struct  sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);//���ն˲���Ҫָ������IP
	return bind(st, (struct sockaddr *)&addr, sizeof(addr));
}

int myudp::socket_recv(char IPbuf[], char buf[], int len)
{
	int rc = 0;
	struct sockaddr_in sendaddr;
	memset(&sendaddr, 0, sizeof(sendaddr));

#ifdef LINUX
	socklen_t len;
#else
	int addrlen;
#endif
	addrlen = sizeof(sendaddr);
	memset(buf, 0, addrlen);
	rc = recvfrom(st, buf, len, 0, (struct sockaddr *)&sendaddr, &addrlen);
	strcpy(IPbuf, inet_ntoa(sendaddr.sin_addr));
	return rc;
}
