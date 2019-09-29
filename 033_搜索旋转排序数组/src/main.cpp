/*
	Create by xiaorun on August th, 2019.
	假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 O(log n) 级别。

示例 1:

输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
示例 2:

输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1

*/

#include <iostream>
#include <vector>

using namespace std;

// 思路：
// 时间复杂度分析：二分查找，所以复杂度为O(logN)
int search(vector<int>& nums, int target) {
	if (nums.size() <= 0)
		return -1;

	int start = 0;
	int end = nums.size() - 1;
	while (start <= end)
	{
		int mid = (start + end) >> 1;
		if (nums[mid] == target)
			return mid;
		
		if (nums[mid] >= nums[start])
		{				
			if (nums[mid] > target && nums[start] <= target)
				end = mid - 1;
			else
				start = mid + 1;
		}
		else
		{
			if (nums[mid] < target && nums[end] >= target)
				start = mid + 1;
			else
				end = mid - 1;
		}
	}

	return -1;
}
// ==================== Test Code ====================

void Test(vector<int> nums, int target)
{
	cout << "Nums:" << endl;
	for each (auto var in nums)
	{
		cout << var << " ";
	}
	cout << endl << "Target: " << target << endl;
	int index = search(nums, target);
	cout << "Index: " << index << endl;
}


int main(int argc, char* argv[])
{
	//vector<int> nums1 = { 4,5,6,7,0,1,2 };
	//int target1 = 1;
	//int target2 = 5;
	//int target3 = -1;
	//Test(nums1, target1);
	//Test(nums1, target2);
	//Test(nums1, target3);

	vector<int> nums2 = { 3,1 };
	for (auto val : nums2)
	{
		Test(nums2, val);
	}

    return 0;
}