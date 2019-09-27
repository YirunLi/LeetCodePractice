/*
	Create by xiaorun on August th, 2019.
	给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。
	滑动窗口每次只向右移动一位。

	返回滑动窗口中的最大值。

*/

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

// 思路：
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	vector<int> maxNumVec;
	if (k > nums.size() || k <= 0)
		return maxNumVec;

	deque<int> possibleMaxIdx;

	for (int i = 0; i < nums.size(); i++)
	{
		if (!possibleMaxIdx.empty())
		{
			//possibleMax.
			if (possibleMaxIdx.front() <= i - k)
				possibleMaxIdx.pop_front();

			while (!possibleMaxIdx.empty())
			{
				auto it = possibleMaxIdx.back(); 
				if (nums[i] > nums[it])
					possibleMaxIdx.pop_back();
				else
					break;
			}
			
		}
		possibleMaxIdx.push_back(i);

		if (i + 1 >= k)
			maxNumVec.push_back(nums[possibleMaxIdx.front()]);
	}

	return maxNumVec;
}


// ==================== Test Code ====================

void Test()
{
	

}


int main(int argc, char* argv[])
{
	vector<int> array = { 9,10,9,-7,-4,-8,2,-6 };

	vector<int> maxNumVec = maxSlidingWindow(array, 5);

    return 0;
}