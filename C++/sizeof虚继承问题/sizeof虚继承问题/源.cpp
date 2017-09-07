#include<iostream>
#include <cstdlib>
using namespace std;

class  A
{
	//int a;
	virtual void fun();
};
class B :virtual public A
{
	int b;
	virtual void fun();
};//12
/*
        +---
 0      | {vbptr}
 4      | b
        +---
        +--- (virtual base A)
 8      | {vfptr}
        +---
*/
class  C
{
	int a;
	virtual void fun();
};
class D :virtual public C
{
	int b;
	virtual void fun();
};//16
/*
        +---
 0      | {vbptr}
 4      | b
        +---
        +--- (virtual base C)
 8      | {vfptr}
12      | a
        +---
*/
////////////////////////////////////////////////////////////////////////////
class  E
{
	int a;
	int b;
	virtual void fun();
};
class F : virtual public E
{
	int b;
	virtual void fun();
};//20
/*
        +---
 0      | {vbptr}
 4      | b
        +---
        +--- (virtual base E)
 8      | {vfptr}
12      | a
16      | b
        +---
*/
////////////////////////////////////////////////////////////////////////////
class  G
{
	int a;
	virtual void fun();
};
class H : virtual public G
{
	int b;
	virtual void fun22();
};//20
/*
        +---
 0      | {vfptr}					//�Լ������
 4      | {vbptr}
 8      | b
        +---
        +--- (virtual base G)
12      | {vfptr}					//��������
16      | a
        +---
*/
/////////////////////////////////////////////////////////////////////////
class  I
{
	double a;
	virtual void fun();
};
class J : public I
{
	int b;
	virtual void fun22();
};//24
//ע��ÿ�����struct�ṹ��һ�������ֽڶ��� �����Կ�������ָ��ռ��8���ֽ�
/*
        +---
        | +--- (base class I)
 0      | | {vfptr}							//�̳и�������
 8      | | a
        | +---
16      | b
        | <alignment member> (size=4)
        +---
*/
class  K
{
	double a;
	virtual void fun();
};
class L : public K
{
	int b;
	virtual void fun();			//���ܺ͸����麯���Ƿ�һ������
};//24
/*
        +---
        | +--- (base class K)
 0      | | {vfptr}
 8      | | a
        | +---
16      | b
        | <alignment member> (size=4)
        +---
*/
class  M
{
	int a;
	virtual void fun();
};
class N : public M
{
	int a;
	virtual void fun();
};//8
/*
        +---
        | +--- (base class M)
 0      | | {vfptr}
 4      | | a
        | +---
 8      | a
        +---
*/
class  O
{
	int a;
};
class P : virtual public O
{
	int a;
};
class R : virtual public O
{
	int a;
};
class S : public P, public R
{
	int a;
};//24
/*
        +---
        | +--- (base class P)
 0      | | {vbptr}
 4      | | a
        | +---
        | +--- (base class R)
 8      | | {vbptr}
12      | | a
        | +---
16      | a
        +---
        +--- (virtual base O)
20      | a
        +---
*/
int main()
{
	cout << sizeof(B) << endl;
	cout << sizeof(D) << endl;
	cout << sizeof(F) << endl;
	cout << sizeof(H) << endl;
	cout << sizeof(J) << endl;
	cout << sizeof(L) << endl;
	cout << sizeof(M) << endl;
	cout << sizeof(S) << endl;
	getchar();
}