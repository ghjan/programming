#include<stdio.h>
int main()
{
	int z,b,c,d,other;
	while((z=getchar())!='\n')
	{
		if((z>='a'&&z<='z')||(z>='A'&&'Z')) b++;
		else if(z==' ') c++;			/*���������س���Ҳ�����ˡ� ����*/ 
		else if(z>='0'&&z<='9') d++;
		else other++;
	}
	printf("��ĸ����%d\t�ո�%d\t����%d\t����%d",b,c-1,d,other);
 } 
