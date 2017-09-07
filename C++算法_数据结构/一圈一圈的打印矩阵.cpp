#include<iostream>
using namespace std;

void printCircle(int **arr, int rows, int cols, int start)
{
	int endX = cols - 1 - start;
	int endY = rows - 1 - start;
	//��ӡһ�� 
	for (int i = start; i <= endX; i++)
		cout << arr[start][i] << " ";
	//��ӡһ�� 
	for (int i = start + 1; i <= endY; i++)
		cout << arr[i][endX] << " ";
	//��ӡһ��
	for (int i = endX - 1; i >= start; i--)
		cout << arr[endY][i] << " ";
	//��ӡһ��
	for (int i = endY - 1; i>start; i--)
		cout << arr[i][start] << " ";
	cout << endl;										//��ӡҲ���״�Ҫ�ǳ�ע���к��У���Ū�������������� 
}
void printRect(int **arr, int rows, int cols)
{
	if (!arr || rows < 1 || cols < 1)
		return;
	int start = 0;
	while (start * 2 < rows && start * 2 < cols)		//������������Ե�ʱ��ܲ������뵽 ������ʲôʱ�������ӡ�� 
	{
		printCircle(arr, rows, cols, start);
		start++;
	}
}
int main()
{
	//	int arr[4][4] = { { 1, 2, 3, 4 }, { 12, 13, 14, 5 }, { 11, 16, 13, 6 }, { 10, 9, 8, 7 } }; ������Ļ�����ȥ��Ҫָ�������磺arr[][4] ������û��ͨ������ 
	int **arr = new int*[4];
	int count = 0;
	for (int i = 0; i<4; i++)
		arr[i] = new int[4];
	for (int i = 0; i<4; i++)
		for (int j = 0; j<4; j++)
			arr[i][j] = count++;

	printRect(arr, 4, 4);
}
