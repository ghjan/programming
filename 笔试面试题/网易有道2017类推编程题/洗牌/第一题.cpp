#include <iostream>
using namespace std;

//这个错误太深刻了，对自己掌握的基础知识实在很担心啊。
//创建数组一开始这样创建：int* res = new int(2*n);
//在牛客始终通不过，老是提示内存访问异常，但是在自己机子上跑用例没啥问题。。纠结了几个小时
// 现在终于知道了， int* res = new int(5)   等价于  int* res = new int  ,  *res = 5;
//在自己电脑上能跑通过，可能没有关是否内存访问异常，我访问了没有申请空间的内存，虽然理论上是可以的，但是实际上不合法，不能访问非法空间 
int* change(int* a, int n)
{
	int* res = new int[2 * n];
	for (int i = 0; i < n; i++)
	{
		res[2*i] = a[i];
		res[2*i + 1] = a[n + i];
	}
	return res;
}

int main()
{
	int T;
	int n, k,j;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> n >> k;
		int* res = new int[2 * n];
		for (j = 0; j < 2 * n; j++)
			cin >> res[j];
		for (j = 0; j < k; j++)
			res = change(res, n);
		for (j = 0; j < 2 * n - 1; j++)
			cout << res[j] << " ";
		cout << res[j] << endl;
		delete[] res;
	}
	
	system("pause");

	return 0;
}

/*
洗牌在生活中十分常见，现在需要写一个程序模拟洗牌的过程。 
现在需要洗2n张牌，从上到下依次是第1张，第2张，第3张一直到第2n张。
首先，我们把这2n张牌分成两堆，左手拿着第1张到第n张（上半堆），右手拿着第n+1张到第2n张（下半堆）。
接着就开始洗牌的过程，先放下右手的最后一张牌，再放下左手的最后一张牌，接着放下右手的倒数第二张牌，
再放下左手的倒数第二张牌，直到最后放下左手的第一张牌。接着把牌合并起来就可以了。 
例如有6张牌，最开始牌的序列是1,2,3,4,5,6。首先分成两组，左手拿着1,2,3；右手拿着4,5,6。
在洗牌过程中按顺序放下了6,3,5,2,4,1。把这六张牌再次合成一组牌之后，我们按照从上往下的顺序看这组牌，
就变成了序列1,4,2,5,3,6。 现在给出一个原始牌组，请输出这副牌洗牌k次之后从上往下的序列。
输入描述:
第一行一个数T(T ≤ 100)，表示数据组数。对于每组数据，第一行两个数n,k(1 ≤ n,k ≤ 100)，
接下来一行有2n个数a1,a2,...,a2n(1 ≤ ai ≤ 1000000000)。表示原始牌组从上到下的序列。


输出描述:
对于每组数据，输出一行，最终的序列。数字之间用空格隔开，不要在行末输出多余的空格。
*/