/*
	Create by xiaorun on August th, 2019.
	
*/

#include <iostream>
#include <vector>

using namespace std;

// 思路：
// 时间复杂度分析：时间复杂度为O(M*N),空间复杂度O(M)
int strStr(string haystack, string needle) {
	if (needle.size() <= 0)
		return 0;
	if (haystack.size() <= 0)
		return -1;

	vector<int> dp(haystack.size() + 1, 0);

	int preTmp = 0;
	for (int i = 0; i < needle.size(); i++)
	{
		for (int j = 1; j <= haystack.size(); j++)
		{				
			if (needle[i] == haystack[j - 1])
			{
				int sum = preTmp + 1;
				preTmp = dp[j];
				dp[j] = sum;
				if (dp[j] == needle.size())
					return (j - needle.size());
			}
			else
			{
				preTmp = dp[j];
				dp[j] = 0;
			}				
		}
	}

	return -1;
}

int main(int argc, char* argv[])
{
	string haystack = "mississippi";
	string needle = "mississippi";

	int idx = strStr(haystack, needle);

    return 0;
}