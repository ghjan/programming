#include <iostream>
#include <regex>
#include <string>
using namespace std;

/*
��֤��ַ
*/
int test()
{
	string html;
	getline(cin, html);

	string pattern("http(s)?://([\\w-]+\\.)+[\\w-]+(/[\\w- ./?%&=]*)?");
	pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
	regex r(pattern);
	for (sregex_iterator it(html.begin(), html.end(), r), end;     //end��β���������regex_iterator��regex_iterator��string���͵İ汾
		it != end;
		++it)
	{
		cout << it->str() << endl;
	}
	getchar();
	return 0;
}