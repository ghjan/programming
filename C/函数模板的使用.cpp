#include<iostream>
using namespace std;
template<class t>t add(t a,t b)
{
	return a+b;
 } 
 int main()
 {
 	cout<<add(10.2,10.0)<<endl;		//�����������ֻ������ͬ���ͣ���int int����double double����char char 
 	cout<<add('a','\4')<<endl;		//   \4���ǰ���ĸ�������ƶ�4λ 
 	return 0;
 }
