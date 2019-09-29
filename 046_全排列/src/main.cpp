/*
	Create by xiaorun on August th, 2019.
	
*/

#include <iostream>
#include <vector>

using namespace std;

// 思路：
// 时间复杂度分析：
vector<vector<int>> permute(vector<int>& nums) {
	vector<vector<int>> resultVec;
	if (nums.size() <= 0)
		return resultVec;

	resultVec.push_back(nums);
	for (int i = nums.size() - 1; i > 0; i--)
	{
		int length = resultVec.size();
		for (int k = 0; k < length; k++)
		{		
			for (int j = i - 1; j >= 0; j--)		
			{			
				vector<int> tmpVec = resultVec[k];
				swap(tmpVec[i], tmpVec[j]);
				resultVec.push_back(tmpVec);
			}
		}		
	}

	return resultVec;
}

vector<vector<int>> resultVec2;
void backTrack(vector<int> list, int startIdx)
{
	if (startIdx == list.size() - 1)
		resultVec2.push_back(list);

	for (int i = startIdx; i < list.size(); i++)
	{		
		swap(list[i], list[startIdx]);
		backTrack(list, startIdx + 1);
	}
}

vector<vector<int>> permute2(vector<int> nums) {
	resultVec2.clear();
	if (nums.size() <= 0)
		return resultVec2;

	backTrack(nums, 0);
	return resultVec2;
}

// ==================== Test Code ====================

void Test(vector<int> nums)
{
	cout << "Nums: " << endl;
	for each (int var in nums)
		cout << var << " ";
	cout << endl;
	vector<vector<int>> resultVec = permute2(nums);

	for (size_t i = 0; i < resultVec.size(); i++)
	{
		for (size_t j = 0; j < resultVec[i].size(); j++)
			cout << resultVec[i][j] << " ";
		cout << endl;
	}
}


int main(int argc, char* argv[])
{
	vector<int> nums = { 1,2,3,4 };
	Test(nums);

    return 0;
}