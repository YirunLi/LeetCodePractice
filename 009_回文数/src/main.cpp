/*
	Create by xiaorun on August th, 2019.
	判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:

输入: 121
输出: true
示例 2:

输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3:

输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。
*/

#include <iostream>

using namespace std;

// 思路：
// 时间复杂度分析：n为x的位数，O(n)
bool isPalindrome(int x) {
	if (x < 0)
		return false;
	if (x % 10 == 0 && x != 0)
		return false;

	int halfNum = 0;
	while (x>halfNum)
	{
		int tmp = x % 10;
		halfNum = halfNum * 10 + tmp;
		x /= 10;
	}

	// 当数字长度为奇数时，我们可以通过 revertedNumber/10 去除处于中位的数字。
	// 例如，当输入为 12321 时，在 while 循环的末尾我们可以得到 x = 12，revertedNumber = 123，
	// 由于处于中位的数字不影响回文（它总是与自己相等），所以我们可以简单地将其去除。
	return halfNum == x || x == halfNum / 10;
}

// ==================== Test Code ====================

void Test()
{
	

}


int main(int argc, char* argv[])
{
	bool b1 = isPalindrome(1221);
	bool b2 = isPalindrome(121);
	bool b3 = isPalindrome(1);

    return 0;
}