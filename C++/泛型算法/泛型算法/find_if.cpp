#include <algorithm>
#include <list>
#include <set>
#include <string>
#include <iostream>
using namespace std;

class OurFriends {
public:
	bool operator()(const string& str) {
		return static_cast<bool>(
			friendset.count(str));//��set���ҵ�str�ͷ���true
	}
	static void
		FriendSet(const string *fs, int count) {
		copy(fs, fs + count,
			inserter(friendset, friendset.end()));
	}
	static void print(){
		cout << "set:" << endl;
		for (auto a : friendset)
			cout << a << " ";
		cout << endl;
	}
private:
	static set< string, less<string>> friendset;
};
set< string, less<string>> OurFriends::friendset;

void print(list<string> lf){
	cout << "list:" << endl;
	for (auto a : lf)
		cout << a << " ";
	cout << endl;
}

int test1()
{
	string Pooh_friends[] = { "Piglet", "Tigger", "Eyeore" };
	string more_friends[] = { "Quasimodo", "Chip", "Piglet" };
	list<string> lf(more_friends, more_friends + 3);
	print(lf);

	// ���� pooh_friends �б�
	OurFriends::FriendSet(Pooh_friends, 3);
	OurFriends::print();

	list<string>::iterator our_mutual_friend;
	our_mutual_friend =
		find_if(lf.begin(), lf.end(), OurFriends());

	if (our_mutual_friend != lf.end())
		cout << *our_mutual_friend
		<< " �����ǹ�ͬ������ \n";
	return 0;
}