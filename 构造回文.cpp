/*
给定一个字符串s，你可以从中删除一些字符，使得剩下的串是一个回文串。如何删除才能使得回文串最长呢？
输出需要删除的字符个数。

输入描述:

输入数据有多组，每组包含一个字符串s，且保证:1<=s.length<=1000.
  
输出描述:

对于每组的数据，输出一个整数，代表最少需要删除的字符个数。

输入例子1:
abcda
google

输出例子1:
2
2
*/

/*利用回文的性质，将其中一个string反转后，只需求两个string的最大公共子序列即可，这里使用DP*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define MAX 1001
int maxlen[MAX][MAX];
int Maxlen(string s1, string s2)
{

	int length1 = s1.size();
	int length2 = s2.size();
	for (int i = 1; i <= length1; i++)
	{
		for (int j = 1; j <= length2; j++)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				maxlen[i][j] = maxlen[i - 1][j - 1]+1;
			}
			else {
				maxlen[i][j] = max(maxlen[i - 1][j], maxlen[i][j - 1]);
			}
		}
	}
	return maxlen[length1][length2];
	
}
int main()
{
	string s = "123";
	cout << s.length();
	cout << sizeof(s);
	getchar();
	getchar();
}