
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <signal.h>


//��ʾ�źŴӲ������ִ����������
//�źŵ������ͽ�������ۺ�ʵ��

#define ERR_EXIT(m) \
	do \
	{ \
		perror(m); \
		exit(EXIT_FAILURE); \
	} while(0)

void handler(int sig)
{
	if (sig == SIGINT)
	{
		printf("recv a sig=%d\n", sig);
		printf("\n\n\n");
		//fflush(stdout);
	}
	else if (sig == SIGQUIT)//ctr + \ ��������  SIGINT �ź�
	{
		sigset_t uset;
		sigemptyset(&uset);						//�ź�λ���
		sigaddset(&uset, SIGINT);				//��SIGINT�ź�λ��1
		
		sigprocmask(SIG_UNBLOCK, &uset, NULL);	//�������
		//signal(SIGINT, SIG_DFL) ;
	}
}

void printsigset(sigset_t *set)
{
	int i;
	for (i=1; i<NSIG; ++i)
	{
		if (sigismember(set, i))
			putchar('1');
		else
			putchar('0');
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	sigset_t pset; //������ӡ���źż�
	sigset_t bset; //���������������źż�
	
	sigemptyset(&bset);
	sigaddset(&bset, SIGINT);//SIGINT==2  �ź�λ������Ϊ1
	
	if (signal(SIGINT, handler) == SIG_ERR)//�������Ǹ�����ctrl+c���źŴ����ܣ����Ե�ʱ����򲢲����˳�
		ERR_EXIT("signal error");		//ÿ�����ǰ���ctrl+cʱ�ͻ��ӡrecv a sig=2
		
	if (signal(SIGQUIT, handler ) == SIG_ERR)
		ERR_EXIT("signal error");

	//ctrl+c�źű����ó���������ʹ�û�����ctl+c���̣�Ҳ����ִ�
	sigprocmask(SIG_BLOCK, &bset, NULL);
	
	//��Ҫ����������ź�λ���Ի��ˣ�û���������ѭ��������ʵ���ܺܺõ���֤��ֻ�����ǿ������ź�λ�ı仯����
	for (;;)
	{
		sigpending(&pset);//��ȡδ�� ����Ϣ
		printsigset(&pset);//��ӡ�ź�δ��  sigset_t��
		sleep(1);
	}
	return 0;
}
//����֮�����ǰ���ctrl+c֮��û���������recv a sig=2�����ǵ����ǰ���ctrl+\ �ų�����
//��Ϊhandler�����ǽ����SIGINT������


