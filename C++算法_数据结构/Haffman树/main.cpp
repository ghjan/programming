#include <iostream>
using namespace std;
#define MAX 100000

typedef struct {
	int parent;
	int lchild;
	int rchild;
	int weight;
}HuffmanNode;

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
		printf("Please input weight of leaf node %d:\n", i);
		cin >> Node[i].weight;
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
		//�Ѿ��ҵ�������СȨֵ�����ڹ����µ�Node����С����ȨֵNode�ĸ��ࣩ
		Node[n + i].weight = Node[x1].weight + Node[x2].weight;
		Node[n + i].lchild = x1;
		Node[n + i].rchild = x2;
		//�ı��ӽڵ��parent Ϊ��ǰ�����Ľڵ�
		Node[x1].parent = n + i;
		Node[x2].parent = n + i;

		//���涼�ǲ��Դ���
		cout << "��" << i + 1 << "�κϲ�" << "\t��������" << Node[x1].weight << "\t��������" << Node[x2].weight << "\t���ڵ㣺"<< Node[n + i].weight << endl;
	}

}
int main()
{
	int n;
	cout << "Ҫ���������ڵ�" << endl;
	cin >> n;
	HuffmanNode* Node = new HuffmanNode[2 * n - 1];
	huffmanTree(Node, n);
}
/*
5
18
4
9
8
6
*/
