#include "iostream"
using namespace std;
int main(){
    int a=0;
    printf("%d %d %d",a++,a++,a++);//�������ҿ�ʼ��ջ�����ܱ�֤��ջ�Ǵ������ң�a�Ƚ�ջ�ټ�1���ٽ�ջ �ټ�1 �ڽ�ջ�ټ�1
	printf("\n%d\n",a);			   //�������ܽ��� ����� a Ϊʲô3    
    int b=1;
    printf("\n%d %d %d",++b,++b,++b);//��Ϊ�Ӻ�ȫ����ǰ�� ������ִ�м�1 Ȼ���ٽ�ջ  �������������Ķ�һ�� 
    printf("\n%d %d %d %d",++b,++b,++b,++b);//���֤����һ����������ȷ��
    int c=1;
    printf("\n%d %d %d",++c,++c,c++);
    int d=1;
    printf("\n%d %d %d",d++,++d,d++);
    int e=1;
    printf("\n%d %d %d %d",e++,e++,++e,e++);		//��Щ���������ܽ���    ���ϲ����  ��ͬ������  �ó����Ĵ𰸲�һ�� 
    int i = 3;
 printf("\n%d,%d,%d,%d,%d\n",i++,++i,i,i++,i);
 printf("%d\n",i);
    return 0;
}
