#include<iostream>
using namespace std;
#include <stdio.h>
#include <string>

int main()
{
	char e;
	while(e!=EOF)
	{
		e = getchar();
		cout<<e;
	}
	cout<<"dong";
 }
int  main2()
{
    int ch;
    do{
        ch=getchar();
        printf("ch=%d\n", ch ); //��������ص�chֵ������EOF�����-1
    } while ( ch!=EOF );
}
int main3()
{
	int a[10];
	while(scanf("%d",a)!=EOF)
	{
		printf("a = %d\n",a);
	}
}
int main4()
{
	cout<<EOF<<endl;
 } 
/*
EOF �Ǹ��꣬����˼�ǣ�End Of File���ļ�β��־�� ����ֵ����������������-1
��C���Ե�ͷ�ļ��ж�������˺궨�壺
stdio.h:    # define EOF (-1)
�����ļ�����ʱ�������ļ�����λ�û�����ݳ�����᷵�� EOF�� ��C���������е���������������ǰ����ļ���˼������Ƶģ�
����˵�����ļ�������һ����������getchar��������fgetc(stdin) ��һ���� ��
int getchar() ; //�ӱ�׼���뻺������ȡһ���ַ����ɹ����ظ��ַ���ASCIIֵ����������EOF
��ô������ڼ�������ʱ������EOF�أ� ��ͬ��ϵͳ������ͬ��
linuxϵͳ�£�������س����к�Ŀ���λ�ã��� ctrl+d (�Ȱ�ctrl�������ţ��ٰ�d����
windowsϵͳ�£�������س����к�Ŀ���λ�ã��� ctrl+z���ٻس�ȷ��
���´��빩�ο���
#include <stdio.h>
void main()
{
    int ch;
    do {
        ch=getchar();
        printf("ch=%d\n", ch ); //��������ص�chֵ������EOF�����-1
    } while ( ch!=EOF );
}
*/
