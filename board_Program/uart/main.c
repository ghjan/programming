#include "serial.h"
#include "s3c24xx.h"

int main()
{
    uart0_init();   // ������115200��8N1(8������λ����У��λ��1��ֹͣλ)

	GPBCON|=(1<<2*5);
	GPBDAT=0;
	char *a="\n\r\n\rwelcome to my board\n������\n\r";
	while(*a)
	{
		putcs(*a++);
	}
	while(1)
	{
	char b[20];
	int i=0;
	while(1)
	{
		b[i]=getcs();
		putcs(b[i]);
		if(b[i]=='\n')
			break;
		i++;
	}
	putcs('\n');
		putcs('a');
	putcs('\n');

	i=0;
	while(1)
	{
		if(b[i]=='\n')
			break;
		putcs(b[i]);
		i++;
	}
	}
	
    return 0;
}
