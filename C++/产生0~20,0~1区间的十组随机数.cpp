#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
	double d;
	int i,n; 
	srand(time(0));
	for(i=0;i<10;i++)
	{
		n=rand()%20;				//����0~20֮���������� 
		d=rand()/(double)RAND_MAX;	//����0`1֮���С�� 
		cout<<n<<"\t"<<d<<endl;
	}
	return 0;
 } 
