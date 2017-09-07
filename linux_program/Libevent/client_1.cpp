#include<sys/types.h>  
#include<sys/socket.h>  
#include<netinet/in.h>  
#include<arpa/inet.h>  
#include<errno.h>  
#include<unistd.h>  
  
#include<stdio.h>  
#include<string.h>  
#include<stdlib.h>  
  
#include<event.h>  
#include<event2/util.h>  
  
int tcp_connect_server(const char* server_ip, int port);  
void cmd_msg_cb(int fd, short events, void* arg);  
void socket_read_cb(int fd, short events, void *arg);  
  
int main(int argc, char** argv)  
{
    if( argc < 3 )  
    {  
        printf("please input 2 parameter\n");  
        return -1;  
    }  
  
    //�������������Ƿ������˵�IP��ַ���˿ں�  
    int sockfd = tcp_connect_server(argv[1], atoi(argv[2]));  
    if( sockfd == -1)  
    {  
        perror("tcp_connect error ");  
        return -1;  
    }  
  
    printf("connect to server successful\n");  
  
    struct event_base* base = event_base_new();//��ʼ��
  
    struct event *ev_sockfd = event_new(base, 
										sockfd,  EV_READ | EV_PERSIST,//���������ǲ���
                                        socket_read_cb,//�ص���������������У���������
										NULL);//���Ҳ�ǲ���
	/*
		typedef void (*event_callback_fn)(evutil_socket_t, short, void *);//�ص���������
event_new(struct event_base *base, evutil_socket_t fd, short events, void (*cb)(evutil_socket_t, short, void *), void *arg)
		#define EV_TIMEOUT 0x01 	��ʱ�¼�
		#define EV_READ 0x02 		I/O�¼�
		#define EV_WRITE 0x04 		I/O�¼�
		#define EV_SIGNAL 0x08 		�ź�
		#define EV_PERSIST 0x10 	�����¼�
		#define EV_ET 0x20 			���ش���
	*/
    event_add(ev_sockfd, NULL);  
    /*
	��Ȼ�Ѿ���ʼ�����¼������Ǹ��¼������ᱻ������ԭ���������ǲ�û�м�����¼���
	`event_add`�����ṩ�˼����¼��Ĺ��ܡ�int event_add(struct event *ev, const struct timeval *tv);
	�����һ����non-pending��δע��`ev`������`event_add`������ע����¼�����Ϊpending״̬����
	�����һ����pending��ע�����`ev`�����øú�������tvʱ�������ע����¼����ɹ�����0��ʧ�ܷ���-1��
	*/
    //�����ն������¼�  
    struct event* ev_cmd = event_new(base, STDIN_FILENO,  
                                      EV_READ | EV_PERSIST,
									  cmd_msg_cb, //�ص���������������У�����д��
                                      (void*)&sockfd);  
	/*
		STDIN_FILENO ���Ǳ�׼�����豸��һ���Ǽ��̣����ļ���������
	*/
    event_add(ev_cmd, NULL);  
	
    event_base_dispatch(base);//ѭ������
	
    printf("finished \n");  
    return 0;  
}  
  
void cmd_msg_cb(int fd, short events, void* arg)  
{  
    char msg[1024];  
  
    int ret = read(fd, msg, sizeof(msg));//�Ӽ����϶���ƽʱ������fgets������ 
    if( ret <= 0 )  
    {  
        perror("read fail ");  
        exit(1);
    }
  
    int sockfd = *((int*)arg);  
  
    //���ն˵���Ϣ���͸���������  
    //Ϊ�˼������������дһ�����ݵ����  
    write(sockfd, msg, ret);  
}  
  
  
void socket_read_cb(int fd, short events, void *arg)  
{  
    char msg[1024];  
  
    //Ϊ�˼�����������Ƕ�һ�����ݵ����  
    int len = read(fd, msg, sizeof(msg)-1);  
    if( len <= 0 )  
    {  
        perror("read fail ");  
        exit(1);  
    }  
  
    msg[len] = '\0';  
  
    printf("recv %s", msg);  
}  
  
int tcp_connect_server(const char* server_ip, int port)  
{  
    int sockfd, status, save_errno;  
    struct sockaddr_in server_addr;  
  
    memset(&server_addr, 0, sizeof(server_addr) );  
  
    server_addr.sin_family = AF_INET;  
    server_addr.sin_port = htons(port);  
    status = inet_aton(server_ip, &server_addr.sin_addr);//inet_aton��һ���Ľ��ķ�������һ���ַ���IP��ַת��Ϊһ��32λ����������IP��ַ��
  
    if( status == 0 ) //the server_ip is not valid value  
    {  
        errno = EINVAL;  
        return -1;  
    }
  
    sockfd = ::socket(AF_INET, SOCK_STREAM, 0);  
    if( sockfd == -1 )  
        return sockfd;  
  
  
    status = ::connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr) );  
  
    if( status == -1 )  
    {  
        save_errno = errno;  
        ::close(sockfd);  
        errno = save_errno; //the close may be error  
        return -1;  
    }  
  
    evutil_make_socket_nonblocking(sockfd);  
  
    return sockfd;  
}
/*
evutil_make_socket_nonblocking(evutil_socket_t fd)
{
#ifdef WIN32
	{
		u_long nonblocking = 1;
		if (ioctlsocket(fd, FIONBIO, &nonblocking) == SOCKET_ERROR) {
			event_sock_warn(fd, "fcntl(%d, F_GETFL)", (int)fd);
			return -1;
		}
	}
#else
	{
		int flags;
		if ((flags = fcntl(fd, F_GETFL, NULL)) < 0) {
			event_warn("fcntl(%d, F_GETFL)", fd);
			return -1;
		}
		if (fcntl(fd, F_SETFL, flags | O_NONBLOCK) == -1) {
			event_warn("fcntl(%d, F_SETFL)", fd);
			return -1;
		}
	}
#endif
	return 0;
}

typedef void (*event_callback_fn)(evutil_socket_t, short, void *);//�ص���������
struct event *event_new(struct event_base *base, evutil_socket_t fd, short events, void (*cb)(evutil_socket_t, short, void *), void *arg)
{
	struct event *ev;
	ev = mm_malloc(sizeof(struct event));
	if (ev == NULL)
		return (NULL);
	if (event_assign(ev, base, fd, events, cb, arg) < 0) {
		mm_free(ev);
		return (NULL);
	}
	return (ev);
}



int event_assign(struct event *ev, struct event_base *base, evutil_socket_t fd, short events, void (*callback)(evutil_socket_t, short, void *), void *arg)
{
	if (!base)
		base = current_base;

	_event_debug_assert_not_added(ev);

	ev->ev_base = base;

	ev->ev_callback = callback;
	ev->ev_arg = arg;
	ev->ev_fd = fd;
	ev->ev_events = events;
	ev->ev_res = 0;
	ev->ev_flags = EVLIST_INIT;
	ev->ev_ncalls = 0;
	ev->ev_pncalls = NULL;

	if (events & EV_SIGNAL) {
		if ((events & (EV_READ|EV_WRITE)) != 0) {
			event_warnx("%s: EV_SIGNAL is not compatible with "
			    "EV_READ or EV_WRITE", __func__);
			return -1;
		}
		ev->ev_closure = EV_CLOSURE_SIGNAL;
	} else {
		if (events & EV_PERSIST) {
			evutil_timerclear(&ev->ev_io_timeout);
			ev->ev_closure = EV_CLOSURE_PERSIST;
		} else {
			ev->ev_closure = EV_CLOSURE_NONE;
		}
	}

	min_heap_elem_init(ev);

	if (base != NULL) {
		//Ĭ������£����ǰ��µ��¼������м����ȼ�
		ev->ev_pri = base->nactivequeues / 2;
	}

	_event_debug_note_setup(ev);

	return 0;
}
*/