#include <iostream>
using namespace std;

#define MAX 100
#define MAXCOST 0x7fffffff 

int prim(int graph[][MAX],int n)
{
	int lowcost[MAX];  //MAX ������ڽ���id   �����������ˣ���ǰû�м��뵽�����еĵ㣬�����ϵ���̾��� 
	int mst[MAX];
	int min,minid,sum = 0;
	for(int i = 2;i<n;i++)
	{
		lowcost[i] = graph[1][i];//��һ���㣬���ڽ���ľ���
		mst[i] = 1;
	}
	mst[1]  = 0;
	for(int i = 2; i <= n; i++)
	{
		min = MAXCOST;// ��ǰ�㵽�ڽ���ľ��� 
		minid = 0;	//����ڽ����id
		
		/*�ҵ���̾��벢��¼*/
		for(int j = 2; j <= n; j++) 
		{
			if(lowcost[j] < min && lowcost[j] != 0)
			{
				min = lowcost[j];
				minid = j;
			}
		}
		cout << "V" << mst[minid] << "-V" << minid << "=" << min << endl;
		sum += min;//���ڼ�����С������ֵ 
		lowcost[minid] = 0;//��ǰ�ڵ㵽 �Լ��϶��Ǿ�����0  ********************************************
		
		for(int j = 2; j <= n; j++) 
		{
			if(graph[minid][j] < lowcost[j])
			{
				lowcost[j] = graph[minid][j];
				mst[j] = minid;					//���ڼ����� minid -> j �ڵ�����̵� 
			}
		}
	}
	return sum;
}

int main()
{
	int graph[MAX][MAX];
	int i, j, k, m, n;
	int x, y, cost;
	cin >> m >> n;
	//��ʼ��ͼG  
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= m; j++)
		{
			graph[i][j] = MAXCOST;
		}
	}
	//����ͼG  
	for (k = 1; k <= n; k++)
	{
		cin >> i >> j >> cost;
		graph[i][j] = cost;
		graph[j][i] = cost;
	}
	//�����С������  
	cost = prim(graph, m);
	//�����СȨֵ��  
	cout << "��СȨֵ��=" << cost << endl;
	return 0;
}
/*
MST��Minimum Spanning Tree����С������������������ͨ�õĽⷨ��Prim�㷨��������֮һ�����Ǵӵ�ķ��濼�ǹ���һ��MST��
����˼���ǣ���ͼG���㼯��ΪU����������ѡ��ͼG�е�һ����Ϊ��ʼ��a�����õ���뼯��V���ٴӼ���U-V���ҵ���һ��bʹ�õ�b��V������һ���Ȩֵ��С��
��ʱ��b��Ҳ���뼯��V���Դ����ƣ����ڵļ���V={a��b}���ٴӼ���U-V���ҵ���һ��cʹ�õ�c��V������һ���Ȩֵ��С����ʱ��c����뼯��V��ֱ�����ж���ȫ��������V��
��ʱ�͹�������һ��MST����Ϊ��N�����㣬���Ը�MST����N-1���ߣ�ÿһ���򼯺�V�м���һ���㣬����ζ���ҵ�һ��MST�ıߡ�

lowcost[i]:��ʾ��iΪ�յ�ıߵ���СȨֵ,��lowcost[i]=0˵����iΪ�յ�ıߵ���СȨֵ=0,Ҳ���Ǳ�ʾi�������MST
mst[i]:��ʾ��Ӧlowcost[i]����㣬��˵����<mst[i],i>��MST��һ���ߣ���mst[i]=0��ʾ���i����MST

///////////////////////////////****************************************
�Ҹо����ѵ������		mst[2]=3 
���˺þã�����������ɶ��˼�ˣ���mst[2]=3  ����  3�Žڵ㣨�����еģ� �� 2�Žڵ�(��û���뵽������) �����·����һ���� 

6 10
1 2 6
1 3 1
1 4 5
2 3 5
2 5 3
3 4 5
3 5 6
3 6 4
4 6 2
5 6 6
*/ 
