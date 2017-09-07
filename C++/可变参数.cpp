#include <iostream>
#include <stdarg.h>  
 using namespace std;
 /* ������� */
int max(int n, ...) {                   // ���� n ��ʾ�����������������ã�����ʱ������
  va_list ap;                            // ����һ�� va_list ָ�������ʲ�����
  va_start(ap, n);                       // ��ʼ�� ap������ָ���һ�����
  int maximum = -0x7FFFFFFF;            // ����һ����С������
  int temp;
  for(int i = 0; i < n; i++) 
  {
    temp = va_arg(ap, int);             // ��ȡһ�� int �Ͳ��������� ap ָ����һ������
    if(maximum < temp) 
		maximum = temp;
  }
  va_end(ap);                            // �ƺ������ر� ap
  return maximum;
}

int main()
{
  cout << max(3, 10, 20, 30) << endl;
  cout << max(6, 20, 40, 10, 50, 30, 40) << endl;
}
