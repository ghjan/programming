#include "iostream"
using namespace std;

//����һ����
//������--------------------------->���д��麯������ 
class figure
{
public:
	virtual int showarea() = 0; //���麯��
};

class Tri : public figure
{
public:
	Tri(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
	}
	virtual int showarea()
	{
		cout<<"������s"<<a*b/2<<endl;
		return 0;
	}
protected:
private:
	int a;
	int b;
};

class Squre : public figure
{
public:
	Squre(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
	}
	virtual int showarea()
	{
		cout<<"�ı���s"<<a*b<<endl;
		return 0;
	}
protected:
private:
	int a;
	int b;
};


//ͨ�������࣬����һ�׽ӿڡ����ñ���ʵ����ĳ�����Ľӿڶ��壻������
//��ܾͿ����ڲ����κθı������£����ú�����д�����ࣨ����������ࣩ����
void printS(figure *pbase)
{
	pbase->showarea();
}
int main81()
{
	
	//figure f;
	figure *pbase = NULL;
	Tri tri(10, 2);
	tri.showarea();
	Squre sq(3, 4);
	sq.showarea();

	system("pause");
}

int main()
{
	Tri tri(10, 2);
	Squre sq(3, 4);

	printS(&tri);
	printS(&sq);

	system("pause");
}
