#include <iostream>
using namespace std;

typedef struct st_type
{
	int nCnt;
	int item[0];
}type_a;
//����Щ�������ᱨ���޷�������Ըĳɣ���
typedef struct st_type2
{
	int nCnt;
	int item[];
}type_a2;

void test()
{
	//int a[0];  ����������������Ǵ��  �� gcc�п��ԣ�ռ4B
	//int a[];    ͬ��
	cout << sizeof(type_a) << endl;
	cout << sizeof(type_a2) << endl;

	type_a *p = (type_a*)new char[sizeof(type_a) + 100 * sizeof(int)];
	type_a2 *p2 = (type_a2*)new char[sizeof(type_a2) + 100 * sizeof(int)];

	

	memcpy(p->item, "abcdefg", 8);//������ֵ�ǲ��е�
	memcpy(p2->item, "������", 7);
	
	cout << p->item << endl;//�����Ǵ�ӡ�������ģ���Ϊ��int����
	cout << p2->item << endl;

	char *p3 = (char*)p->item;
	char *p4 = (char*)p2->item;
	
	cout << p3 << endl;
	cout << p4 << endl;

	cout << sizeof(type_a) << endl;
	cout << sizeof(type_a2) << endl;
}
int main()
{
	test();

	/*
	�������ǾͲ�����һ����Ϊ100��type_a���͵Ķ�����p->item[n]���ܼ򵥵ط��ʿɱ䳤Ԫ�أ�
	ԭ��ʮ�ּ򵥣������˱�sizeof(type_a)����ڴ��int item[0]�������������ˣ�
	��ָ�����int nCnt��������ݣ���û���ڴ���Ҫ�ģ����ڷ���ʱ�������ڴ�Ϳ����������ٿأ�
	�Ǹ�ʮ�ֺ��õļ��ɡ�  
	*/

	getchar();
}
/*
C99�����ṹ�����ʹ��0��1�ĳ��������ԭ����Ҫ��Ϊ�˷���Ĺ����ڴ滺������
�����ֱ��ʹ��ָ�����ʹ�����飬��ô���ڷ����ڴ滺����ʱ���ͱ������ṹ��һ�Σ�Ȼ���ٷ���ṹ���ڵ�ָ��һ��
������ʱ������ڴ��Ѿ���ṹ����ڴ治�����ˣ�����Ҫ�ֱ����������ͷţ������ʹ�����飬
��ôֻ��Ҫһ�ξͿ���ȫ�����������������������ӣ������������ͷ�ʱҲ��һ����
ʹ�����飬һ���ͷţ�ʹ��ָ�룬�����ͷŽṹ���ڵ�ָ�룬���ͷŽṹ�塣�����ܵߵ�����
��ʵ���Ƿ���һ�������ĵ��ڴ棬�����ڴ����Ƭ����


���ͷ�ͬ���򵥣�
C���԰棺    free(p);
C++���԰棺  delete []p;

�ŵ��У�
1.�ṹ����������µĴ洢�䳤����Ŀռ䣻
2.�ͷűȽϷ��㣻
*/