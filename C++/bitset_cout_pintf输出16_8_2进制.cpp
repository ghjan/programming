// ��MoreWindows�����ʼ�3�� ʹ��cout/pintf���16���ƣ�8���ƣ�2��������
#include <iostream>
#include <bitset>
#include <stdlib.h>
using namespace std;
int main()
{
  printf(" ��MoreWindows�����ʼ�3�� ʹ��cout/pintf���16���ƣ�8���ƣ�2��������\n");    
  printf(" - http://blog.csdn.net/morewindows/article/details/16358511 -\n");
  printf(" -- By MoreWindows( http://blog.csdn.net/MoreWindows ) --\n\n");

  int a = 100;
  cout<<"ʮ����    "<<a<<endl;
  cout<<"ʮ������  "<<hex<<a<<endl;
  cout<<"�˽���    "<<oct<<a<<endl;
  cout<<"������    "<<bitset<8>(a)<<"   "<<bitset<32>(a)<<endl;  // ����ʹ����bitset�������2��������	�������������

  cout<<"--------------------------------"<<endl;

  printf("ʮ����    %d\n", a);
  printf("ʮ������  %x\n", a);
  printf("�˽���    %o\n", a);
  char binary_text[100];
  itoa(a, binary_text, 2);					//������������� 
  printf("������    %s\n", binary_text); 
  return 0;
}
