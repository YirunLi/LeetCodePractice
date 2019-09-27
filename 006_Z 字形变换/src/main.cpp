/*
	Create by xiaorun on August th, 2019.
	将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

L    C     I     R
E T O E S  I  I  G
E    D    H    N
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
示例 1:

输入: s = "LEETCODEISHIRING", numRows = 3
输出: "LCIRETOESIIGEDHN"
示例 2:

输入: s = "LEETCODEISHIRING", numRows = 4
输出: "LDREOEIIECIHNTSG"
解释:

L         D      R
E    O  E     I  I
E  C     I  H   N
T        S        G

*/

#include <iostream>
#include <vector>

using namespace std;

// 思路：按行输出
// 时间复杂度分析：O（n）
string convert(string s, int numRows)
{
	if (s.size() <= 0)
		return "";
	if (numRows <= 1)
		return s;

	vector<string> strRow;
	strRow.resize(numRows);
	fill(strRow.begin(), strRow.end(), "");
	for (int i = 0; i < s.size(); i++)
	{
		int loopNum = 2 * numRows - 2;
		int idx = i % loopNum;
		idx = idx > numRows - 1 ? loopNum - idx : idx;
		strRow[idx] += s[i];
	}

	string resultStr = "";
	for (int i = 0; i < numRows; i++)
		resultStr += strRow[i];

	return resultStr;
}

// ==================== Test Code ====================

void Test()
{
	

}


int main(int argc, char* argv[])
{
	string s = "LEETCODEISHIRING";
	string cvtStr1 = convert(s, 3);
	string cvtStr2 = convert(s, 4);

    return 0;
}