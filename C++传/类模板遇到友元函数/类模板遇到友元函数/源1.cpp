//#include <iostream>
//using namespace std;
////
////���д������
////ostream operator << (ostream& os, Point& pt)
////��
////Point a, b;
////cout << a << b;
////����ֻ��дΪ��
////cout << a;
////cout << b;
////ԭ������
////cout << a << b;
////�൱�ڣ�
////(cout << a) << b;
////��һ��()�з���cout����ʱ�����������Բ�������Ϊ��ֵ���������
////
////���д�ɣ�
////ostream& operator << (ostream& os, Point& pt)
////��
////cout << a << b;
////��ȷ����Ϊ����ͬ��
////(cout << a) << b;
////(acout << a)����cout�����ã����������Լ����������ٴ���Ϊ��ֵ������ܹ�����д��������
//
//template < typename T >
//class A
//{
//    friend ostream &operator<< <T>(ostream &, const A< T > &);
//	friend A operator-<T>(A &a1, A &a2);
//	T age;
//public:
//	A(){}
//	A(T a)
//	{
//		age = a;
//	}
//	void show()
//	{
//		cout << age << endl;
//	}
// };
//
//template < typename T >
//ostream &operator<< (ostream &output, const A< T > &a)
//{
//    output << "���سɹ�" << endl;
//    return output;
// }
//
//template<class T>
//A<T> operator-(A<T> &a1, A<T> &a2)
//{
//	A<T> tmp(a1.age - a2.age);
//	return tmp;
//}
//
//int main2()
//{
//	A<int> a;
//	cout << a << a;
//	cin.get();
//	return 0;
// }
//int main3()
//{
//	A<int> a(10);
//	A<int> b(50);
//	A<int> c = b - a;
//	c.show();
//
//
//	cin.get();
//	return 0;
//}