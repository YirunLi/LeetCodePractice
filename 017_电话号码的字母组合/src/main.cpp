/*
	Create by xiaorun on August 7th, 2019.
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

// 思路：利用递归方法解决
vector<string> strVec;
unordered_map<char, string> vecList;

void InitialVectors()
{
	string str2 = "abc";
	vecList.insert(make_pair('2', str2));
	string str3 = "def";
	vecList.insert(make_pair('3', str3));
	string str4 = "ghi";
	vecList.insert(make_pair('4', str4));
	string str5 = "jkl";
	vecList.insert(make_pair('5', str5));
	string str6 = "mno";
	vecList.insert(make_pair('6', str6));
	string str7 = "pqrs";
	vecList.insert(make_pair('7', str7));
	string str8 = "tuv";
	vecList.insert(make_pair('8', str8));
	string str9 = "wxyz";
	vecList.insert(make_pair('9', str9));
}



void GetStrVec(const char* digits, string str)
{
	if (*digits == '\0')
	{
		strVec.push_back(str);
		return;
	}		

	string tgtStr = vecList[*digits];
	for (size_t i = 0; i < tgtStr.size(); i++)
	{
		str += tgtStr[i];
		GetStrVec(digits + 1, str);
		str.pop_back();
	}
}

vector<string> letterCombinations(string digits) {
	strVec.clear();
	if (digits.size() <= 0)
		return strVec;

	//unordered_map<char, string> vecList;
	InitialVectors();
	string str = "";

	GetStrVec(digits.c_str(), str);

	return strVec;
}


// ==================== Test Code ====================

void Test()
{
	

}


int main(int argc, char* argv[])
{
	string testStr = "23";
	vector<string> result = letterCombinations(testStr);

    return 0;
}