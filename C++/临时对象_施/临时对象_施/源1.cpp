#include<iostream>
using namespace std;

class B{
public:
	B(){
		cout << "B()" << endl;
	}
	~B(){
		cout << "~B()" << endl;
	}
	B(const B &b){
		cout << "const B &B" << endl;
	}
	B &operator =(const B &b){
		cout << "operator = " << endl;
	}
};

B test()
{
	B b;
	return b;
}

int main()
{
	B b = test();
	system("pause");
	return 0;
}
/*
���������gcc��û�е��ÿ�������
*/