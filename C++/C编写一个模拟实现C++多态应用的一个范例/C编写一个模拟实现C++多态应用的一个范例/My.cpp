#include <stdio.h>
#include <stdlib.h>


//ģ��һ����A
typedef struct A
{
	void *vptr;//�麯��ָ��

	//�������ݿ���ɾ����д�ϵ�Ŀ�ģ�������һ����
	int a;//��Ա����
	int b;
	void initA(A *p, int a, int b);
	void dong1();//�麯��
	void dong2();
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
void initA(A *p, int a, int b)//��һ����thisָ�룬��c++��Ҳ��Ĭ�ϴ�һ��thisָ��
{
	p->vptr = &A_Vtable;
	p->a = a;
	p->b = b;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

//ģ�������� B
typedef struct B
{
	A a;//���������

	//�������ݿ���ɾ����д�ϵ�Ŀ�ģ�������һ����
	int b;
	void dong11();
	void dong66();
	void initB(B* p, int a, int b);
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
void initB(B* p,int a, int b)//ΪʲôҪa�����أ���ʼ������
{
	//************�ص�**************
	//initA((A*)p, a, b);			//����B�࣬������Ҫ��ʼ��A�ࡣ�̳�A���е����ָ��
	p->a.vptr = &B_vtable;		//����������B���Լ������һ����һ�����
	p->b = b;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

//��������ȫ��ģ��

//����һ��A��
void test1()
{
	A aa;
	initA(&aa, 10, 20);
	((Vtable*)aa.vptr)->v1();
	((Vtable*)aa.vptr)->v2();
}
//����һ��B��
void test2()
{
	//����B��
	B *b = (B*)malloc(sizeof(B));
	initB(b, 10, 20);

	//ת��A��
	A *a = (A*)b;
	((Vtable2*)(a->vptr))->p();//���ڱ������Ǹ��࣬�����ǿ��Ե��ø���û�ж������еķ���

	printf("\n------��֤�漣��ʱ���ˣ�ʵ�ֶ�̬------\n\n");

	((Vtable*)(a->vptr))->v1();		//���า���˸�����󣬵��õľ����������
	((Vtable*)(a->vptr))->v2();		//����û�и��Ǹ�����󣬵��õľ��Ǹ������
}
//test3�������ġ���ʵ����b�಻��A���ܵ��ø��࣬���෽����test2ʵ�ֵĶ�̬����Ϊ��ģ��C++
void test3()
{
	B *b = (B*)malloc(sizeof(B));
	initB(b, 10, 20);

	//����������ַ��һ���ģ��������ϸ���ǡ���Ҳ�ǵ����˺þòŷ������еİ���
	printf("%d\n", b->a.vptr);
	printf("%d\n", ((A*)b)->vptr);

	((Vtable*)(b->a.vptr))->v1();	
	((Vtable*)(b->a.vptr))->v2();
	((Vtable2*)(b->a.vptr))->p();
}
int main()
{
	test1();
	printf("---------------------------------------------\n\n");
	test2();
	printf("---------------------------------------------\n\n");
	test3();
	system("pause");
	return 0;
}
/*
����  dong1
����  dong2
---------------------------------------------

������  dong66

------��֤�漣��ʱ���ˣ�ʵ�ֶ�̬------

������  dong11
����  dong2
---------------------------------------------

12185644
12185644
������  dong11
����  dong2
������  dong66
*/
/*
**************************���濴�ŷѾ�----�⿴���������**************************
typedef struct
{
	void(*v1)();
	void(*v2)();
}Vtable;

Vtable A_Vtable = { &dong1, &dong2 };	//�������������A ��仰���Ƿϻ�

typedef struct
{
	Vtable vtable;		//Vtable2��һ��Vtable������Vtable2����ת��ΪVtableʹ��v1 v2�� 
	void(*p)();			//�������Ǹ�ֵ��ʱ����Vtable2  ����������õ�ʱ�򣬻��Ǵ�Vtable2�е���
}Vtable2;

Vtable2 B_vtable = { { &dong11, &dong2 }, &dong66 };

���ԣ���ʼ�����������õľ���Vtable2ָ��ĺ��������Ե���v1������ΪVtable2����Vtable����Vtable����v1
*/