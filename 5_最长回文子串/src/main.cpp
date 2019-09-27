/*
	Create by xiaorun on August 11th, 2019.
	给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
*/

#include <iostream>

using namespace std;

// 思路：
string longestPalindrome(string s) {
	int longestLength = 0;
	string longestString = "";
	if (s.size() <= 0)
		return longestString;

	float baseIdx = 0.f;
	for (int i = 0; i < s.size(); i++)
	{
		int halfLength = 0;
		while ((i - halfLength) >= 0 && (i + halfLength) < s.size() && s[i - halfLength] == s[i + halfLength])
		{
			if (halfLength * 2 + 1 > longestLength)
			{
				longestLength = halfLength * 2 + 1;
				baseIdx = i;
			}
			halfLength++;
		}
	}

	for (float i = 0.5; i < s.size() - 1; i++)
	{
		int halfLength = 1;		
		while (i + 0.5 - halfLength >= 0 && i - 0.5 + halfLength < s.size() && s[i + 0.5 - halfLength] == s[i - 0.5 + halfLength])
		{
			if (halfLength * 2 > longestLength)
			{
				longestLength = halfLength * 2;
				baseIdx = i;
			}
			halfLength++;
		}
	}

	if (longestLength & 1)
	{
		int halfLength = (longestLength - 1) / 2;
		for (size_t i = baseIdx - halfLength; i <= baseIdx + halfLength; i++)
			longestString += s[i];
	}
	else
	{
		int halfLength = longestLength / 2;
		for (size_t i = baseIdx + 0.5 - halfLength; i <= baseIdx - 0.5 + halfLength; i++)
			longestString += s[i];
	}

	return longestString;
}


// ==================== Test Code ====================

void Test()
{
	

}


int main(int argc, char* argv[])
{
	string s1 = "babad";
	//string resultStr1 = longestPalindrome(s1);

	string s2 = "bb";
	string resultStr2 = longestPalindrome(s2);

    return 0;
}