/* server.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define MAXLINE 80
#define SERV_PORT 8000
int main(int argc, char *argv[])
{
	int i, maxi, maxfd, listenfd, connfd, sockfd;
	int nready, client[FD_SETSIZE]; /* FD_SETSIZE Ĭ��Ϊ1024 */
	ssize_t n;
	fd_set rset, allset;
	char buf[MAXLINE];
	char str[INET_ADDRSTRLEN]; /* #define INET_ADDRSTRLEN 16 */
	socklen_t cliaddr_len;
	struct sockaddr_in cliaddr, servaddr;
	listenfd = Socket(AF_INET, SOCK_STREAM, 0);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(SERV_PORT);
	bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	listen(listenfd, 20); /* Ĭ�����128 */
	maxfd = listenfd; /* ��ʼ��*/
	maxi = -1; /* client[]���±�*/
	for (i = 0; i < FD_SETSIZE; i++)
		client[i] = -1; /* ��-1��ʼ��client[] */
	FD_ZERO(&allset);
	FD_SET(listenfd, &allset); /* ����select����ļ���������*/
	for ( ; ; ) {
		rset = allset; /* ÿ��ѭ��ʱ����������select����źż�*/
		nready = select(maxfd+1, &rset, NULL, NULL, NULL);
		if (nready < 0)
			perr_exit("select error");
		if (FD_ISSET(listenfd, &rset)) { /* new client connection */
			cliaddr_len = sizeof(cliaddr);
			connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &cliaddr_len);
			printf("received from %s at PORT %d\n",
			inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)),
			ntohs(cliaddr.sin_port));
			for (i = 0; i < FD_SETSIZE; i++)
				if (client[i] < 0) {
					client[i] = connfd; /* ����accept���ص��ļ���������client[]��*/
					break;
				}
			/* �ﵽselect�ܼ�ص��ļ���������1024 */
			if (i == FD_SETSIZE) {
				fputs("too many clients\n", stderr);
				exit(1);
			}
			FD_SET(connfd, &allset); /* ���һ���µ��ļ�������������źż���*/
			if (connfd > maxfd)
				maxfd = connfd; /* select��һ��������Ҫ*/
			if (i > maxi)
				maxi = i; /* ����client[]����±�ֵ*/
			if (--nready == 0)
				continue; /* ���û�и���ľ����ļ������������ص�����select��������,������δ
				������ľ����ļ�������*/
		}
		for (i = 0; i <= maxi; i++) { /* ����ĸ�clients �����ݾ���*/
			if ( (sockfd = client[i]) < 0)
				continue;
			if (FD_ISSET(sockfd, &rset)) {
				if ( (n = Read(sockfd, buf, MAXLINE)) == 0) {
					/* ��client�ر�����ʱ����������Ҳ�رն�Ӧ����*/
					Close(sockfd);
					FD_CLR(sockfd, &allset); /* ���select��ش��ļ�������*/
					client[i] = -1;
				} else {
					int j;
					for (j = 0; j < n; j++)
					buf[j] = toupper(buf[j]);
					Write(sockfd, buf, n);
				}
				if (--nready == 0)
					break;
			}
		}
	}
	close(listenfd);
	return 0;
}