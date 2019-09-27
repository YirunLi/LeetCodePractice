/*
	Create by xiaorun on August 5th, 2019.
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

说明:

s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。

*/

#include <iostream>

using namespace std;

// 思路：
bool isMatchCore(string s, string p, int indexS, int indexP)
{
	if (indexP == p.size())
	{
		if (indexS == s.size())
			return true;
		else
			return false;
	}

	if (indexP < p.size() - 1 && p[indexP+1] == '*')
	{
		if (indexS < s.size() && s[indexS] == p[indexP] || p[indexP] == '.' && indexS < s.size())
			return isMatchCore(s, p, indexS, indexP + 2) || isMatchCore(s, p, indexS + 1, indexP);
		else
			return isMatchCore(s, p, indexS, indexP + 2);
	}
	else
	{
		if (indexS < s.size() && s[indexS] == p[indexP] || p[indexP] == '.' && indexS < s.size())
			return isMatchCore(s, p, indexS + 1, indexP + 1);
		else
			return false;
	}
}

bool match(const char* str, const char* pattern)
{
	if (str == NULL || pattern == NULL)
		return false;

	if (*str == '\0' && *pattern == '\0')
		return true;

	if (*str != '\0' && *pattern == '\0')
		return false;

	// 如果第二位不是*
	if (*(pattern + 1) != '*')
	{
		if (*str == *pattern || *pattern == '.' && *str != '\0')
			return match(str + 1, pattern + 1);
		else
			return false;
	}
	else  //如果第二位是*
	{
		if (*str == *pattern || *pattern == '.' && *str != '\0')
			return match(str + 1, pattern) || match(str, pattern + 2);
		else
			return match(str, pattern + 2);
	}
}

bool isMatch(string s, string p) {
	if (p.size() == 0)
	{
		if (s.size() == 0)
			return true;
		else
			return false;
	}
	
	int indexS = 0;
	int indexP = 0;
	return match(s.c_str(), p.c_str());
	//return isMatchCore(s, p, indexS, indexP);
}


// ==================== Test Code ====================

void Test(string s, string p)
{
	cout << "s: " << s.c_str() << endl;
	cout << "p: " << p.c_str() << endl;
	cout << isMatch(s, p) << endl;
}


int main(int argc, char* argv[])
{
	/*string s1 = "aa", p1 = "a";
	Test(s1, p1);

	string s2 = "aa", p2 = "a*";
	Test(s2, p2);

	string s3 = "ab", p3 = ".*";
	Test(s3, p3);

	string s4 = "ab", p4 = ".*c";
	Test(s4, p4);

	string s5 = "mississippi", p5 = "mis*is*p*.";
	Test(s5, p5);*/
	
	string s6 = "aaaaaaaaaaaaab", p6 = "a*a*a*a*a*a*a*a*a*a*c";
	Test(s6, p6);
    return 0;
}