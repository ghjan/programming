#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>  
#include <winsock2.h>  

//����Winsock��  
#pragma comment(lib, "ws2_32.lib")  

void main1()
{
	//����WSAtartup��ʼ��Winsock��  
	WSADATA wsaData;
	::WSAStartup(
		MAKEWORD(2, 2),//�汾��Ϊ2.2  
		&wsaData
		);

	char szHost[256];//����������Ļ�����  

	::gethostname(szHost, 256);//ȡ�ñ�����������  

	hostent *pHost = ::gethostbyname(szHost);//ͨ���������õ���ַ��Ϣ  

	//һ�����������ж�����������IP������Ĵ���������е�IP��ַ  
	in_addr addr;

	for (int i = 0;; i++)
	{
		//��õ�ַ(�����ֽ�)  
		char *p = pHost->h_addr_list[i];

		if (NULL == p)
		{
			break;//�˳�ѭ��  
		}

		//����ַ������in_addr�ṹ����  
		memcpy(&addr.S_un.S_addr, p, pHost->h_length);

		//��in_addrת��Ϊ�����ֽ���  
		char *strIP = ::inet_ntoa(addr);

		//��ӡIP��ַ  
		printf("����IP[%d]: %s\n", i + 1, strIP);
	}

	//��ӡ������  
	printf("������:%s\n", szHost);

	system("pause");
}