#include <iostream>
using namespace std;

//��������  = delete;����ɾ��������� 
void show(char a) = delete; //������仰�����Ͳ����� show('A');�� 
void show(int i)
{
	cout<<i<<endl;
}

int main()
{
	//show('A');//����� 65 
	show(1);
}
