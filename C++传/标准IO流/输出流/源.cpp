#include <iostream>
#include <iomanip>
#include <cstring>
#include <bitset>
using namespace std;

int main()
{
	int a = 7;
	cout << bitset<8>(a) << endl;//�ñ��˵��࣬��Ҫ��ͷ�ļ�

	char buf[32];
	_itoa_s(a, buf, 2);
	cout << buf << endl;
	
	/*	����ת��2���Ƶķ���
	00000111
	111
	*/

	system("pause");
	return 0;
}
int main4()
{
	int i, j, k, l;
	cout << "Input i(oct), j(hex), k(hex), l(dec) :" << endl;
	cin >> oct >> i; //����Ϊ�˽�����
	cin >> hex >> j; //����Ϊʮ��������
	cin >> k; //������Ϊʮ��������		����hex֮�󣬾�Ĭ����hex
	cin >> dec >> l; //����Ϊʮ������
	cout << "���" << endl;
	cout << "i = " << i << endl;
	cout << "j = " << j << endl;
	cout << "k = " << l << endl;
	cout << "l = " << k << endl;
	/*
	Input i(oct), j(hex), k(hex), l(dec) :
	20 20 20 20										// 0  �� 0x ����ʡ��
	���
	i = 16		//  8���� 20  == 10���� 16
	j = 32		// 16���� 20  == 10���� 32
	k = 20		
	l = 32		// 16���� 20  == 10���� 32

	Input i(oct), j(hex), k(hex), l(dec) :
	020 0x20 0x20 20								
	���
	i = 16
	j = 32
	k = 20
	l = 32
	*/
	
	/*
����˵����
					
ʹ�ò���.h��ͷ�ļ�<iostream>ʱ��������cin��ָ�����ƣ�����Ӽ�������ʱ�����ϰ˽��ƺ�ʮ����������ͷ��0��0x��־��ָ�����ʡ��0��0x��־��

���ƿ���ֻ���������ͱ�������������ʵ�ͺ��ַ��ͱ�����

�������ݵĸ�ʽ�����������ͱ�����cin�еı���һһ��Ӧ�����򲻽�ʹ�������ݴ��󣬶���Ӱ������������ݵ���ȷ���롣

��cin��cout��ָ�����ƺ󣬸����ƽ�һֱ��Ч��ֱ������ָ��ʹ���������ơ�
	*/
	system("pause");
	return 0;
}

int main3()
{
	cout.width(8);
	cout.fill('*');//���
	cout.setf(ios::showbase);
	cout << hex << 20 << endl;

	cout.width(8);
	cout.fill('*');//���
	cout.setf(ios::showbase);
	cout.setf(ios::internal);// internal �ڲ���;
	cout << hex << 20 << endl;

	//ʹ�ÿ��Ʒ�		Ч��������һ��
	cout << setw(8) << setfill('*') << setiosflags(ios::showbase) << setiosflags(ios::internal) << hex << 20 << endl;

	//һ�����16 ����
	cout << "ʮ������  " << hex << 20 << endl;
	cout << "�˽���    " << oct << 20 << endl;

	/*
	setiosflags�Ĳ����Ǹ����ĸ�ʽ��־ֵ�����ֵ������λ����(iosö����)ָ����������λ��OR(|)�����������ϣ�
    ios::skipws  �������������հס�    
    ios::left  �����ֵ��������ַ�����ұߡ�
    ios::right  �Ҷ���ֵ��������ַ�������(ȱʡ���뷽ʽ)��
    ios::internal  ��ָ���κ�������ǻ��֮����������ַ���
    ios::dec  �Ի�10(ʮ����)��ʽ����ֵ(ȱʡ����)��
    ios::oct  �Ի�8(�˽���)��ʽ����ֵ��
    ios::hex  �Ի�16(ʮ������)��ʽ����ֵ��
    ios::showbase  ��C++�������ܶ��ĸ�ʽ��ʾ��ֵ������
    ios::showpoint  �Ը�����ֵ��ʾС�����β����0��
    ios::uppercase  ����ʮ��������ֵ��ʾ��д��ĸA��F�����ڿ�ѧ��ʽ��ʾ��д��ĸE��
    ios::showpos  ����������ʾ����(+)��
    ios::scientific  �Կ�ѧ��ʽ��ʾ������ֵ��
    ios::fixed  �Զ����ʽ��ʾ������ֵ��
    ios::unitbuf  ������ÿ�β���֮��ostream::osfxˢ�¸�����ȱʡ�أ�cerr�ǻ���ĵ�Ԫ��
    ios::stdio  ������ÿ�β���֮��ostream::osfxˢ�¸�����stdout��stderr��
	*/

	system("pause");
	return 0;
}
int main2()
{
	cout.width(8);
	cout.fill('*');//���
	cout << "������";

	cout.width(2);
	cout.fill('#');
	cout <<""<< endl;

	system("pause");
	return 0;
}
int main1()
{
	cout << "chen" << endl;
	cout.put('m').put('i').put('n').put('g') << endl;

	char* p = "dong";
	cout.write(p, strlen(p)) << endl;
	cout.write(p, strlen(p) - 1) << endl;
	cout.write(p, strlen(p) + 4) << endl;

	system("pause");
	return 0;
}