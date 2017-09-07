//����Ȼ��N�ֽ�����ɸ�������ͬ��������֮�ͣ�ʹ�˻����
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
//��һ������n����n�ֽ�����ɸ���ͬ��Ȼ��֮�ͣ�����ηֽ���ʹ��Щ���ĳ˻�����������˻�m 
#define maxn 109
using namespace std;
long long dp[maxn][maxn];
int solve(int n){
	long long ans = 0;
	for(int i = 0; i <= n; i++)
		ans = max(ans, dp[n][i]);
	return ans;
}
int main(){
	int n;
	cin >> n;
	for(int i = 0; i <= n; i++)
		dp[0][i] = 1;					//Ϊʲô��ʼ������1�� ��ΪҪ��˻������ 7 �� ���� 0 + 7  ����˵�˻������0����7 
	for(int i = 1; i <= n; i++)			//������1 - n ֮����������� 
		for(int j = 1; j <= i; j++)		//���� i ���Ҫ�ֽ���� 
			for(int k = 0 ; k < j; k++)	//��Ϊ�ǲ�ͬ����Ȼ������k!=j 
				dp[i][j] = max(dp[i][j], dp[i - j][k] * j);//Ҫ�˻������Ҫ�õ����ǰ�˻�����ֵ 
	cout << solve(n) << endl;
	
	for(int i = 0;i<=n;i++)
	{
		for(int j = 0;j<=n;j++)
			cout<<dp[i][j]<<"\t";
		cout<<endl;
	}
	return 0;
}
