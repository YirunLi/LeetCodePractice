/*
	Create by xiaorun on August th, 2019.
	
*/

#include <iostream>
#include  <vector>

using namespace std;

// 思路：
// 时间复杂度分析：
vector<int> spiralOrder(vector<vector<int>>& matrix)
{
	vector<int> printMatrix;
	int up = 0;
	int down = matrix.size() - 1;
	if (down < 0)
		return printMatrix;
	int left = 0;
	int right = matrix[0].size() - 1;
	if (right < 0)
		return printMatrix;

	while (true)
	{
		for (int i = left; i <= right; i++)
			printMatrix.push_back(matrix[up][i]);
		++up;
		if (up > down)	break;

		for (int i = up; i <= down; i++)
			printMatrix.push_back(matrix[i][right]);
		--right;
		if (right < left)	break;

		for (int i = right; i >= left; i--)
			printMatrix.push_back(matrix[down][i]);
		--down;
		if (down < up)	break;

		for (int i = down; i >= up; i--)
			printMatrix.push_back(matrix[i][left]);
		++left;
		if (left > right)	break;
	}

	return printMatrix;
}

// ==================== Test Code ====================

void Test()
{
	

}


int main(int argc, char* argv[])
{
	vector<int> arr1 = { 1, 2, 3 };
	vector<int> arr2 = { 5, 6, 7 };
	vector<int> arr3 = { 9,10,11 };
	vector<vector<int>> matrix;
	/*matrix.push_back(arr1);
	matrix.push_back(arr2);
	matrix.push_back(arr3);*/

	auto printedMatrix = spiralOrder(matrix);

    return 0;
}