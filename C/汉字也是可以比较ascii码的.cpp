#include <iostream> 
using namespace std;

int main()
{
	char a[] = "��";
	char b[] = "��";
	char c[] = "��";
	
	if(a[0]<b[0])
	{
		cout<<b<<" ���� "<<a<<endl;
	}
	
	if(c[0]>b[0])
	{
		cout<<c<<" ���� "<<b<<endl;
	}
	
	if(a[0]<c[0])
	{
		cout<<c<<" ���� "<<a<<endl;
	}

	
}
