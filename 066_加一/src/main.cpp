/*
	Create by xiaorun on August th, 2019.
	给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1:

输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。
示例 2:

输入: [4,3,2,1]
输出: [4,3,2,2]
解释: 输入数组表示数字 4321。
*/

#include <iostream>
#include <vector>

using namespace std;

// 思路：
// 时间复杂度分析：
vector<int> plusOne(vector<int>& digits) {
	if (digits.size() <= 0)
		return digits;

	bool shouldPlusOne = true;
	int idx = digits.size() - 1;
	while (shouldPlusOne && idx >= 0) 
	{
		if (digits[idx] == 9)
		{
			digits[idx] = 0;
			shouldPlusOne = true;
		}
		else
		{
			digits[idx] += 1;
			shouldPlusOne = false;
		}
		--idx;
	}

	if (shouldPlusOne)
	{
		digits.push_back(1);
		int i = digits.size() - 1;
		while (i>0)
		{
			swap(digits[i], digits[i - 1]);
			i--;
		}
	}
	
	return digits;
}

// ==================== Test Code ====================

void Test(vector<int> arr)
{
	cout << "Ori array:" << endl;
	for each (auto var in arr)
		cout << var << ",";
	cout << endl;

	vector<int> arr2 = plusOne(arr);
	cout << "After plus one:" << endl;
	for each (auto var in arr2)
		cout << var << ",";
	cout << endl;
}


int main(int argc, char* argv[])
{
	vector<int> arr1 = { 0 };
	Test(arr1);
	vector<int> arr2 = { 9 };
	Test(arr2);
	vector<int> arr3 = { 9,9,9 };
	Test(arr3);
	vector<int> arr4 = { 1 };
	Test(arr4);
	vector<int> arr5 = { 1,2,9,9 };
	Test(arr5);
	vector<int> arr6 = { 1,3,2,5 };
	Test(arr6);

    return 0;
}