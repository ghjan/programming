#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

void test1()
{
	//ֻ��ָ����Ҫ����ڴ�й©����
	//int* p = new int[1024 * 1024 * 100];//ֱ��ռ400M �ڴ档��Ϊ��������ҳ����ģ����Բ���100M

	//ֻ���ù��캯����ʼ�� ������ = 
	auto_ptr<int> p1(new int[1024 * 1024 * 100]);//ֻռ��  0.4M 
}
void test2()
{
	/*
	�жϣ�
	����ָ�벻��new STL����е���
	ԭ��auto_ptr �᲻�ϵĽ�Լ�ڴ棬����delete���ᵼ��string���ڲ�����
	*/
}
void test3()
{
	//STL ���� auto_ptr ����
	vector<auto_ptr<int>> vp;
	vp.push_back(auto_ptr<int>(new int[10]));
	//vector��������һ��auto_ptr ���auto_ptrָ��һ�����������ڴ�
}
void test4()
{
	char *p = "hello";
	auto_ptr<char *> p1(&p);
	
	auto_ptr<char *> p2(p1);		//�ڴ���p2��ʱ��p1�ᱻ����

	auto_ptr<char *> p3(&p);
	auto_ptr<char *> p4 = p3;		//�ڴ���p4��ʱ��p3�ᱻ����

	//ͬʱ����p1 p2    p1�ж�
	/*cout << "p2----" << *p2 << endl;
	cout << "p1----" << *p1 << endl;*/

	//ͬʱ����p3 p4  p3�ж�
	cout << "p4-----" << *p4 << endl;
	cout << "p3----" << *p3 << endl;
	
	
	/*
	���⣺
	�����Ǵ�ӡp2��ʱ��û��ʲô���⣬���ǵ����Ǵ�ӡp3��ʱ���ж���

	��Ȼ��ǳ���������ǲ��ǵ�����ǳ������
	ǳ��������һ�����ü����������ü���Ϊ0 ��������delete�ڴ�
	
	5. ��ֹ����auto_ptr����ӵ��ͬһ������һ���ڴ棩
	��Ϊauto_ptr������Ȩ����-----------------------------������� = ��ô�Ⱥ��ұߵ�����ָ�뽫�ᱻ����
	
	*/
}


