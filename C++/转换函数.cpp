#include<iostream>
#include<string.h>
using namespace std;
class cmoney
{
	double amount;
public:
	cmoney(double a=0)
	{
		amount=a;
	}
	 operator char*();   //ת������
};
cmoney::operator char*()
{
	char *ba[15]={"��","��","Ԫ","ʮ","��","ǧ","��","ʮ","��","ǧ","��","ʮ","��","ǧ","��"};
	char *da[10]={"��","Ҽ","�E","��","��","��","��","��","��","��"};
	static char str[80];
	double temp,base=1;
	int n=0;
	temp=amount*100;
	cout<<temp<<endl;
	strcpy(str,"���Ϊ:");
	if(temp<1)
		strcpy(str,"Ҫ����һ��Ǯ");
	else
	{
		while(temp>=10)
		{
			base*=10;
			temp/=10;
			n++;
		}
		if(n>=15)
			strcpy(str,"Ǯ̫����");
		else
		{
			temp=amount*100;
			for(n;n>=0;n--)
			{
				int d=temp/base;
				temp=temp-base*d;
				base=base/10;
				strcat(str,da[d]);
				strcat(str,ba[n]);
			}
		}
	}
		return str;
}
int main()
{
	cmoney money(1234123456789.123);
	cout<<(char*)money<<endl;			//����ת������
	return 0;
}
