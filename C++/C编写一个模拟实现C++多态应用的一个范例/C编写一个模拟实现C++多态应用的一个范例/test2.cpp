#include <stdio.h>
#include <stdlib.h>


//ģ��һ����A
typedef struct A
{
	void *vptr;//�麯��ָ��
}A;

//ʵ���麯��
void dong1()
{
	printf("����  dong1\n");
}
void dong2()
{
	printf("����  dong2\n");
}

//ģ�����ṹ
typedef struct
{
	void(*v1)();
	void(*v2)();
}Vtable;

//ģ��һ�����е����
Vtable A_Vtable = { &dong1, &dong2 };//�������⣺��a����Ե���dong1  dong2 ������������

//ģ��A��Ĺ��캯��
void initA(A *p)//��һ����thisָ�룬��c++��Ҳ��Ĭ�ϴ�һ��thisָ��
{
	p->vptr = &A_Vtable;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

//ģ�������� B
typedef struct B
{
	A a;//*****************���Ǳ���ġ������ܸ�A��ָ���ʼ��������Ϊ��BǿתΪA֮���ܲ���A�е�ָ��
	//�������壬Ҳ�൱����B��Ҳ����һ��void *p ������
}B;
//ģ����������麯��
void dong11()//ģ�⸲��dong1�������
{
	printf("������  dong11\n");
}
void dong66()
{
	printf("������  dong66\n");
}
//ģ���������������һ������dong66
typedef struct
{
	Vtable vtable;
	void(*p)();
}Vtable2;

//��������
Vtable2 B_vtable = { { &dong11, &dong2 }, &dong66 };//ע�����������һ��������  //��b����Ե���dong11  dong2 dong66 ������������

//B�๹�캯��
void initB(B* p)//ΪʲôҪa�����أ���ʼ������
{
	p->a.vptr = &B_vtable;		//����������B���Լ������һ����һ�����
}

///////////////////////////////////////////////////////////////////////////////////////////////////

//����һ��B��
void test2()
{
	//����B��
	B *b = (B*)malloc(sizeof(B));
	initB(b);

	printf("%d\n", b);
	printf("%d\n", b->a);
	printf("%d\n", b->a.vptr);
	printf("%d\n", ((A*)b)->vptr);
	A* a = (A*)b;
	printf("%d\n", a->vptr);
	/*
	11961744
	20217864
	20217864
	20217864
	11961744
	*/

	

}

int main()
{
	test2();
	system("pause");
	return 0;
}

//#include <iostream>
//using namespace std;
//
//class A{};
//class B :public A{};
//class C
//{
//	A a;
//	B b;
//};
//int main()
//{
//	cout << sizeof(A) << endl;
//	cout << sizeof(B) << endl;
//	cout << sizeof(C) << endl;
//	system("pause");
//}

/*
ͨ������



*/