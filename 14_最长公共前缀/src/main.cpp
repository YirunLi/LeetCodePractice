/*
	Create by xiaorun on August th, 2019.
	编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。

*/

#include <iostream>
#include <vector>

using namespace std;

// 思路：
string longestCommonPrefix(vector<string>& strs) {
	string longestPrefixStr = "";
	if (strs.size() <= 0)
		return longestPrefixStr;

	for (size_t i = 0; i < strs[0].size(); i++)
	{
		char ch = strs[0][i];
		for (size_t j = 1; j < strs.size(); j++)
		{
			if (i >= strs[j].size() || ch != strs[j][i])
				return longestPrefixStr;

		}
		longestPrefixStr += ch;
	}

	return longestPrefixStr;
}

bool isPrefix(vector<string> strs, string prefixStr)
{
	for (size_t j = 0; j < strs.size(); j++)	
	{
		for (size_t i = 0; i < prefixStr.size(); i++)
		{
			if (strs[j][i] != prefixStr[i])
				return false;
		}		
	}
	return true;
}

string longestCommonPrefix2(vector<string>& strs) {
	string longestPrefixStr = "";
	if (strs.size() <= 0)
		return longestPrefixStr;

	// 先找到最短的字符串，这是可能的最长公共前缀
	string possibleLongestPrefixStr = strs[0];
	for (size_t i = 0; i < strs.size(); i++)
	{
		if (strs[i].size() < possibleLongestPrefixStr.size())
			possibleLongestPrefixStr = strs[i];
	}

	int startIdx = 0;
	int endIdx = possibleLongestPrefixStr.size() - 1;
	string prefix = "";
	// 利用二分法	求解
	while (startIdx <= endIdx)
	{
		int idx = (startIdx + endIdx) / 2;		
		for (size_t i = 0; i <= idx; i++)
			prefix += possibleLongestPrefixStr[i];

		if (isPrefix(strs, prefix))
			startIdx = idx + 1;
		else
			endIdx = idx - 1;
		prefix.clear();
	}

	// 当endIdx<0时，代表没有相同公共子串，此时(startIdx + endIdx) / 2为0，还是会复制第一个字符，因此需要特殊处理一下
	if (endIdx < 0)
		return "";

	for (int i = 0; i <= (startIdx + endIdx) / 2; i++)
		prefix += possibleLongestPrefixStr[i];

	return prefix;
}


// ==================== Test Code ====================

void Test()
{
	

}


int main(int argc, char* argv[])
{
	string str1 = "dog";
	string str2 = "flow";
	string str3 = "asd";

	/*string str1 = "flslfj";
	string str2 = "flow";
	string str3 = "floepq";*/

	vector<string> strs;
	strs.push_back(str1);
	//strs.push_back(str2);
	//strs.push_back(str3);

	longestCommonPrefix2(strs);

    return 0;
}