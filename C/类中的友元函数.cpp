#include<iostream>
using namespace std;
class cpoint
{
	friend cpoint inflate(cpoint &pt,int noffset);//����һ����Ԫ����
public:
	cpoint(int x=0,int y=0)
	{
		xp=x;yp=y;
	}
	void print()
	{
		cout<<"point("<<xp<<","<<yp<<")"<<endl;
	}
private:
	int xp,yp;
};
cpoint inflate(cpoint &pt,int noffset)			//class�ⲿ   ��Ԫ�����Ķ���
{
	pt.xp +=noffset;							//ֱ�Ӹı�˽�����ݳ�Ա
	pt.yp +=noffset;
	return pt;
}
int main()
{
	cpoint a(10,20);
	a.print ();
	inflate(a,3);							//ֱ�ӵ�����Ԫ����
	a.print ();
	return 0;
}
