#include <iostream>
using namespace std;

// ���������ĺ�������Ӧ�������е��麯��
// 
void foo1()
{
	printf("anything foo1 \r\n");
}
void foo2(int i)
{
}
void foo3(int i, int j)
{
}
// ����������麯����ָ��
typedef struct Vtbl
{
	void(*pf1)();
	void(*pf2)(int);
	void(*pf3)(int, int);
}Vtbl;

// ������
Vtbl g_vtbl = { &foo1, &foo2, &foo3, };

// ���࣬��ʼ�������ָ�룬
// �����ǽṹ��Ա��
typedef struct Anything
{
	//Vtbl *pvtbl;
	void *pvtbl;
	int field1;
	int field2;
}Anything;

// ���캯��
// Ҳ��һ����ͨ�ĳ�Ա��������Ҫһ��thisָ��
void InitAnything(Anything *p)
{
	p->pvtbl = &g_vtbl;
	p->field1 = 0x1234;
	p->field2 = 0x5678;
}

// �����е��麯���������˸����е�ͬ���ͺ���
void Sfoo1()
{
	// ���Կ��ǵ��ø����еĺ���
	// foo1();
	printf("something foo1 \r\n");
}

void Sfoo4(char *s)
{
	printf("hello %s\r\n", s);
}

// �����е������Ϊ�ڴ沼����һ���ģ�
// ֱ��ʹ�ø����
typedef struct SVtbl
{
	Vtbl vtbl;
	void(*pf4)(char *);
}SVtbl;

// ��������
SVtbl g_svtbl = { { &Sfoo1, &foo2, &foo3, }, &Sfoo4, };
// ĳ�����࣬�������������
// �����Լ��ĳ�Ա
typedef struct Something
{
	Anything a;
	int field3;
}Something;

// ���캯��
// Ҳ��һ����ͨ�ĳ�Ա��������Ҫһ��thisָ��
void InitSomething(Something *p)
{
	InitAnything((Anything*)p);

	p->a.pvtbl = &g_svtbl;
	p->field3 = 0xabcd;
}

void TestPolymorphism(Anything *p)
{
	// ��Ȼʹ�õ��Ǹ����͵�ָ��
	// ���麯�����ջ���ݶ������ʵ���͵��á�
	(*((Vtbl*)p->pvtbl)->pf1)();
}

void TestVtbl()
{
	// �����һ������
	Something s;
	Anything *p = 0;

	// ��ʼ��
	InitSomething(&s);

	p = (Anything*)&s;

	// ����Sfoo4
	((SVtbl*)p->pvtbl)->pf4("Sfoo4");

	// ���Զ�̬
	TestPolymorphism((Anything*)&s);
}

int main1()
{
	TestVtbl();

	system("pause");
	return 0;
}