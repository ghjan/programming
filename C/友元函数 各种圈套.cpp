#include<iostream>
using namespace std;
class crect;
class cpoint
{
public:
	void in(crect &rc,int no);		//������crect ����cpoint ��Ϊcpoint �����˽��Ԫ�� in ����ֱ�ӵ��� 
	cpoint (int x=0,int y=0)
	{
		xp=x;yp=y;
	}
	void print()
	{
		cout<<xp<<"  "<<yp<<endl;
	}
private:
	int xp,yp;
};
class crect
{
	friend void cpoint ::in (crect &rc,int no);
public:
	crect(int x1=0,int y1=0,int x2=0,int y2=0)
	{
		left=x1;
		right=y1;
		top=x2;
		bottom=y2;
	}
	void print()
	{
		cout<<left<<"  "<<top<<"  "<<right<<"  "<<bottom<<endl;
	}
private:
	int left,right,top,bottom;
};
void cpoint::in(crect &rc,int no)
{
	xp+=no;				//ֱ�ӷ����Լ���ĳ�Ա 
	yp+=no;
	rc.left +=no;		//����crect��˽��Ԫ�� 
	rc.right +=no;
	rc.bottom +=no;
	rc.top +=no;
}
int main()
{
	cpoint pt(10,20);
	crect rc(0,0,100,80);
	pt.print ();
	rc.print ();
	pt.in (rc,3);
	pt.print ();
	rc.print();
	return 0;
}
