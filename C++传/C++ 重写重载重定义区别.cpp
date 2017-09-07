//��дoverride��Ҳ�������ǡ��������¶��常��������ͬ���ƺͲ������麯��������������ͬ�����Ǿ���ʵ�ֲ�ͬ����Ҫ���ڼ̳й�ϵ�г��ֵ� ��
//��д��Ҫע�⣺
//1 ����д�ĺ���������static�ġ�������virtual��
//2 ��д������������ͬ�����ͣ����ƺͲ����б�
//3 ��д�����ķ������η����Բ�ͬ������virtual��private�ģ�����������д��дΪpublic,protectedҲ�ǿ��Ե�
//
//�ض��� (redefining)Ҳ��������:
//
//�������¶��常��������ͬ���Ƶķ��麯�� ( �����б���Բ�ͬ ) ��
//
//���һ���࣬���ں͸�����ͬ�ĺ�������ô������ཫ�Ḳ���丸��ķ������������ڵ��õ�ʱ��ǿ��ת��Ϊ�������ͣ�������ͼ������͸������������صĵ����ǲ��ܳɹ��ġ� 
#include <iostream> 
using namespace std;
//���� 
class Base {
 virtual void display() { cout<<"Base display()"<<endl; }
 void say(){ cout<<"Base say()"<<endl; }
public:
 void exec(){ display(); say(); }
 virtual void f1(string a) { cout<<"Base f1(string)"<<endl; }
 void f1(int a) { cout<<"Base f1(int)"<<endl; } //overload������f1������Base����ڲ�������
};
//A
class DeriveA:public Base{
public:
 void display() { cout<<"DeriveA display()"<<endl; } //override��������displayΪ�麯�����ʴ˴�Ϊ��д
 void f1(int a,int b) { cout<<"DeriveA f1(int,int)"<<endl; } //redefining��f1������Base���в�Ϊ�麯�����ʴ˴�Ϊ�ض���
 void say() { cout<<"DeriveA say()"<<endl; } //redefining��ͬ��
};
//B
class DeriveB:public Base
{
public:
	void f1(int a) { cout<<"DeriveB f1(int)"<<endl; } //redefining���ض���]
	void f1(string a){ cout<<"DeriveB f1(string)"<<endl; }
};

int main()
{
	DeriveB b;
 	Base *base=&b;
 	
 	b.f1(1);	
 	//DeriveB f1(int)		
 	base->f1(1);
 	//Base f1(int)			//���ࡰ�ض��塱�˸���ķ���������ķ���ֻ�Ǳ������ˡ���ǿ������ת��Ϊ���࣬���õ���Ȼ�ǻ���ķ���
 
 	
	b.f1("1");
	//DeriveB f1(string)	
	base->f1("1"); 			
	//DeriveB f1(string)	//���ࡰ���ء��˸���ķ���������ķ������ı��ˡ���ǿ������ת��Ϊ���࣬���õ���Ȼ�ǻ���ķ���
}

int main1(){
 DeriveA a;
 Base *base=&a;
 base->exec();
// DeriveA display()
// Base say() 
 // base��ߵĺ���display��A�า�ǣ�����say�����Լ��ġ�A��ֻ�� �ض���(����)�˻���ķ��� 
 a.exec(); //same result as last statement���� 
 // DeriveA display()
// Base say()

 a.say();
 // DeriveA say()
 
 DeriveB b;
 b.f1(1); //version of DeriveB called
// DeriveB f1(int)
}
// �����������ܽ����£�
//1 ��Ա���������ء�������
//   a ��ͬ�ķ�Χ����ͬһ�����У�
//   b ����������ͬ
//   c ������ͬ
//   d virtual�ؼ��ֿ��п���
//2 ����д��������)��ָ�����ຯ�����ǻ��ຯ���������ǣ�����ǿ��ת��Ϊ����ʱ�����ܵ��û���ĺ�����ֻ�ܵ��ñ���д�ĺ�����
//   a ��ͬ�ķ�Χ���ֱ�λ�ڻ������������
//   b ������������ͬ
//   c ������ͬ
//   d ���ຯ��������virtual�ؼ���
//3 �ض���(����)��ָ������ĺ�������������ͬ���Ļ��ຯ�����������£�
//   a ���������ĺ����ͻ���ĺ���ͬ�������ǲ�����ͬ����ʱ����������virtual������ĺ��������ء�����ǿ��ת��Ϊ����ʱ�����ܵ��û���ĺ����� 
//   b ���������ĺ��������ĺ���ͬ�������Ҳ���Ҳ��ͬ�����ǻ��ຯ��û��vitual�ؼ��֣���ʱ������ĺ��������ء�
