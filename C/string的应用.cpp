#include <iostream>
#include <string>
using namespace std;

int main1()
{
	string s1 = "chen,ming,haha";
	
	string s2(s1,0,4);//chen		//��ȡ�Ǳ�0 ֮���4���ַ�
	string s3(s1,5,4);//ming       //��ȡ�Ǳ�5 ֮���4���ַ� 
	string s4(s1,4);//,ming,haha   //��ȡ�Ǳ�4 �����  ���ַ��� 
	
	cout<<s2<<"       "<<s3<<"    "<<s4<<endl;	
	
	
	char str[] = "chen,ming,haha";
	string s5(str,4);//��ȡǰ�ĸ� 
	cout<<s5<<endl;
	
	string s6(10,'d');//��ʼ��Ϊ10��d 
	cout<<s6<<endl; 
}

int main2()
{
	string s1;
	
	//��ȡ�ַ�������ֵ��s1���ԣ�����		���Բ�ֹһ�� 
	getline(cin,s1,'!'); 
	
	cout<<s1<<endl;
	
	//������ĩβ�����ַ������� 
	s1.push_back('Q');//��ĩβ��Q
	 
	s1+='A'; 
	
	s1+="bbbb";
	
	int i = s1.find("23");
	
	cout<<s1<<"   i = "<<i<<endl;
 
	
	cout<<endl;	
}

int main()
{
	string s1 = "chen,ming,dong";
	
	s1.erase(0,10);//ɾ���Ǳ� 0  -  9  ���ַ� 
	
	cout<<s1<<endl;

	
	s1.clear();//��� 
	
	cout<<s1<<endl; 
	
}
