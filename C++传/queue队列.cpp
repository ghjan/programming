#include <iostream>
#include <queue>
using namespace std; 

int main2()
{
	queue<char> q;
	for(char i = 'A';i<='Z';i++)
	{
		q.push(i);//��ĩβ��һ��Ԫ�� 
		cout<<q.back()<<"   ";//�������һ��Ԫ��  
	}
	cout<<endl;
	while(!q.empty())
	{
		cout<<q.front()<<"   ";//���ص�һ��Ԫ�� 
		q.pop();//ɾ����һ��Ԫ�� 
	}
	cout<<endl;
}
int main()
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.front() = 5;
	cout<<q.front()<<endl;
	cout<<q.back()<<endl;
}
