#include <iostream>
using namespace std; 


int main1()
{
	int a = 10;
	int aa = 100;
	const int b = a;//c++�������������κ��Ż�������Ϊa�Ǳ���
	
	cout<<b<<endl;
	a = 20;
	cout<<b<<endl;
	
	int* p = (int*)&b;
	*p = 20;
	cout<<b<<endl; 
	return 0;
}

int main()  
{  
    const volatile int i = 10;  //volatile�������ǣ� ��Ϊָ��ؼ��֣�ȷ������ָ�������������Ż���ʡ�ԣ���Ҫ��ÿ��ֱ�Ӷ�ֵ.
    int* pi = (int*)(&i);  
    *pi = 100;  
    printf("*pi: %d\n",*pi);  
    printf("i: %d\n",i);  
    printf("pi: %p\n",pi);  
    printf("&i: %p\n", &i);  
    return 0;  
}  
