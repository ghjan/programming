#include <iostream>
#include <string>
using namespace std;

class Link
{
public:
	char data;
	Link *next;
};
///////////////////////////ע���һ�������ڵ��Ժ�Ľڵ����һ��//////////////////////////////
int get_list_len(Link *link)
{
	int count = 0;
	while(link)
	{
		++count;
		link = link->next;
	}
	return count;
}
Link *find_first_public(Link *link1,Link *link2)
{
	/* 先把两个链表弄成一样长 */
	Link *long_link;
	Link *short_link;
	int len1 = get_list_len(link1);
	int len2 = get_list_len(link2);
	int count;
	if(len1 > len2)
	{
		long_link = link1;
		short_link = link2;
		count = len1 - len2;
	}
	else
	{
		long_link = link2;
		short_link = link1;
		count = len2 - len1;
	}
	while(count)
	{
		--count;
		long_link = long_link->next;
	}
	/* 第一个相同的节点即为公共节点 */
	while(long_link)
	{
		if(long_link->data == short_link->data)
			return long_link;
		long_link = long_link->next;
		short_link = short_link->next;
	}
	return NULL;
}
///////////////////////////////////////////////////////////////////////////
Link* create_link(string s)
{
	Link *head = new Link;
	Link *link,*pre = head;
	string::iterator it = s.begin();
	while(it != s.end())
	{
		if(it == s.begin())
			head->data = *it++;
		else
		{
			link = new Link;
			pre->next = link;
			link->data = *it++;
			pre = link;
		}
	}
	link->next = NULL;
	link = head;
	while(link)
	{
		cout<<link->data<<" ";
		link = link->next;
	}
	cout<<endl;
	return head;
}

int main()
{
	Link *link1 = create_link("dong");
	Link *link2 = create_link("shuai dong");
	Link *link3 = create_link("he ong");
	cout<<find_first_public(link1,link2)->data<<endl;
	cout<<find_first_public(link2,link3)->data<<endl;
}
