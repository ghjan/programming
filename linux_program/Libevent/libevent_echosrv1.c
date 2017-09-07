/*
* libevent echo server example.
*/
#include
#include
#include
/* For inet_ntoa. */
#include
/* Required by event.h. */
#include
#include
#include
#include
#include
#include
#include
#include
/* Libevent. */
#include
/* Port to listen on. */
#define SERVER_PORT 5555
/**
* ����ṹ��ָ���Ŀͻ������ݣ����������ָֻ���˶��¼�����
*/
struct client {
	struct event ev_read;
};
/**
* ��һ��socket ���óɷ�����ģʽ
*/
int
setnonblock(int fd)
{
	int flags;
	flags = fcntl(fd, F_GETFL);
	if (flags < 0)
		return flags;
	flags |= O_NONBLOCK;
	if (fcntl(fd, F_SETFL, flags) < 0)
		return -1;
	return 0;
}
/**
* ����������ͻ��˵�socket �ɶ�ʱ��libevent ����
*/
void
on_read(int fd, short ev, void *arg)
{
	struct client *client = (struct client *)arg;
	u_char buf[8196];
	int len, wlen;
	len = read(fd, buf, sizeof(buf));
	if (len == 0) {
		/* �ͻ��˶Ͽ����ӣ��������Ƴ����¼������ͷſͻ����ݽ�
		�� */
		printf("Client disconnected.\n");
		close(fd);
		event_del(&client->ev_read);
		free(client);
		return;
	}
	else if (len < 0) {
		/* �����������Ĵ���������ر�socket���Ƴ��¼�������
		�ſͻ����ݽṹ */
		printf("Socket failure, disconnecting client: %s", strerror(errno));
		close(fd);
		event_del(&client->ev_read);
		free(client);
		returreturn;
	}
	/* Ϊ�˼�㣬����ֱ�ӽ�����д�ص��ͻ��ˡ�ͨ�����ǲ����ڷ�����
	��Ӧ�ó�������ô����
	* ����Ӧ�ý����ݷŵ������У��ȴ���д�¼���ʱ����д�ؿͻ��ˡ�
	*/
	wlen = write(fd, buf, len);
	if (wlen < len) {
		/* ����û�а��������ݶ�д�ء�����������ʵ��Ķ���/����
		���ƣ�
		* �����ܹ����ٴεĿ�д�¼����ٴ�д��ʣ������ݡ���Ϊ
		����һ���򵥵����ӣ�
		* ���ǽ�����ȥ��û��д������ݡ� */
		printf("Short write, not all data echoed back to
			client.\n");
	}
}
/**
* ����һ����������׼��������ʱ�������������libevent ���á� */
void
on_accept(int fd, short ev, void *arg)
{
	int client_fd;
	struct sockaddr_in client_addr;
	socklen_t client_len = sizeof(client_addr);
	struct client *client;
	/* �����µ����� */
	client_fd = accept(fd, (struct sockaddr *)&client_addr, &client_len);
	if (client_fd == -1) {
		warn("accept failed");
		return;
	}
	/* ���ÿͻ���socket Ϊ������ģʽ�� */
	if (setnonblock(client_fd) < 0)
		warn("failed to set client socket non-blocking");
	/* ���ǽ�����һ���µĿͻ�������һ���µĿͻ����ݽṹ����������
	����ͻ���״̬�� */
	client = calloc(1, sizeof(*client));
	if (client == NULL)
		err(1, "malloc failed");
	/* ���ö��¼���libevent ���ڿͻ���socket �ɶ�ʱ����on_read ��
	����
	* ����Ҳ������Ҳ�᲻�ϵ���Ӧ���¼����������ǲ�����ÿ�ζ�ȡʱ
	�ٴ���Ӷ��¼��� */
	event_set(&client->ev_read, client_fd, EV_READ | EV_PERSIST,
		on_read,
		client);
	/* ���õ��¼���û�м��ʹ������¼����伤� */
	event_add(&client->ev_read, NULL);
	printf("Accepted connection from %s\n",
		inet_ntoa(client_addr.sin_addr));
}
int
main(int argc, char **argv)
{
	int listen_fd;
	struct sockaddr_in listen_addr;
	int reuseaddr_on = 1;
	/* ��������������¼����� */
	struct event ev_accept;
	/* ��ʼ�� libevent. */
	event_init();
	/* �������Ǽ�����socket�� */
	listen_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (listen_fd < 0)
		err(1, "listen failed");
	if (setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR,
		&reuseaddr_on,
		sizeof(reuseaddr_on)) == -1)
		err(1, "setsockopt failed");
	memset(&listen_addr, 0, sizeof(listen_addr));
	listen_addr.sin_family = AF_INET;
	listen_addr.sin_addr.s_addr = INADDR_ANY;
	listen_addr.sin_port = htons(SERVER_PORT);
	if (bind(listen_fd, (struct sockaddr *)&listen_addr,
		sizeof(listen_addr)) < 0)
		err(1, "bind failed");
	if (listen(listen_fd, 5) < 0)
		err(1, "listen failed");
	/* ����socket Ϊ������ģʽ��ʹ��libevent ������Ǳز����ٵġ� */
	if (setnonblock(listen_fd) < 0)
		err(1, "failed to set server socket to non-blocking");
	/* ������������һ��������socket�����Ǵ���һ�����¼������пͻ�
	����ʱ������֪ͨ�� */
	event_set(&ev_accept, listen_fd, EV_READ | EV_PERSIST, on_accept,
		NULL);
	event_add(&ev_accept, NULL);
	/* ��ʼ libevent ���¼�ѭ���� */
	event_dispatch();
	return 0;
}