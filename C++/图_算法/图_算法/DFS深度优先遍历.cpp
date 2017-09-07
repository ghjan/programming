#include <iostream>
using namespace std;

#define ElemType char
#define EdgeType int
#define MAXNUM	 100
int visited[MAXNUM];//���ʱ�ʶ���� 

class Graph
{
public:
	ElemType value[MAXNUM];
	EdgeType edges[MAXNUM][MAXNUM];
	int n;//�ڵ����
	int e;//����
};

void createMGraph(Graph *G);

void DFS(Graph *G, int ivex)
{
	if (!G)
		return;
	visited[ivex] = 1;
	cout << G->value[ivex] << "\t";
	for (int i = 0; i < G->n; i++)
	{
		if (!visited[i] && G->edges[ivex][i])
		{
			visited[i] = 1;//1��ʾ�Ѿ�������
			DFS(G, i);
			return;
		}
	}
	/*�����ǰ�ڵ���·���ߣ�but���е�û�б�����*/
	int j = 0;
	for (; j < G->n; j++)
	{
		if (!visited[j])
		{
			visited[j] = 1;//1��ʾ�Ѿ�������
			DFS(G, j);
			return;
		}
	}
}

int main3()
{
	Graph* G = new Graph;
	createMGraph(G);
	DFS(G, 0);
	system("pause");
	return 0;
}
