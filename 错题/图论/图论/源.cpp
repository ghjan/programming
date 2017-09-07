#include <iostream>
#include <cstring>
using namespace std;

void test0()
{
	int a[] = { 1, 2, 3, 4, 5 };
	int *p = (int *)(&a + 1);				//ǰ��(int *)������Ӱ��ɶ���������int���͵�����
	printf("%d\n", *p);
	printf("%d\n", *(p - 1));
	printf("%d\n", *(p - 2));
	cout << "-------------------" << endl;
	p = (int *)(a + 1);
	printf("%d\n", *p);
	printf("%d\n", *(p - 1));
	printf("%d\n", *(p - 2));
	/*
	-858993460				5 �ĺ�һ���϶�������ֵ
	5
	4
	-------------------
	2
	1
	-858993460
	*/
	cout << "-------------------" << endl;
	cout << a << endl;
	cout << a + 1 << endl;	//���ﲽ��Ϊ 4 
	cout << &a + 1 << endl;// ���ﲽ��Ϊ 20 Ϊʲô��20�أ� ������
	/*
	0042F8C4	�������ַΪ�׵�ַ���洢��5��int Ҳ��ռ��20�ֽ� = 0x14
	0042F8C8
	0042F8D8	�պ� 0x80 = 0x6C + 0x14  Ҳ����˵������ȡ��ַ֮��  �����ᷢ���仯 ÿ�� + 1 �������������С
	*/
	cout << "-------------------" << endl;
	cout << a << endl;
	cout << (int *)&a + 1 << endl;	//���ﲽ��Ϊ 4 
	/*
	0108F6A4
	0108F6A8	���ﲽ���ֱ�Ϊ�� 4  ��Ϊ������ǿת�����ַ����Ϊ (int *)��
	*/
	cout << (int)a + 1 << endl; //�����������Σ������϶���1��
	/*
	0x108F6A5
	*/
}

void test1()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int *p1 = (int *)&a + 1;
	int *p2 = (int *)((int)a + 1);
	printf("%d,%d\n", p1[-1], *p2);//1,2000000
	// *p2�϶�����2  ��Ϊ (int)a �Ĳ�����Ϊ��1 
	printf("%d\n", *(int *)((int)p2 - 1));
}

void test2()
{
	char a[] = "hello";
	cout << (void *)a << endl;
	cout << &a << endl;
	/*
	00FCF968
	00FCF968	��ַ����һ��  ��������ȡ��ַ��ȡ�ľ��ǵ�һ���ַ��ĵ�ַ
	*/
	char *b = "hello";
	cout << (void *)b << endl;
	cout << &b << endl;
	/*
	0125E098
	0019F8CC	��ַ��һ��    ָ������鲻��һ�����������ֻ��һ��ƫ�ƣ���һ����ֵ��
	*/
	int c[] = { 2, 3, 4, 5 };
	cout << (void *)c << endl;
	cout << &c << endl;
	/*
	0021FAB8
	0021FAB8	ֻҪ�����飬&c���ǵ�һ�����洢�ĵ�ַ��ֻ��Ҫע�⡰�������ͺ���
	*/
}

void test3()
{
	unsigned char c = -1;
	int i = (int)c;
	printf("%d\n", c);//255   1�ֽ�������255��

	c = -2;
	printf("%d\n", (int)c);//254
}

void test4()
{
	/*���ƶ����� *2   ���ƶ����� /2 */
	int b = 0xff000000;
	b >>= 1;
	printf("%x\n", b);//ff800000    ��Ҫע�⣺�����������λҪ��1
	//�𰸽�����  1111 1111 0000 ����ȫ��0�ˣ���ǰ�漸���ͺ���
	//����1λ��   1111 1111 1000 ת����16���Ʋ����� 0xff800000

	/*��֪�������ж��ô����*/
	unsigned int i = 0xffffffff;
	i >>= 1;
	int ii = i;
	cout << ii << endl;		//�������int���ͱ�ʾ�����ֵ  Ҳ����0x7fffffff   Ҳ����0xffffffff >>= 1
	ii++;
	cout << ii << endl;		//����һ�����Ǹ��������ֵ��   �������Ҳ����0xfffffff Ҳ���� -1 �ټ�һ�͵��� 0��
}

int main()
{
	test1();

	system("pause");
}