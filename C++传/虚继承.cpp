//C++������̳еĸ���
//Ϊ�˽���Ӳ�ͬ;���̳�����ͬ�������ݳ�Ա���ڴ����в�ͬ�Ŀ���������ݲ�һ�����⣬
//����ͬ��������Ϊ����ࡣ��ʱ�Ӳ�ͬ��·���̳й�����ͬ�����ݳ�Ա���ڴ��о�ֻ��һ��������
//ͬһ��������Ҳֻ��һ��ӳ�䡣���������ͽ���˶��������⣬Ҳ��ʡ���ڴ棬���������ݲ�һ�µ����⡣

//-----------------------------------------------------
//���ƣ�blog_virtual_inherit.cpp 
//˵����C++����̳�ѧϰ��ʾ 
//������VS2005 
//blog��pppboy.blog.163.com 
//---------------------------------------------------- 
#include <iostream>
using namespace std;

class dong{
	public:
	void print(){cout << "dong  dong" <<endl;}
};

 //Base 
 class Base:virtual public dong
 {
 };

 //Sub 
 class Sub:virtual public dong //��̳�dong 
 {
 };

 //Child 
 class Child : public Base , public Sub //��̳�dong
 {
 };

class Child2:public Base,public Sub{
};

 int main(int argc, char* argv[])
 {
 Child c;

 //��������ʹ�ã�����������ԣ�VC��error C2385 
 //c.print();  

 //ֻ������ʹ�� 
 c.Base::print();
 c.Sub::print();
 
 cout<<"------------------"<<endl;
 
 Child2 cc;
 cc.print();//����Ϳ���ֱ�ӵ��� 

 system("pause");
 return 0;
 }
