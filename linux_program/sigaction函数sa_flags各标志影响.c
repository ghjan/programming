#include <signal.h>
#include <stdio.h>
#include <setjmp.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
void sig_init(int signal)
{
	printf("hello signal %d\n",signal);
}

int main()
{
	struct sigaction sigact;
	
	sigact.sa_handler = sig_init;
	
	//sigact.sa_flags = 0;//��������Կ�����read���ñ��жϺ�û����������\
						��˵���ҵ�ϵͳĬ�Ͼ��� �Ա��жϵ�ϵͳ���ò����Զ�������
	sigact.sa_flags |= SA_RESTART;//ʹ���� SA_RESTART��־�� read���ñ��жϺ� ���Զ����� �����ȴ��ж����롣
	if(sigaction(SIGINT,&sigact,NULL) == -1)
	{
		perror("sigacion");
		return 0;
	}
	char c;
	read(0,&c,1);
	printf("read:%c\n",c);
	return 0;
}
/*



*/