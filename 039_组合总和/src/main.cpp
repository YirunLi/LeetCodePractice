/*
	Create by xiaorun on August th, 2019.
	
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 思路：
// 时间复杂度分析：
vector<vector<int>> resultVec;
void DFS(vector<int> candidates, int target, int startIdx, vector<int> curVector)
{
	if (target == 0)
	{
		resultVec.push_back(curVector);
		return;
	}

	for (int i = startIdx; i < candidates.size() && candidates[i] <= target; i++)
	{
		curVector.push_back(candidates[i]);
		DFS(candidates, target - candidates[i], i, curVector);
		curVector.pop_back();
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	resultVec.clear();
	if (target == 0)
		return resultVec;

	sort(candidates.begin(), candidates.end());

	vector<int> curVector;
	DFS(candidates, target, 0, curVector);
	return resultVec;
}

// ==================== Test Code ====================

void Test(vector<int> candidates, int target)
{
	cout << "Candidates: ";
	for each (int var in candidates)
		cout << var << " ";
	cout << "Target: " << target << endl << "[" << endl;

	vector<vector<int>> list = combinationSum(candidates, target);
	for each (auto var in list)
	{
		cout << "    [ ";
		for each (int val in var)
		{
			cout << val << " ";
		}
		cout << "]"<<endl;
	}
	cout << "]" << endl;
}


int main(int argc, char* argv[])
{
	vector<int> candidates1 = { 2, 3, 6, 7 };
	int target1 = 7;
	Test(candidates1, target1);

	vector<int> candidates2 = { 2, 3, 5 };
	int target2 = 8;
	Test(candidates2, target2);

	int target3 = 0;
	Test(candidates1, target3);

    return 0;
}