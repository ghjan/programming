#include <iostream>
using namespace std; 

template<class T>//������� ����T ģ�壬���������ǲ��ܵ��ø��࣬������ֻҪ�������࣬�������ǲ���ȥ������е����ݵ� 
class A{
	public:
		A(T a){
			this->a = a;
		}
		T a; 
};

class B:public A<int>{		//�̳е�ʱ��Ҳ������ϡ�ģ���βΡ�
	public:
		B(int a,int b):A(a){ //�ڼ̳е�ʱ������� ��ģ���βΡ� ����Ϳ��Բ����� 
			this->b = b;
		}
		int b;
}; 

void showA(A<int> a)//������������ȥ��ʱ��Ҳ������ϡ�ģ���βΡ�
{
	cout<<a.a<<endl;
}

int main1()
{
	//cout<<sizeof(A)<<endl; ����Ҳ���ñ�����ȥ������еĳ�Ա 
	A<int> a(1); //���������ʱ��  ������ϡ�ģ���βΡ�  ��Ȼ��������֪�������ж��
	
	showA(a);
}

int main()
{
	B b(4123,2);
	showA(b);
} 
