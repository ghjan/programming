#include <iostream>
#include <cstring>
using namespace std;

//��ƽ����������ȡ�� 
int main() 
{
	int arr[] = {4,4,3};
	int n = sizeof(arr)/sizeof(arr[0]); 
	double res = (double)(arr[0] + arr[1] + arr[2]) / n;
	int res2 = (arr[0] + arr[1] + arr[2]) / n;
	
	cout<<res<<endl;
	cout<<res2<<endl;
    
    ////////////���治��զŪ���о��������������Լ������ǽ�ȥ������������һ�ֺ÷���//////////////////
    int res3 = (arr[0] + arr[1] + arr[2] + n - 1) / n;
    cout<<res3<<endl;
    
    double i = 5.546375;
    printf("%.5f\n",i);//��������Ļ�   .5f   �Զ��������� 
    
    return 0;
}

