#include <iostream>
using namespace std;

class Test2{
public:
	Test2()
	{
		cout<<"���캯��"<<endl; 
	}
	void show()
	{
		cout<<"��"<<endl;
	}
	~Test2()
	{
		cout<<"��������"<<endl; 
	}
};

int main()
{    
    Test2().show();//��仰ִ���ꡣ�͵����������� 
    
    cout<<"��������������������"<<endl;
    /*
	���캯��
	��
	��������
	��������������������
	*/ 
    
    return 0;
}
