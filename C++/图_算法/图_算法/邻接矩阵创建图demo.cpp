#include <iostream>
using namespace std;

#define MaxVertexNum 100 /*��󶥵�����Ϊ100*/
typedef char VertexType; /*����������Ϊ�ַ���*/
typedef int EdgeType; /*�ߵ�Ȩֵ��Ϊ����*/

typedef struct {
	VertexType vexs[MaxVertexNum]; /*�����*/
	EdgeType edges[MaxVertexNum][MaxVertexNum]; /*�ڽӾ��󣬼��߱�*/
	int n, e; /*�������ͱ���*/
}Mgragh; /*Maragh �����ڽӾ���洢��ͼ����*/

//����һ��ͼ���ڽӾ���洢���㷨���£�
void CreateMGraph(Mgragh *G)
{
	int i, j, k, w, value;
	char ch;
	printf("�����붥�����ͱ���\n");
	cin >> G->n >> G->e;/*���붥�����ͱ���*/
	printf("�����붥����Ϣ(�����ʽΪ:�����):\n");
	for (i = 0; i<G->n; i++)
		cin >> G->vexs[i]; /*���붥����Ϣ�����������*/

	/*��ʼ���ڽӾ���*/
	for (i = 0; i<G->n; i++)
		for (j = 0; j<G->n; j++)
			G->edges[i][j] = 0;

	printf("������ÿ���߶�Ӧ��������������(�����ʽΪ:i j):\n");
	for (k = 0; k < 2 * G->e; k++)
	{
		cin >> i >> j >> value;
		G->edges[i][j] = value;
	}
}
void print(Mgragh *G)
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
int main1()
{
	Mgragh* G = new Mgragh;
	CreateMGraph(G);
	print(G);
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