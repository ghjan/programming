#include <iostream>
#incluce <string>
using namespace std;

class Student
{
public:
	Student(int num,string name,string sex,string birth,int age,int math,int english,int pe)
	:num(num),name(name),sex(sex),birth(birth),age(age),math(math),english(english),pe(pe){}
	virtual void display() = 0;
protected:
	int num;
	string name;
	string sex;
	int math;
	int english;
	int pe;
	string birth;
	int age;
protected:
	void display_sys()
	{
		cout<<"ѧ��:\t"<<num<<endl; 
		cout<<"����:\t"<<name<<endl;
		cout<<"�Ա�:\t"<<sex<<endl;
		cout<<"����:\t"<<birth<<endl;
		cout<<"����:\t"<<age<<endl;
		cout<<"��ѧ�ɼ�:\t"<<math<<endl;
		cout<<"Ӣ��ɼ�:\t"<<english<<endl;
		cout<<"�����ɼ�:\t"<<pe<<endl;
	}
};
class Undergraduate
{
public:
	Undergraduate(int num,string name,string sex,string birth,int age,int math,int english,int pe,string direction)
	:num(num),name(name),sex(sex),birth(birth),age(age),math(math),english(english),pe(pe),major(major){}
public:
	string major;
	void display()
	{
		display_sys();
		cout<<"רҵ:\t"<<major<<endl;
	}
};
class Graduate
{
public:
	Graduate(int num,string name,string sex,string birth,int age,int math,int english,int pe,string direction)
	:num(num),name(name),sex(sex),birth(birth),age(age),math(math),english(english),pe(pe),direction(direction){}
	void dispaly()
	{
		display_sys();
		cout<<"�о�����:\t"<<direction<<endl;
	}
private:
	string direction;
};

int main()
{
	
}
