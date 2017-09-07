
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
/* Easy sensible linked lists. */
#include "queue.h"
/* Libevent. */
#include
/* Port to listen on. */
#define SERVER_PORT 5555
/* Length of each buffer in the buffer queue. Also becomes the amount
* of data we try to read per call to read(2). */
#define BUFLEN 1024
/**
* �����¼�Ϊ�����ı��ʱ��������Ҫһ���������洢Ҫд������ݣ�
* ֱ��libevent ֪ͨ���ǿ���д�룬���ܹ�������д�����ݡ�����򵥵�
buffer ������
* queue.h �е�TAILQ ��д�롣
*/
struct bufferq {
	/* The buffer. */
	u_char *buf;
	/* The length of buf. */
	int len;
	/* ����дbuffer �Ŀ�ʼλ��ƫ�ơ� */
	int offset;
	/* ����ṹ�� */
	TAILQ_ENTRY(bufferq) entries;
};
/**
* ָ���Ŀͻ����ݽṹ��Ҳ����һ���洢һ���û���ָ�롣
*
* �ڻ����¼��ĳ����У�ͨ����ҪΪÿ���ͻ�����һЩ״̬��Ϣ�Ķ���
*/
struct client {
	/* �¼�����������Ҫ�����¼�����һ�����ڶ��¼�һ������д��
	��֪ͨ�� */
	struct event ev_read;
	struct event ev_write;
	/* �������ݶ��У�������д������ͻ��ˡ�����ֻ�ܵȵ�libevent
	�����������socket ׼����д��ʱ��
	* ��������д�롣 */
	TAILQ_HEAD(, bufferq) writeq;
};
/**
* ����socket Ϊ������ģʽ��
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
* ���ͻ���socket �ɶ�ʱ��libevent �������������
*/
void
on_read(int fd, short ev, void *arg)
{
	struct client *client = (struct client *)arg;
	struct bufferq *bufferq;
	u_char *buf;
	int len;
	/* ��Ϊ������Ҫ�ڿ�д�½��յ�֪ͨ������������Ҫ�����ȡ��������
	* ���ҽ����ŵ��ͻ����ݶ����д����С� */
	buf = malloc(BUFLEN);
	if (buf == NULL)
		err(1, "malloc failed");
	len = read(fd, buf, BUFLEN);
	if (len == 0) {
		/* �ͻ��˶Ͽ����ӣ��������Ƴ����¼����ͷſͻ����ݽṹ��
		*/
		printf("Client disconnected.\n");
		close(fd);
		event_del(&client->ev_read);
		free(client);
		return;
	}
	else if (len < 0) {
		/* һЩ�����Ĵ�������������ر�socket���¼�������
		�ſͻ����ݽṹ�� */
		printf("Socket failure, disconnecting client: %s",
			strerror(errno));
		close(fd);
		event_del(&client->ev_read);
		free(client);
		return;
	}
	/* ���ǲ��ܽ�����buffer д�أ���Ϊ������Ҫ�ڿ���д��ʱ��Ӧ
	libevent �Ŀ�д�¼���
	* ���������ŵ��ͻ����ݽṹ�е�д���У�������һ����д�¼��� */
	bufferq = calloc(1, sizeof(*bufferq));
	if (bufferq == NULL)
		err(1, "malloc faild");
	bufferq->buf = buf;
	bufferq->len = len;
	bufferq->offset = 0;
	TAILQ_INSERT_TAIL(&client->writeq, bufferq, entries);
	/* ������������ӵ����Ҫд�ص��ͻ��˵����ݣ��������һ����д��
	��֪ͨ�� */
	event_add(&client->ev_write, NULL);
}
/**
* ���ͻ���socket ׼����д��ʱ��libevent �������������
*/
void
on_write(int fd, short ev, void *arg)
{
	struct client *client = (struct client *)arg;
	struct bufferq *bufferq;
	int len;
	/* ����һ��Ԫ���Ƴ�д���С����ǿ��ܲ�����̽��д�����Ƿ��ǿգ�
	����Ӧ��ȷ�Ϸ���ֵ����NULL�� */
	bufferq = TAILQ_FIRST(&client->writeq);
	if (bufferq == NULL)
		return;
	/* дbuffer ������ݡ�buffer �е�һ���ֿ����Ѿ���ǰ��д���ˣ�
	����ֻдʣ�µ��ֽڡ� */
	len = bufferq->len - bufferq->offset;
	len = write(fd, bufferq->buf + bufferq->offset,
		bufferq->len - bufferq->offset);
	if (len == -1) {
		if (errno == EINTR || errno == EAGAIN) {
			/* д������һ���źŴ�ϣ��������ǲ���д�����ݣ�
			����һ�²����ء� */
			event_add(&client->ev_write, NULL);
			return;
		}
		else {
			/* һЩ������socket ���������˳��ɡ� */
			err(1, "write");
		}
	}
	else if ((bufferq->offset + len) < bufferq->len) {
		/* �������е����ݶ���д���ˣ�����д���ƫ�Ʋ�����д��
		�¼��� */
		bufferq->offset += len;
		event_add(&client->ev_write, NULL);
		return;
	}
	/* �����Ѿ�������д���ˣ���д�������Ƴ����buffer�� */
	TAILQ_REMOVE(&client->writeq, bufferq, entries);
	free(bufferq->buf);
	free(bufferq);
}
/**
* ����һ����������׼��������ʱ��libevent ���������������
*/
void
on_accept(int fd, short ev, void *arg)
{
	int client_fd;
	struct sockaddr_in client_addr;
	socklen_t client_len = sizeof(client_addr);
	struct client *client;
	/* ��������µ��������� */
	client_fd = accept(fd, (struct sockaddr *)&client_addr,
		&client_len);
	if (client_fd == -1) {
		warn("accept failed");
		return;
	}
	/* ���ÿͻ���socket Ϊ������ģʽ�� */
	if (setnonblock(client_fd) < 0)
		warn("failed to set client socket non-blocking");
	/* �����Ѿ�������һ���µĿͻ�������һ���ͻ����ݽṹ����������
	����ͻ���״̬�� */
	client = calloc(1, sizeof(*client));
	if (client == NULL)
		err(1, "malloc failed");
	/* ���ö��¼������ͻ���socket �ɶ�ʱ��libevent ������on_read()
	������
	* ����Ҳ���ϵĹ���ɶ��¼������Բ�����ÿ�ζ�ȡʱ���¼������
	���ˡ� */
	event_set(&client->ev_read, client_fd, EV_READ | EV_PERSIST,
		on_read,
		client);
	/* ���õ��¼�û�м������¼��Ա㼤������ */
	event_add(&client->ev_read, NULL);
	/* ����д�¼������������������ݿ�д֮ǰ����Ҫ������� */
	event_set(&client->ev_write, client_fd, EV_WRITE, on_write,
		client);
	/* ��ʼ���ͻ���д���С� */
	TAILQ_INIT(&client->writeq);
	printf("Accepted connection from %s\n",
		inet_ntoa(client_addr.sin_addr));
}
int
main(int argc, char **argv)
{
	int listen_fd;
	struct sockaddr_in listen_addr;
	int reuseaddr_on = 1;
	/* socket �Ľ����¼����� */
	struct event ev_accept;
	/* ��ʼ�� libevent. */
	event_init();
	/* �������ǵļ���socket�� This is largely boiler plate
	* code that I'll abstract away in the future. */
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
	/* ����socket Ϊ������ģʽ�������ʹ��libevent �����ʱ����ġ�
	*/
	if (setnonblock(listen_fd) < 0)
		err(1, "failed to set server socket to non-blocking");
	/* ������������һ��������socket�����Ǵ���һ�����¼����Ա��п�
	����������ʱ�ܹ����յ�֪ͨ�� */
	event_set(&ev_accept, listen_fd, EV_READ | EV_PERSIST, on_accept,
		NULL);
	event_add(&ev_accept, NULL);
	/* ���� libevent ʱ��ѭ��. */
	event_dispatch();
	return 0;
}