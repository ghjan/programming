#include<iostream>
using namespace std;
class cpoint 
{
	friend class cother;//cother ����������к��������Զ� cpoint ��������ж������з��� 
public:
	cpoint(int x=0,int y=0)
	{
		x1=x;y1=y;
	}
private:
	int x1,y1;
	void inflate(int n)
	{
		x1+=n;y1+=n;
	}
	void print()
	{
		cout<<x1<<"  "<<y1<<endl;
	}
};
class cother
{
	cpoint p;
public:
	cother(int a=0,int b=0)
	{
		p.x1=a;p.y1=b;
	}
	void display()
	{
		p.inflate(10);			//ͨ����Ԫ������cpoint �е�inflate ��print�������з��� 
		p.print();
	}
};
int main()
{
	cother one(100,100);
	one.display();
	return 0;
}
	
