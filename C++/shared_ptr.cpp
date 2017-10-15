#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

void test1(){
	shared_ptr<string> pNico(new string("nico"));
	shared_ptr<string> pJutta(new string("jutta"),
		[](string *p) {
		cout << "delete " << *p << endl;
		delete p;
	}
	);

	(*pNico)[0] = 'N';
	pJutta->replace(0, 1, "J");

	vector<shared_ptr<string>> whoMadeCoffee;
	whoMadeCoffee.push_back(pJutta);
	whoMadeCoffee.push_back(pNico);
	whoMadeCoffee.push_back(pJutta);
	whoMadeCoffee.push_back(pNico);

	for (auto ptr : whoMadeCoffee)
		cout << *ptr << " ";
	cout << endl;

	*pNico = "Nicolai";
	for (auto ptr : whoMadeCoffee)
		cout << *ptr << " ";
	cout << endl;
	
	cout << "use_count: " << whoMadeCoffee[0].use_count() << endl;
}
/*
Jutta Nico Jutta Nico
Jutta Nicolai Jutta Nicolai
use_count: 3
delete Jutta
*/
void test2(){
	int *p = new int(6);
	shared_ptr<int> sp(p);
	cout<<p<<endl;
	cout<<&(*sp)<<endl;
	cout<<sp.use_count()<<endl;
	shared_ptr<int> p2 = sp;
	cout<<sp.use_count()<<endl;
}
/*
0xa114e0
0xa114e0
1
2
*/
class A{
public:
	A(){cout<<"����"<<endl;}
	~A(){cout<<"xigou"<<endl;}
};
void test3(){
//	shared_ptr<A[]> sp(new A[2]); 	shared_ptr"����ָ������" Ĭ������ֻ��delete 
	shared_ptr<A> sp(new A[2],	//���ǿ���ָ��������׵�ַ 
	[](A *a){
		cout<<"�Զ�����������"<<endl; 
		delete[] a;		//ע�⣺���ָ��������飬�����Զ�������������Ĭ�ϵ��õ��� delete 
	}
	);
}
int main(){
	//test1();
	test3();
}

