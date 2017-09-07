/*
* libevent echo server example using buffered events.
*/
#include
#include
#include
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
* ָ���û����ݵĽṹ��Ҳ����һ���û���ָ�롣
*/
struct client {
	/* �ͻ���socket */
	int fd;
	/* ����ͻ��� bufferedevent ���� */
	struct bufferevent *buf_ev;
};
/**
* ����һ��socket Ϊ������ģʽ��
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
* �������ݿɶ�ʱ��libevent �����������
*/
void
buffered_on_read(struct bufferevent *bev, void *arg)
{
	/* д�ض���������ע�� bufferevent_write_buffer ���𽥷�������
	�������
	* �������ǵ�����ʱ�����Ϳ�ʼ��Ч�ˡ� */
	bufferevent_write_buffer(bev, bev->input);
}
/**
* ��д����Ϊ0 ʱ��libevent �����������������д���������ֻ����Ϊ
libevent ��Ҫ����������û��ʹ������
*/
void
buffered_on_write(struct bufferevent *bev, void *arg)
{
}
/**
* ��������socket ��������������ʱ��libevent ���������������
*/
void
buffered_on_error(struct bufferevent *bev, short what, void *arg)
{
	struct client *client = (struct client *)arg;
	if (what & EVBUFFER_EOF) {
		/* �ͻ��˶Ͽ����ӣ��������Ƴ����¼����ͷſͻ����ݽṹ��
		*/
		printf("Client disconnected.\n");
	}
	else {
		warn("Client socket error, disconnecting.\n");
	}
	bufferevent_free(client->buf_ev);
	close(client->fd);
	free(client);
}
/**
* ����һ����������׼��������ʱ�������������libevent ���á�
*/
void
on_accept(int fd, short ev, void *arg)
{
	int client_fd;
	struct sockaddr_in client_addr;
	socklen_t client_len = sizeof(client_addr);
	struct client *client;
	client_fd = accept(fd, (struct sockaddr *)&client_addr,
		&client_len);
	if (client_fd < 0) {
		warn("accept failed");
		return;
	}
	/* ���ÿͻ���socket Ϊ������ģʽ�� */
	if (setnonblock(client_fd) < 0)
		warn("failed to set client socket non-blocking");
	/* ���ǽ���һ���µĿͻ�������һ���ͻ����ݽṹ���� */
	client = calloc(1, sizeof(*client));
	if (client == NULL)
		err(1, "malloc failed");
	client->fd = client_fd;
	/* ���� buffered �¼���
	*
	* ��һ�������������¼����ļ��������������ǿͻ���socket��
	*
	* �ڶ���������һ���ص��������������Ѿ���socket ��ȡ���ҶԳ���
	��Чʱ���������á�
	*
	* ������������һ���ص���������д������������Сֵʱ���������á�
	* ��ͨ����ζ�ţ���д�뻺��������Ϊ0 ʱ������ص������������á�
	* �����뱻���壬����ʵ���������������ص������в����κδ���
	*
	* ���ĸ�������һ���ص�����������socket ������ʱ���������á�
	* �����������̽��ͻ��˶Ͽ����ӣ����������Ĵ���
	*
	* ��������������洢һ�����ᴫ�ݸ������ص������Ĳ�����������
	����洢�ͻ����ݶ���
	*/
	client->buf_ev = bufferevent_new(client_fd, buffered_on_read,
		buffered_on_write, buffered_on_error, client);
	/* ���Ǳ����ڻص�����������ǰ��ʹ����Ч�� */
	bufferevent_enable(client->buf_ev, EV_READ);
	printf("Accepted connection from %s\n",
		inet_ntoa(client_addr.sin_addr));
}
int
main(int argc, char **argv)
{
	int listen_fd;
	struct sockaddr_in listen_addr;
	struct event ev_accept;
	int reuseaddr_on;
	/* ��ʼ�� libevent. */
	event_init();
	/* �������ǵļ���socket�� */
	listen_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (listen_fd < 0)
		err(1, "listen failed");
	memset(&listen_addr, 0, sizeof(listen_addr));
	listen_addr.sin_family = AF_INET;
	listen_addr.sin_addr.s_addr = INADDR_ANY;
	listen_addr.sin_port = htons(SERVER_PORT);
	if (bind(listen_fd, (struct sockaddr *)&listen_addr,
		sizeof(listen_addr)) < 0)
		err(1, "bind failed");
	if (listen(listen_fd, 5) < 0)
		err(1, "listen failed");
	reuseaddr_on = 1;
	setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &reuseaddr_on,
		sizeof(reuseaddr_on));
	/* ����socket Ϊ������ģʽ��������libevent ���ʱ�Ǳ���ġ� */
	if (setnonblock(listen_fd) < 0)
		err(1, "failed to set server socket to non-blocking");
	/* ������������һ������socket�����Ǵ���һ�����¼����Ա����п�
	����������ʱ�ܹ����յ�֪ͨ�� */
	event_set(&ev_accept, listen_fd, EV_READ | EV_PERSIST, on_accept,
		NULL);
	event_add(&ev_accept, NULL);
	/* ��ʼ�¼�ѭ���� */
	event_dispatch();
	return 0;
}