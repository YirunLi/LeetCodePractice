/*
	Create by xiaorun on August th, 2019.
	例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。

*/

#include <iostream>
#include <unordered_map>

using namespace std;

// 思路：
int romanToInt(string s) {
	unordered_map<string, int> map;
	map.insert(make_pair("I", 1));
	map.insert(make_pair("IV", 4));
	map.insert(make_pair("V", 5));
	map.insert(make_pair("IX", 9));
	map.insert(make_pair("X", 10));
	map.insert(make_pair("XL", 40));
	map.insert(make_pair("L", 50));
	map.insert(make_pair("XC", 90));
	map.insert(make_pair("C", 100));
	map.insert(make_pair("CD", 400));
	map.insert(make_pair("D", 500));
	map.insert(make_pair("CM", 900));
	map.insert(make_pair("M", 1000));

	int resultNum = 0;
	if (s.size() <= 0)
		return resultNum;

	for (size_t i = 0; i < s.size(); i++)
	{
		string str = "";
		str += s[i];
		if (i+1 < s.size())
		{
			string strTmp = "";
			strTmp = s[i+1];
			if (map[str] < map[strTmp])
			{
				str += strTmp;
				i++;
			}				
		}
		resultNum += map[str];

	}

	return resultNum;
}


// ==================== Test Code ====================

void Test()
{
	

}


int main(int argc, char* argv[])
{
	/*string str1 = "III";
	int resultNum1 = romanToInt(str1);

	string str2 = "IV";
	int resultNum2 = romanToInt(str2);*/
	
	string str3 = "MCMXCIV";
	int resultNum3 = romanToInt(str3);
	

    return 0;
}