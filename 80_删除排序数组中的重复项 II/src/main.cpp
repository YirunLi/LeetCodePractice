/*
	Create by xiaorun on August th, 2019.
	
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 思路：
// 时间复杂度分析：
int removeDuplicates(vector<int>& nums) {
	int curIdx = 0;
	int i = 0;
	//for(int i = 0; i < nums.size(); i++)
	while (i < nums.size())
	{
		int j = 1;
		while ((i + j) < nums.size() && nums[i + j] == nums[i])
			++j;

		int length = min(j, 2);
		for (int k = 0; k < length; k++)
			nums[curIdx + k] = nums[i];

		i = i + j;
		curIdx += length;
	}
	return curIdx;
}


// ==================== Test Code ====================

void Test()
{
	

}


int main(int argc, char* argv[])
{
	vector<int> arr = { 1,1,1,2,2,3 };
	int length = removeDuplicates(arr);
	for (size_t i = 0; i < length; i++)
	{
		cout << arr[i] << ",";
	}

    return 0;
}