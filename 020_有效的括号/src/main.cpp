/*
	Create by xiaorun on August th, 2019.
	给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false
示例 4:

输入: "([)]"
输出: false
示例 5:

输入: "{[]}"
输出: true

*/

#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

// 思路：
bool isValid(string s) {
	if (s.size() <= 0)
		return true;

	unordered_map<char, char> matchMap;
	matchMap.insert(make_pair(')', '('));
	matchMap.insert(make_pair('}', '{'));
	matchMap.insert(make_pair(']', '['));

	stack<char> tmpStack;

	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] == ')' || s[i] == '}' || s[i] == ']')
		{
			if (tmpStack.empty())
				return false;
			else
			{
				if (tmpStack.top() != matchMap[s[i]])
					return false;
				else
					tmpStack.pop();
			}
		}
		else
			tmpStack.push(s[i]);
	}

	return tmpStack.empty();
}


// ==================== Test Code ====================

void Test()
{
	

}


int main(int argc, char* argv[])
{
	string s1 = "()";
	cout << isVilid(s1);

	string s2 = "()[]{}";
	cout << isVilid(s2);

	string s3 = "(]";
	cout << isVilid(s3);

	string s4 = "([)]";
	cout << isVilid(s4);

	string s5 = "{[]}";
	cout << isVilid(s5);

    return 0;
}