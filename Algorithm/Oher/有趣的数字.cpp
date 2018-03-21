/*
小Q今天在上厕所时想到了这个问题：有n个数，两两组成二元组，差最小的有多少对呢？差最大呢？


输入描述:

输入包含多组测试数据。

对于每组测试数据：

N - 本组测试数据有n个数

a1,a2...an - 需要计算的数据

保证:

1<=N<=100000,0<=ai<=INT_MAX.




输出描述:

对于每组数据，输出两个数，第一个数表示差最小的对数，第二个数表示差最大的对数。


输入例子1:
6
45 12 45 32 5 6

输出例子1:
1 2
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void result(vector<int>&a, int n);
int main()
{
	int num;
	while (cin >> num)
	{
		int temp;
		vector<int>data;
		for (int i = 0; i < num; ++i)
		{
			cin >> temp;
			data.push_back(temp);
		}
		result(data, num);
	}
	return 0;
}

void result(vector<int>&a, int n)
{
	if (n > 1)
	{
		sort(a.begin(), a.end());
		int m1 = 1;
		int m2 = 1;
		for (int i = 0; i < n - 1; ++i)
		{
			if (a[i + 1] != a[i])
				break;
			++m1;
		}
		for (int i = n - 1; i > 0; --i)
		{
			if (a[i - 1] != a[i])
				break;
			++m2;
		}
		int max = m1*m2;

		int min_temp = a[1] - a[0];
		int min = 0;
		for (int i = 2; i < n; ++i)
			if (a[i] - a[i - 1] < min_temp)
				min_temp = a[i] - a[i - 1];
		if (min_temp == 0)
		{
			for (int i = 1; i < n; ++i)
			{
				int j = i - 1;
				while (j >= 0 && a[j] == a[i])
				{
					++min;
					--j;
				}
			}
		}
		else
		{
			for (int i = 1; i < n; ++i)
				if (a[i] - a[i - 1] == min_temp)
					++min;
		}
		cout << min << ' ' << max << endl;
	}
}
