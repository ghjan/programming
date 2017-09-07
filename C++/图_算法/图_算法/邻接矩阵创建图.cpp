#include <iostream>
using namespace std;

#define ElemType char
#define EdgeType int
#define MAXNUM	 100
class Graph
{
public:
	ElemType value[MAXNUM];
	EdgeType edges[MAXNUM][MAXNUM];
	int n;//�ڵ����
	int e;//����
};

/*����ͼ�洢*/
void createMGraph(Graph *G)
{
	int n, e, value, x, y;
	char ch;
	cout << "������ �ڵ���� ����" << endl;
	cin >> n >> e;
	G->n = n;
	G->e = e;

	/*��ʼ��ͼde �� ������ɴ����ͬ���ʾ��0*/
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			G->edges[i][j] = 0;

	cout << "�����붨���" << endl;
	/*���������*/
	for (int i = 0; i < n; i++)
	{
		cin >> ch;
		G->value[i] = ch;
	}
	/*�����ڽӾ���*/
	for (int i = 0; i < 2 * e; i++)
	{
		cin >> x >> y >> value;
		G->edges[x][y] = value;
	}
}
/*����ͼ�����Ż���ֻ��Ҫ�洢�ڽӾ���������ǻ��������Ǿ����ˣ�������Ҫ������������������*/
/*����ͼ������ͼһ����ֻ������ı��������һ��*/
void MyPrint(Graph *G)
{
	int n = G->n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << G->edges[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	Graph* G = new Graph;
	createMGraph(G);
	MyPrint(G);
	system("pause");
	return 0;
}
/*
5 7
A B C D E
0 1 9
0 2 6
0 3 3
1 0 9
1 2 4
1 3 5
2 0 6
2 1 4
2 4 7
3 1 5
3 0 3
3 4 8
4 3 8
4 2 7
*/