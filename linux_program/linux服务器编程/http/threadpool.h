#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <list>
#include <cstdio>
#include <exception>
#include <pthread.h>
#include "locker.h"

template< typename T >
class threadpool
{
public:
    threadpool( int thread_number = 8, int max_requests = 10000 );
    ~threadpool();
    bool append( T* request );

private:
    static void* worker( void* arg );
    void run();

private:
	/*����߳���*/
    int m_thread_number;
	/*���������*/
    int m_max_requests;
	/*���й�����������*/
    std::list< T* > m_workqueue;
	/*������*/
    locker m_queuelocker;
	/*�ź���*/
    sem m_queuestat;
    pthread_t* m_threads;//typedef unsigned long int pthread_t;
    bool m_stop;
};

template< typename T >
threadpool< T >::threadpool( int thread_number, int max_requests ) : 
        m_thread_number( thread_number ), m_max_requests( max_requests ), m_stop( false ), m_threads( NULL )
{
    if( ( thread_number <= 0 ) || ( max_requests <= 0 ) )
    {
        throw std::exception();
    }

    m_threads = new pthread_t[ m_thread_number ];//�൱������ m_thread_number ���߳�id
    if( ! m_threads )
    {
        throw std::exception();
    }
	/*�����̳߳�*/
    for ( int i = 0; i < thread_number; ++i )
    {
        printf( "create the %dth thread\n", i );
        if( pthread_create( m_threads + i, NULL, worker, this ) != 0 )
        {
            delete [] m_threads;
            throw std::exception();
        }
        if( pthread_detach( m_threads[i] ) )//���߳����н�������Զ��ͷ�������Դ
        {
            delete [] m_threads;
            throw std::exception();
        }
    }
}

template< typename T >
threadpool< T >::~threadpool()
{
    delete [] m_threads;
    m_stop = true;
}

/*���ź������мӲ��� �� ����������м�����*/
template< typename T >
bool threadpool< T >::append( T* request )
{
	/*��������������Ҫ����*/
    m_queuelocker.lock();
    if ( m_workqueue.size() > m_max_requests )//�жϵ�ǰ���������Ƿ�ﵽ���
    {
        m_queuelocker.unlock();
        return false;
    }
    m_workqueue.push_back( request );
    m_queuelocker.unlock();
    m_queuestat.post();//�ź���+1
    return true;
}

/*�������̶߳����⿪ʼ����*/
template< typename T >
void* threadpool< T >::worker( void* arg )
{
    threadpool* pool = ( threadpool* )arg;
    pool->run();
    return pool;
}

template< typename T >
void threadpool< T >::run()
{
    while ( ! m_stop )
    {
		/*ֻҪ�߳��ܵ��⣬�ź�����-1 , ����ź���Ϊ0���������⣬˵��û��������*/
        m_queuestat.wait();
		/*��ȡ������Ҫ���������ܶ���̻߳�ȡͬһ������*/
        m_queuelocker.lock();
        if ( m_workqueue.empty() )
        {
            m_queuelocker.unlock();
            continue;
        }
        T* request = m_workqueue.front();//ȡ������еĵ�һ��
        m_workqueue.pop_front();
        m_queuelocker.unlock();
        if ( ! request )//����Ϊ��
        {
            continue;
        }
        request->process();//����user��process������Ҳ���ǵ���http_conn.cpp�����process
    }
}

#endif
/*
����һ���߳�Ĭ�ϵ�״̬��joinable, ���һ���߳̽������е�û�б�join,������״̬�����ڽ����е�Zombie Process,
������һ������Դû�б����գ��˳�״̬�룩�����Դ����߳���Ӧ��pthread_join���ȴ��߳����н��������ɵõ��̵߳��˳����룬��������Դ��������wait,waitpid)
���ǵ���pthread_join(pthread_id)��������߳�û�����н����������߻ᱻ����������Щ��������ǲ���ϣ����ˣ�
������Web�������е����߳�Ϊÿ�����������Ӵ���һ�����߳̽��д����ʱ�����̲߳���ϣ����Ϊ����pthread_join����������Ϊ��Ҫ��������֮���������ӣ���
��ʱ���������߳��м������
pthread_detach(pthread_self())
���߸��̵߳���
pthread_detach(thread_id)�������������������أ�
�⽫�����̵߳�״̬����Ϊdetached,����߳����н�������Զ��ͷ�������Դ��
*/
