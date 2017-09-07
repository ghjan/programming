#ifndef HTTPCONNECTION_H
#define HTTPCONNECTION_H

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <sys/stat.h>
#include <string.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <stdarg.h>
#include <errno.h>
#include "locker.h"

class http_conn
{
public:
	/*�ļ�����󳤶�*/
    static const int FILENAME_LEN = 200;
	/*��д��������С*/
    static const int READ_BUFFER_SIZE = 2048;
    static const int WRITE_BUFFER_SIZE = 1024;
	/*��������*/
    enum METHOD { GET = 0, POST, HEAD, PUT, DELETE, TRACE, OPTIONS, CONNECT, PATCH };
    enum CHECK_STATE { CHECK_STATE_REQUESTLINE = 0, CHECK_STATE_HEADER, CHECK_STATE_CONTENT };//��״̬�������ڷ��������У����ڷ���ͷ���ֶΣ�����
    enum HTTP_CODE { NO_REQUEST, //������������Ҫ�������ͻ�����
					GET_REQUEST, //�õ�һ�������Ŀͻ�����
					BAD_REQUEST, //�����﷨����
					NO_RESOURCE, //û����Դ
					FORBIDDEN_REQUEST, //�ͻ��˶���Դû���㹻�ķ���Ȩ��
					FILE_REQUEST, //�ļ�����
					INTERNAL_ERROR, //�������ڲ�����
					CLOSED_CONNECTION /*�ͻ��˹ر�����*/};
    enum LINE_STATUS { LINE_OK = 0, LINE_BAD, LINE_OPEN };//��״̬������ȡ״̬��1.���������� 2.�г��� 3.���ݲ�����

public:
    http_conn(){}
    ~http_conn(){}
public:
    void init( int sockfd, const sockaddr_in& addr );
    void close_conn( bool real_close = true );
	/*����ͻ�����*/
    void process();
	/*��������д*/
    bool read();
    bool write();

private:
    void init();
	/*���HTTPӦ��*/
    bool process_write( HTTP_CODE ret );

	/*����http����*/
    HTTP_CODE process_read();
    HTTP_CODE parse_request_line( char* text );
    HTTP_CODE parse_headers( char* text );
    HTTP_CODE parse_content( char* text );
    HTTP_CODE do_request();
    char* get_line() { return m_read_buf + m_start_line; }
    LINE_STATUS parse_line();

    void unmap();
    bool add_response( const char* format, ... );
    bool add_content( const char* content );
    bool add_status_line( int status, const char* title );
    bool add_headers( int content_length );
    bool add_content_length( int content_length );
    bool add_linger();
    bool add_blank_line();

public:
    static int m_epollfd;
	/*ͳ���û�����*/
    static int m_user_count;

private:
    int m_sockfd;
    sockaddr_in m_address;
	/*��������*/
    char m_read_buf[ READ_BUFFER_SIZE ];
	/*����λ��(���һ���ֽڵ���һ��λ��)*/
    int m_read_idx;
	/*���ڷ������ַ����ڶ�ȡ�������е�λ��*/
    int m_checked_idx;
	/*���ڽ������е���ʼλ��*/
    int m_start_line;
	/*д������*/
    char m_write_buf[ WRITE_BUFFER_SIZE ];
    int m_write_idx;
	
	/*��״̬����ǰ������״̬*/
    CHECK_STATE m_check_state;
    METHOD m_method;
	/*�����Ŀ���ļ�·��*/
    char m_real_file[ FILENAME_LEN ];
	/*�ļ���*/
    char* m_url;
	/*httpЭ���*/
    char* m_version;
	/*������*/
    char* m_host;
	/*������Ϣ�峤��*/
    int m_content_length;
	/*http�Ƿ񱣳�����*/
    bool m_linger;

	/*�ͻ������Ŀ���ļ���mmap���ڴ��е���ʼλ��*/
    char* m_file_address;
    /*Ŀ���ļ�״̬���Ƿ���Ŀ¼���Ƿ�ɶ����ļ���С*/
	struct stat m_file_stat;
    /*����writev��д*/
	struct iovec m_iv[2];
	int m_iv_count;
};

#endif
