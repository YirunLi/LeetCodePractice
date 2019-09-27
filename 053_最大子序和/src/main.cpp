/*
	Create by xiaorun on August th, 2019.
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

*/

#include <iostream>
#include <vector>

using namespace std;

// 思路：
int maxInt(int a, int b)
{
	return a > b ? a : b;
}

int maxInt3(int a, int b, int c)
{
	int max1 = maxInt(a, b);
	return maxInt(max1, c);
}

// 方法1：动态规划
// 空间复杂度O(N)
int maxSubArray1(vector<int>& nums) {
	if (nums.size() <= 0)
		return 0;

	
	vector<int> a;
	a.resize(nums.size());
	fill(a.begin(), a.end(), 0);
	a[0] = nums[0];

	int max = nums[0];
	for (size_t i = 1; i < nums.size(); i++)
	{
		a[i] = maxInt(a[i - 1] + nums[i], nums[i]);
		if (a[i] > max)
			max = a[i];
	}

	return max;
}

// 方法1：动态规划
// 空间复杂度O(1)
int maxSubArray2(vector<int>& nums) {
	if (nums.size() <= 0)
		return 0;

	int pre = nums[0];
	int max = nums[0];

	for (size_t i = 1; i < nums.size(); i++)
	{
		pre = maxInt(pre + nums[i], nums[i]);
		if (pre > max)
			max = pre;
	}

	return max;
}

// 方法2：分治法
int maxSubArrayDivid(vector<int> nums, const int start, const int end)
{
	if (start == end)
		return nums[start];

	if (start > end)
		return numeric_limits<int>::min();

	int middle = (start + end) / 2;
	int leftMax = maxSubArrayDivid(nums, start, middle - 1);
	int rightMax = maxSubArrayDivid(nums, middle + 1, end);

	int leftSqueMax = nums[middle], leftSque = nums[middle]; 

	for (int i = middle - 1; i >= start; i--)
	{
		leftSque += nums[i];
		if (leftSque > leftSqueMax)
			leftSqueMax = leftSque;
	}

	int includeMiddleMax = leftSqueMax, rightSque = leftSqueMax;

	for (int i = middle + 1; i <= end; i++)
	{
		rightSque += nums[i];
		if (rightSque > includeMiddleMax)
			includeMiddleMax = rightSque;
	}

	return maxInt3(leftMax, rightMax, includeMiddleMax);
}

int maxSubArray(vector<int>& nums) {
	if (nums.size() <= 0)
		return 0;

	return maxSubArrayDivid(nums, 0, nums.size() - 1);
}

// ==================== Test Code ====================

void Test()
{
	

}


int main(int argc, char* argv[])
{
	vector<int> arr = { -2,1,-3,4,-1,2,1,-5,4 };
	int maxSque = maxSubArray(arr);

	vector<int> arr2 = { 1, 2 };
	int maxSque2 = maxSubArray(arr2);

    return 0;
}