#include <netinet/in.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/select.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

#define MAXLINE 1024
#define IPADDRESS "127.0.0.1"
#define SERV_PORT 8787

#define max(a,b) (a > b) ? a : b

static void handle_recv_msg(int sockfd, char *buf) 
{
	printf("client recv msg is:%s\n", buf);
	sleep(5);
	write(sockfd, buf, strlen(buf) +1);
}

static void handle_connection(int sockfd)
{
	char sendline[MAXLINE],recvline[MAXLINE];
	int maxfdp,stdineof;
	fd_set readfds;
	int n;
	struct timeval tv;
	int retval = 0;

	while (1) {

		FD_ZERO(&readfds);//���ļ�����������������λ��0
		FD_SET(sockfd,&readfds);//���ļ�������������fdλ��1
		maxfdp = sockfd;

		tv.tv_sec = 5;
		tv.tv_usec = 0;

		retval = select(maxfdp+1,&readfds,NULL,NULL,&tv);

		if (retval == -1) {
			return ;
		}
		if (retval == 0) {
			printf("client timeout.\n");
			continue;
		}

		if (FD_ISSET(sockfd, &readfds)) {//�����ļ�������������fd�Ƿ���1
			n = read(sockfd,recvline,MAXLINE);
			if (n <= 0) {
				fprintf(stderr,"client: server is closed.\n");
				close(sockfd);
				FD_CLR(sockfd,&readfds);
				return;
			}
			handle_recv_msg(sockfd, recvline);
		}
	}
}

int main(int argc,char *argv[])
{
	int sockfd;
	struct sockaddr_in servaddr;

	sockfd = socket(AF_INET,SOCK_STREAM,0);

	bzero(&servaddr,sizeof(servaddr));//���ֽ��ַ���ǰn���ֽ�Ϊ���Ұ�����\0����
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	inet_pton(AF_INET,IPADDRESS,&servaddr.sin_addr);//IP��ַת�������������ڽ�IP��ַ�ڡ����ʮ���ơ��͡�������������֮��ת��,�������ʮ���ơ� ��> ��������������

	int retval = 0;
	retval = connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	if (retval < 0) {
		fprintf(stderr, "connect fail,error:%s\n", strerror(errno));
		return -1;
	}

	printf("client send to server .\n");
	write(sockfd, "hello server", 32);

	handle_connection(sockfd);

	return 0;
}
/*
int select(int nfds, fd_set *readfds, fd_set *writefds,fd_set *exceptfds, struct timeval *timeout);
	nfds: ��ص��ļ���������������ļ���������1����Ϊ�˲���������ں˼��ǰ���ٸ��ļ���������״̬
	readfds������ж����ݵ����ļ����������ϣ����봫������
	writefds�����д���ݵ����ļ����������ϣ����봫������
	exceptfds������쳣�������ļ�����������,��������ݵ����쳣�����봫������
	timeout����ʱ�������ʱ�䣬3�����
	1.NULL����Զ����ȥ
	2.����timeval���ȴ��̶�ʱ��
	3.����timeval��ʱ���Ϊ0����������ֺ��������أ���ѯ


struct timeval {
long tv_sec;  seconds 
long tv_usec;  microseconds 

RETURN VALUE
	>0�����������ֵ�����Ŀ
	-1������
	0 ����ʱ
};


inet_pton���������ʮ���ơ� ��> ��������������
int inet_pton(int af, const char *src, void *dst);
	�������ת���ַ����������ַ����һ������af�ǵ�ַ�أ��ڶ�������*src����Դ��ַ������������* dst����ת��������ݡ�
	inet_pton ��inet_addr����չ��֧�ֵĶ��ַ�������У�
	af = AF_INET
	srcΪָ���ַ��͵ĵ�ַ����ASCII�ĵ�ַ���׵�ַ��ddd.ddd.ddd.ddd��ʽ�ģ����������õ�ַת��Ϊin_addr�Ľṹ�壬��������*dst�С�
	af = AF_INET6
	srcΪָ��IPV6�ĵ�ַ���������õ�ַת��Ϊin6_addr�Ľṹ�壬��������*dst�С�
	���������������һ����ֵ������errno����ΪEAFNOSUPPORT���������afָ���ĵ�ַ���src��ʽ���ԣ�����������0��

*/