#include<iostream>
using namespace std;
int main()
{
	char s[100];
	int i=0,n;
	while((s[i]=cin.get()) !='\n') i++;		//��getchar();Ҳ���� 
	for(n=0;n<i;n++)
	if(s[n]!='*')
	cout<<s[n];
 } 
