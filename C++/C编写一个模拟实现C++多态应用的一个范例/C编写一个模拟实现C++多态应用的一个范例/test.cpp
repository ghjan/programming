#include <stdio.h>
#include <stdlib.h>
void dong7()
{
	printf("����  dong1\n");
}
void dong8()
{
	printf("����  dong2\n");
}
void dong9()
{
	printf("����  dong3\n");
}
//ģ�����ṹ
typedef struct
{
	void(*v1)();
}AA;

//ģ��һ�����е����
AA test1 = { &dong7};
typedef struct A
{
	//int b;	//����һ�½�ע�ͣ����B��ֻ��4�ֽڴ�С��A��8�ֽڣ�BǿתΪA��Ҳֻ�ܲ���ǰ4�ֽڵĶ����������������ָ�뽫��  ջ���
	void *vptr;//�麯��ָ��   ռ4�ֽ�
}A;


typedef struct
{
	void(*v1)();
	void(*v2)();
	void(*v3)();
}BB;
BB test2 = { &dong7, &dong8, dong9 };
typedef struct B
{
	//void *vptr;//�麯��ָ��
	//A a;//����֪��Ϊʲôdemo����Ҫ����A a   Ŀ�ģ�Ϊ��ȷ��B���A��󣬵�ʱ�򴴽�BȻ�󸳸�A\
				B��Ϳ��Բ���A���е�Ԫ���ˣ����B����A���ͻᷢ��stack���(�������A��ƫ�Ƶ�ַ����B���ƫ�Ƶ�ַ)
	int a;//��B��СΪ4�ֽ�
}B;
int main3()
{
	/*A a;
	B* b = (B*)&a;
	b->vptr = &test2;
	((BB*)(b->vptr))->v1();
	((BB*)(b->vptr))->v2();*/
	printf("%d", sizeof(B));
	printf("%d", sizeof(A));
	B b;
	A *a = (A*)&b;//�����ǹؼ�����Ȼ��������b�����ǿ���ǿתΪA��Ŀ����������A�е�ָ��
	a->vptr = &test2;//a�е�ָ�����ָ��  a  b  �κ�һ���ṹ��
	((BB*)(a->vptr))->v1();
	((BB*)(a->vptr))->v2();
	((AA*)(a->vptr))->v1();


	system("pause");
	return 0;
}