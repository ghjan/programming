#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#define MAX 100000

typedef struct {
	int parent;
	int lchild;
	int rchild;
	int weight;//Ȩֵ
	char value;//��Ҫ����ַ�
	char* code;//�����Ķ�����
}HuffmanNode;

typedef struct{
	char* code;
	int len;
}Hcode;

//����haffman��
void  huffmanTree(HuffmanNode Node[], int n)
{
	int m1, m2;//������СȨֵ��
	int x1, x2;//������СȨֵ��ʱ����¼�ýڵ��������е���� 
	//��ʼ��������
	for (int i = 0; i< 2 * n - 1; i++)
	{
		Node[i].parent = -1;
		Node[i].lchild = -1;
		Node[i].rchild = -1;
		Node[i].weight = 0;//Ȩֵ	
	}
	//����n��Ҷ�ӽڵ��Ȩֵ
	for (int i = 0; i<n; i++)
	{
		cout << "ֵ: and Ƶ��:" << endl;
		cin >> Node[i].value >> Node[i].weight;
	}
	//������
	for (int i = 0; i < n - 1; i++)//�����ڵ���һ���ڵ㣬���Ҫʣ��һ���ڵ㣬������ n - 1
	{
		m1 = m2 = MAX;//����СȨֵ��ʼ��һ���ܴ����
		x1 = x2 = 0;
		for (int j = 0; j<n + i; j++)
		{
			if (Node[j].weight < m1 && Node[j].parent == -1)//��������СȨֵ�����
			{
				m2 = m1;
				m1 = Node[j].weight;
				x2 = x1;
				x1 = j;//��¼��ǰ��СȨֵ��Node �������е����
			}
			else if (Node[j].weight < m2 && Node[j].parent == -1)//���ֵڶ�СȨֵ�����
			{
				m2 = Node[j].weight;
				x2 = j;
			}
		}
		Node[n + i].weight = Node[x1].weight + Node[x2].weight;
		Node[n + i].lchild = x1;
		Node[n + i].rchild = x2;
		//�ı��ӽڵ��parent Ϊ��ǰ�����Ľڵ�
		Node[x1].parent = n + i;
		Node[x2].parent = n + i;
	}
}

//����Ȩֵ���б���
void codeHuffman(HuffmanNode* node, int n)
{
	Hcode tempCode;
	int parent, child;
	tempCode.code = new char[n];
	for (int i = 0; i < n; i++)
	{
		tempCode.len = n;
		parent = node[i].parent;
		child = i;
		while (parent != -1)//û�и��������ѭ��
		{
			// ����ǰ�ڵ��Ǹ��ڵ�����ӣ������Ϊ0
			if (node[parent].lchild == child)
				tempCode.code[--tempCode.len] = '0';
			else if (node[parent].rchild == child)
				tempCode.code[--tempCode.len] = '1';
			child = parent;
			parent = node[parent].parent;
		}
		int len = n - tempCode.len;
		node[i].code = new char[len + 1];
		memcpy(node[i].code, tempCode.code + tempCode.len, len);
		node[i].code[len] = '\0';
	}
	delete[] tempCode.code;
}

char* getcodeHuffman(HuffmanNode* node, char* code, int n)
{
	char* buf = new char[1024];
	memset(buf, 0, sizeof(buf));
	char* c = code;
	while (*c != '\0')
	{
		for (int i = 0; i < n; i++)
		{
			if (node[i].value == *c)
			{
				strcat(buf, node[i].code);
			}
		}
		c++;
	}
	return buf;
}

void decodeHuffman(HuffmanNode* node, char *code, int n)
{
	int curt = 2 * n - 2;
	int i;
	char *c = code;
	while (*c != '\0')
	{
		for (i = curt; node[i].lchild != -1 && node[i].rchild != -1; )
		{
			if (*c == '0')
				i = node[i].lchild;
			else if (*c == '1')
				i = node[i].rchild;
			c++;
		}
		cout << node[i].value;
	}
	cout << endl;
}

void print(HuffmanNode* node, int n)
{
	for (int i = 0; i < n; i++)
		cout << node[i].value << "\t���룺" << node[i].code << endl;
}
int main()
{
	int n;
	char* code = "11101100111110010";	//����
	char* code2 = "acebdf";				//����
	while (1)
	{
		cout << "Ҫ���������ڵ�" << endl;
		cin >> n;
		HuffmanNode* Node = new HuffmanNode[2 * n - 1];
		huffmanTree(Node, n);
		codeHuffman(Node, n);
		print(Node, n);

		char * buf = getcodeHuffman(Node, code2, n);
		cout << "acebdf\t\t\t�����õ�\t " << buf << endl;
		cout << "11101100111110010\t�����õ�\t";
		decodeHuffman(Node, code, n);
	}
	system("pause");
}
/*
6
a 1
b 2
c 3
d 4
e 5
f 6
----------------------------------------------------------------
a       ���룺1110
b       ���룺1111
c       ���룺110
d       ���룺00
e       ���룺01
f       ���룺10
acebdf                  �����õ�       11101100111110010
11101100111110010       �����õ�      acebdf



*/