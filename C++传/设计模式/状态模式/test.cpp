#include <iostream>
using namespace std;
class Fro
{
public:
	enum e{ hello, nice };
	Fro()
	{
		cout << typeid(hello).name() << endl;
		dong2(hello);
		//dong1(hello);//��֪��Ϊʲô���������������е�enum���ܴ���ȥ�ɡ������е��þ��ǲ���ʹ
	}
	void dong2(enum e w)
	{
		cout << w << endl;
	}
};
void dong1(enum Fro::e w)
{
	cout << w << endl;
	cout << Fro::nice << endl;
}
int main()
{
	Fro* fro = new Fro;
	enum Fro::e w = Fro::hello;
	dong1(w);

	system("pause");
	return 0;
}