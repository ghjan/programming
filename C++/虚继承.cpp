#include <iostream>
using namespace std;  

int gFlag = 0;  

class Base  
{
public:  
Base(){cout << "Base called : " << gFlag++ << endl;}  
void print(){cout << "Base print" <<endl;}  
};

class Mid1 : virtual public Base  						//��̳� 
{
public:  
Mid1(){cout << "Mid1 called" << endl;}  
private:  
};

class Mid2 : virtual public Base  						// ��̳� 
{
public:  
Mid2(){cout << "Mid2 called" << endl;}  
};

class Child:public Mid1, public Mid2  					// ���ﲻ����̳�Ҳ�� 
{
public:  
Child(){cout << "Child called" << endl;}  
};

int main(int argc, char* argv[])  
{
Child d;

//�����������ʹ��  
d.print();

//Ҳ��������ʹ��  
d.Mid1::print();
d.Mid2::print();

system("pause");  
return 0;  
}
