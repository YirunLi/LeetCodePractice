/*
	Create by xiaorun on August 5th, 2019.
	给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

	注意：答案中不可以包含重复的三元组。

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 思路：
/*
找组合思路：固定三个数字中最左数字的指针 k，遍历 k 找到每个k对应的所有满足nums[k] + nums[i] + nums[j] == 0的 i,j 组合。即每指向新的 nums[k]，都通过双指针法找到所有和为 00 的 nums[i]，nums[j] 并记录：
1. 当 nums[k] > 0 时直接跳出，因为 j > i > k，即三个数字都大于 00，在此k之后不可能找到组合了；
2. 当 k > 0且nums[k] == nums[k - 1]时跳过此数字k，因为 nums[k - 1] 的所有组合已经被加入到结果中，本次搜索只会搜索到重复组合。
3. i，j 分设在数组 [k, len(nums)] 两端，根据 sum 与 00 的大小关系交替向中间逼近，如果遇到等于 00 的组合则加入 res 中，需要注意：
移动 i，j 需要跳过所有重复值，以避免重复答案被计入 res。
整体算法复杂度 O(n2)O(n2)。

*/
vector<vector<int>> threeSum(vector<int>& nums) {
	int length = nums.size();
	vector<vector<int>> resultVec;
	if (length < 3)
		return resultVec;

	sort(nums.begin(), nums.end());

	for (int i = 0; i < length - 2; i++)
	{
		int front = i + 1;
		int back = length - 1;

		while (front < back)
		{
			if (nums[i] > 0)
				break;
			if (i > 0 && nums[i] == nums[i - 1])
				break;

			if (nums[i] + nums[front] + nums[back] == 0)
			{
				vector<int> tmpVec;
				tmpVec.push_back(nums[i]);
				tmpVec.push_back(nums[front]);
				tmpVec.push_back(nums[back]);
				resultVec.push_back(tmpVec);
				while (back > front && nums[back] == nums[back-1])
					back--;
								
				back--;
			}
			else if (nums[i] + nums[front] + nums[back] < 0)
			{
				while (front < back && nums[front] == nums[front + 1])
					front++;
				front++;
			}

			else
			{
				while (back > front && nums[back] == nums[back - 1])
					back--;
				back--;
			}
			
		}
	}

	return resultVec;
}


// ==================== Test Code ====================

void Test()
{
	

}


int main(int argc, char* argv[])
{
	vector<int> array = { -2,-3,0,0,-2 };
	auto result = threeSum(array);

	for each (auto var in result)
	{
		for each (auto tmp in var)
		{
			cout << tmp << " ";
		}
		cout << endl;
	}

    return 0;
}