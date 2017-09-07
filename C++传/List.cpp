//	Lists��Ԫ�ذ�˳�򴢴���������. �� ����(vectors)���, ��������ٵĲ����ɾ���������������ȴ�Ƚ���.
//	
//	assign() ��list��ֵ 						���룺����
//	back() �������һ��Ԫ�� 
//	begin() ����ָ���һ��Ԫ�صĵ����� 
//	clear() ɾ������Ԫ�� 
//	empty() ���list�ǿյ��򷵻�true 
//	end() ����ĩβ�ĵ����� 
//	erase() ɾ��һ��Ԫ�� 
//	front() ���ص�һ��Ԫ�� 
//	get_allocator() ����list�������� 
//	insert() ����һ��Ԫ�ص�list�� 
//	max_size() ����list�����ɵ����Ԫ������ 
//	merge() �ϲ�����list 
//	pop_back() ɾ�����һ��Ԫ�� 
//	pop_front() ɾ����һ��Ԫ�� 
//	push_back() ��list��ĩβ���һ��Ԫ�� 
//	push_front() ��list��ͷ�����һ��Ԫ�� 
//	rbegin() ����ָ���һ��Ԫ�ص���������� 
//	remove() ��listɾ��Ԫ�� 
//	remove_if() ��ָ������ɾ��Ԫ�� 
//	rend() ָ��listĩβ����������� 
//	resize() �ı�list�Ĵ�С 
//	reverse() ��list��Ԫ�ص�ת 
//	size() ����list�е�Ԫ�ظ��� 
//	sort() ��list���� 
//	splice() �ϲ�����list 
//	swap() ��������list 
//	unique() ɾ��list���ظ���Ԫ��

#include <iostream>
#include <list>
#include <numeric>  
#include <algorithm>   
using namespace std;  

void pForward(list<int> l)
{
	//������� 
	for(list<int>::iterator i = l.begin();i!=l.end();i++)
	{
		cout<<*i<<"\t";
	}
	cout<<endl;
}
void pReverse(list<int> l)
{
	//������� 
	for(list<int>::reverse_iterator i = l.rbegin();i!=l.rend();i++)
	{
		cout<<*i<<"\t";
	}
	cout<<endl;
}

int main1()
{
	//list1�����ʼΪ��   
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_front(4);
	l.push_front(6);
	
	pForward(l);
	
	pReverse(l);
	
	//ʹ��STL��accumulate(�ۼ�)�㷨   ��Ҫ#include <numeric>    ������1.��һ��������ֵ 2.���һ������ֵ 3.ǰ�����õ���� 
	int res = accumulate(l.begin(),l.end(),0);
	cout<<"�ܺͣ�"<<res<<endl;
	
	list<int>::iterator i = max_element(l.begin(),l.end());
	cout<<"������"<<*i<<endl;
}
int main()
{
	list<int> list1;
	list1.push_back(1);
	list1.push_back(2);
	list1.push_back(3);
	list1.push_back(4);
	list1.push_back(5);
	//list2���������10��ֵΪ6��Ԫ��  
	list<int> list2(10,6);
	pForward(list2);
	
	//list3���������3��ֵΪ6��Ԫ��   
    list<int> list3(list1.begin(),--list1.end());//��ʼ������list1 �ĵ�һ������ �����ڶ����� 
    pForward(list3);
    
    //��list1�����м��������   
    list1.insert(++list1.begin(),3,9);//�ڵڶ���λ�ã�����3��9 
	pForward(list1);
	
	//���������ຯ��   
    cout<<"list1.front()="<<list1.front()<<endl;   
    cout<<"list1.back()="<<list1.back()<<endl;   
    
    //��list1���е�ǰ�����ȥһ��Ԫ��   
    list1.pop_front();   
    list1.pop_back();   
    cout<<"list1���е�ǰ�����ȥһ��Ԫ�� "<<endl;   
    pForward(list1);
	
	 //���list1�еĵ�2��Ԫ��   
    list1.erase(++++++list1.begin());   
    cout<<"���list1�еĵ�4��Ԫ�� "<<endl;   
    pForward(list1);      
    
    //��list1��������   
    list1.sort();   
    cout<<"��list1�������� "<<endl;  
    pForward(list1); 
    
     //��list2��ֵ����ʾ   
    list2.assign(8,1);   
    cout<<"��list2��ֵ����ʾ "<<endl;   
    pForward(list2); 
    
    //splice() �ϲ�����list 
    list1.splice(++++list1.begin(), list2);//��list1 �ĵ�����λ�ÿ�ʼ�ϲ���������˵list1�ĵ�����λ���Ժ���list2  Ȼ������list1ʣ�µ��� 
    cout<<"�ϲ�����list"<<endl;
    pForward(list1); 

}


