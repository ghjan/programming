#include<iostream>
using namespace std;

//NumberParseException���Զ�����쳣��
class NumberParseException {};

void test1()							// �����׳��κ��쳣
{
	char *str1 = "1", *str2 = NULL;
	if (str2 == NULL)
		throw NumberParseException();

	int num1 = atoi(str1);
	int num2 = atoi(str2);//��str2 == NULL �����쳣
	printf("sum is %d\n", num1 + num2);
}

//��ʾtest2()ֻ���׳������쳣int , char, �Լ���Щ�����������쳣���������׳������쳣��
//���f����Υ��������涨���׳���int , char֮����쳣, ����x4, ��ô������f�׳�x4�쳣ʱ��
//��ת��Ϊһ��std::unexpected()���ã�Ĭ���ǵ���std::terminate(), ͨ���ǵ���abort()��
void test2()throw (int , char)
{
	test1();
}
void test3() throw () // �����׳��κ��쳣
{
	throw "test3()�쳣��";
}

int main()
{
	try{
		test3();//����������쳣�ˣ���ô����Ĵ��뽫���ᱻִ��
		test2();
	}
	catch (NumberParseException){
		printf("���벻������\n");
	}
	catch (int ){
		printf("int �쳣\n");
	}
	catch (char* e)
	{
		cout << e << "   char* �쳣" << endl;
	}
	catch (...)					//�൱��switch�е�default   �����쳣
	{
		printf("δ֪�쳣\n");
	}

	system("pause");
}

	//try {
	//	throw E();
	//}
	//catch (H h) {
	//	//��ʱ���ǿ����ܵ�������
	//}
	//1.���H��E����ͬ������

	//2.���H��E�Ļ���

	//3.���H��E����ָ�����ͣ�����1����2�����������õ����ͳ���

	//4.���H��E�����������ͣ�����1����2��H�����õ����ͳ���