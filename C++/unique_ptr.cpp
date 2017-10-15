#include <iostream>
#include <vector>
#include <memory>//����ָ�������ͷ�ļ��� 
using namespace std;

class A{
public:
	int a; 
	A(){cout<<"A"<<endl;}
	~A(){cout<<"~A"<<endl;}
};

void test1(){
	unique_ptr<int> up(new int(4));
//	int *p2 = up;	���ܸ�ֵ 
	int *p1 = up.release(); //�����ͷ�����Ȩ  �� ���Ը�ֵ  
}
void test2(){
	unique_ptr<A> u_s(new A);  
	u_s=nullptr;//��ʽ������ָ����ͬʱ����ָ���Ϊ��ָ�롣��u_s.reset()�ȼ�  
	cout<<"test2"<<endl;
}
/*
A
~A
test2
*/
void test3(){
	unique_ptr<A> u_s(new A); 
	unique_ptr<A> u_s2 = std::move(u_s); //����Ȩת��(ͨ���ƶ�����)��u_s����Ȩת�ƺ󣬱�ɡ���ָ�롱 �����ǲ����� 
	cout<<"test3"<<endl;
//	u_s->a = 1;	�Ѿ���ΪNULL�� 
}
/*
A
test3
~A
*/
unique_ptr<A> test4(){
	unique_ptr<A> up(new A); 
	return up;//�Զ�����move���� 
}
void test5(){
	cout<<"test5"<<endl;
	unique_ptr<A> u_a = test4();
}
/*
test5
A
~A
*/ 
void test6(){
	unique_ptr<A[]> up(new A[2]); //unique_ptr����ָ������  Ĭ��������delete �� delete[] 
}
//�ɷ���������(�ֲ���auto_ptr������Ϊ����Ԫ�ص�ȱ��)
void test7(){
	vector<unique_ptr<A>>v;  
	unique_ptr<A> p1(new A);  
	v.push_back(std::move(p1));//������Ҫ��move���� 
}
int main(){
//	test2();
//	test3();
//	test5();
//	test6();
	test7();
} 
