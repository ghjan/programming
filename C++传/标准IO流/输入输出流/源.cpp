#include <iostream>
using namespace std;
/*
cin
cin.get();
cin.getline();
cin.ignore();
cin.peek();
cin.putback();
*/
int main7()
{
	//�ո�˵��peek()��get()�����𣬵���������������putback��get�����Ϳ�����ϳ�һ��peek
	char ch;
	char buf[20];
	if (1)
	{
		//��������������Ҫ����һ�����ֿ�ͷ���ַ�������ô����������
		cin.get(ch);
		if ('0' <= ch && '9' >= ch)
		{
			cin.putback(ch);	//����putback�ַ���������
			cin >> buf;
			cout <<"��һ�ַ�����"<< buf << endl;//�����������ѱ��˵�һ���ַ�Ҳ�������
		}
		//0dong
		//��һ�ַ�����0dong
	}
	else
	{
		//������������
		ch = cin.peek();//1.�ȿ�̽�ǲ��������������
		if ('0' <= ch && '9' >= ch)
		{
			cin >> buf;	//2.�ٽ��뵽������
			cout << "�ڶ��ַ�����" << buf << endl;//�����������ѱ��˵�һ���ַ�Ҳ�������
		}
		//0dong
		//�ڶ��ַ�����0dong
	}
	system("pause");
	return 0;
}
int main6()
{
	char buf[20];
	//cin.getline(buf,20);//��Ҫ���������Ȼ��������20���ַ������ܻس����Խ������룬����Ч����̫�ã�\
							����������û�����ݣ�peek()�������������ǣ�ֱ�������������������
	cin >> buf;//����ÿո񣬲�Ȼ�����������ʣһ���س����������ÿ�

	int a = cin.peek();		//��̽�����������һ�����ݣ������ء���cin.get()���������ڣ�get��ֱ�ӳ建��������ȡ�����ݣ�peek()ֻ�ǿ�̽

	cin.ignore(1);			//����һ���ַ���Ϊ�˲��ظ���̽һ���ַ�
	char i = cin.peek();
	cin.ignore(1);			//����һ���ַ�

	cout << a << "   " << i << endl;

	int b = cin.peek();
	cout << b << endl;

	//	aa bc
	//	32   b		// �ո�ʮ����ascii���� 32  
	//	99			//99���ַ�  c

	system("pause");
	return 0;
}

int main5()
{
	char ch;
	//while ((ch = cin.get()) != EOF)
	//{
	//	char a = cin.get();//�������ǻ����������������¼������ɻس�����������
	//	cout << a << endl;
	//}

	//while ((ch = cin.get()) != EOF)
	//{
	//	cin.get();		//������仰���Խ���������⣨���ǵ��ڶ���ѭ����ʱ�򻹻������⣬��Ϊ����һ��ѭ�����������س�  �ڶ����س����������get�������ˣ�
	//	char a = cin.get();								//�ڶ���ѭ����ֱ�������������
	//	cout << a << endl;
	//}

	//while ((ch = cin.get()) != EOF)
	//{
	//	cin.get();		
	//	char a = cin.get();
	//	cout << a << endl;
	//	cin.get();		//����취
	//}

	//while ((ch = cin.get()) != EOF)
	//{
	//	cin.ignore(1);//�·���		���Ի�������һ���ַ�
	//	char a = cin.get();
	//	cout << a << endl;
	//	cin.ignore(1);
	//}

	char s[20];
	cin.ignore(3);//����3���ַ�
	cin.getline(s, 20);
	//	12345678
	//	45678
	cout << s << endl;

	system("pause");
	return 0;
}
int main4()
{
	char buf1[1024];
	char buf2[1024];
	cin >> buf1;
	cin.getline(buf2,1024);
	cout << buf1 << endl;
	cout << buf2 << endl;

	//aa bb cc dd
	//aa
	//	bb cc dd		//ע�����￪ͷ��һ���ո��൱�ڰ������Ǹ��ո���ù�����

	system("pause");
	return 0;
}
int main()
{
	char a, b;
	char c[3];
	cin.get(a);
	cin.get(b);
	cin.get(c, 3);
	
	cout << a << b << c << endl;

	cin.get(a).get(b).get(c,3);//��3�ǽ��������ֽ�

	cout << a << b << c << endl;

	//	1234abcdef
	//	1234
	//	abcd
	system("pause");
	return 0;
}
int main2()
{
	char ch;
	while ((ch = cin.get())!=EOF)//����ctrl+z ֮�����		#define EOF     (-1)
	{
		cout << ch << endl;
	}

	system("pause");
	return 0;
}
int main1()
{
	char a[10];
	char b[10];
	char c[10];

	cin >> a;
	cin >> b >> c;

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	//	���룺aa bb cc dd			//���Կ����������ո����
//  �����
	//	aa
	//	bb
	//	cc
	system("pause");
	return 0;
}