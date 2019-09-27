/*
	Create by xiaorun on August th, 2019.
	
*/

#include <iostream>
#include <vector>

using namespace std;

// 思路：
// 时间复杂度分析：
void moveZeroes(vector<int>& nums) {
	int k = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i])
		{
			if (i != k)
				swap(nums[i], nums[k]);
			k++;
		}
	}
}

// ==================== Test Code ====================

void Test()
{
	

}


int main(int argc, char* argv[])
{
	vector<int> arr = { 0,1,0,3,12 };
	moveZeroes(arr);

    return 0;
}