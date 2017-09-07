//���������У��ҳ����������ֳ��ֵĴ���
#include <iostream>
#include <cstring>
using namespace std;

int BinarySearch(int a[],int n,int data, bool isLeft)  
{  
    //isLeft���ֵ�Ƿ������  
    if(!a || n<=0)  
        return -1;  
    int begin=0;  
    int end=n-1;  
    int last=-1;  
    while(begin <=end)  
    {  
        int mid=(begin+end)/2;  
        if(a[mid] > data)  
            end=mid-1;  
        else if(a[mid] < data)  
            begin=mid+1;  
        else  
        {  
            last=mid;  
            if(isLeft)  
                end=mid-1;  
            else  
                begin=mid+1;  
        }  
    }  
    return  last;  
}  
  
int main()  
{  
    int a[]={3,3,3,3,3,3,3,3,3,3,3,4,5,6,7,13,19};  
    int len=sizeof(a)/sizeof(a[0]);  
    int index1=BinarySearch(a,len,3,true);//�����ȳ��ֵ�λ��  
    int index2=BinarySearch(a,len,3,false);//�������ֵ�λ��  
    cout << index1 << ' ' << index2 << endl;  
    cout << index2-index1+1 << endl;  
  
}  
