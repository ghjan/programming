#include <stdio.h>
#define dong printf("nice to see you\n")
/* �ж����� */
#ifdef DEBUG_PRINT					//���֮ǰ�������� 
#define MyPrint printf("hello\n")	// ��ô 
#else								// û�ж��� 
#define MyPrint					// �� ����Ϊ�� 
#endif
#ifdef dong					//���֮ǰ�������� 
#define dong printf("dong\n")	// ��ô 
#endif

// main����
int main()
{
MyPrint;
dong;
return 0;
}
