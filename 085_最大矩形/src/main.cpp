/*
	Create by xiaorun on August th, 2019.
	求最大子矩阵的大小
	给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。

	示例:

输入:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// 思路：将问题按行分开，转换为每行的柱状图的最大面积

// 柱状图的最大面积
// 遍历每个柱子，然后分下边几种情况。

//如果当前栈空，或者当前柱子大于栈顶柱子的高度，就将当前柱子的下标入栈
//当前柱子的高度小于栈顶柱子的高度。那么就把栈顶柱子出栈，当做解法四中
//的当前要求面积的柱子。而右边第一个小于当前柱子的下标就是当前在遍历的柱子，左边第一个小于当前柱子的下标就是当前新的栈顶。

int largestRectangleArea(vector<int>& heights)
{
	if (heights.size() <= 0)
		return 0;

	stack<int> increaseIndexStack;
	int maxArea = 0;

	int currIdx = 0;
	
	while (currIdx < heights.size() || !increaseIndexStack.empty()) 
	{
		if (!increaseIndexStack.empty() && (currIdx == heights.size() || heights[currIdx] < heights[increaseIndexStack.top()]))
		{
			int idx = increaseIndexStack.top();
			increaseIndexStack.pop();
			int h = heights[idx];
			int l = increaseIndexStack.empty() ? currIdx : currIdx - 1 - increaseIndexStack.top();
			int area = h * l;
			if (area > maxArea)
				maxArea = area;
		}
		else if(currIdx < heights.size())
			increaseIndexStack.push(currIdx++);
	}

	return maxArea;
}

// 时间复杂度：O(N*M)
// N为行数，M为列数。利用栈求每行的柱状图最大面积的时间复杂度为O(M)

int maximalRectangle(vector<vector<char>>& matrix) {
	if (matrix.size() <= 0)
		return 0;

	vector<int> heights;
	heights.resize(matrix[0].size());
	fill(heights.begin(), heights.end(), 0);
	
	int maxArea = 0;

	for (size_t i = 0; i < matrix.size(); i++)
	{
		for (size_t j = 0; j < matrix[0].size(); j++)
		{
			if (matrix[i][j] == '1')
				heights[j] += 1;
			else
				heights[j] = 0;
		}
		maxArea = max(maxArea, largestRectangleArea(heights));
	}

	return maxArea;
}


// ==================== Test Code ====================

void Test()
{
	

}


int main(int argc, char* argv[])
{
	vector<int> arr = { 2,1,5,6,2,3 };
	int maxArea = largestRectangleArea(arr);

	vector<vector<char> > matrix = { {'1','0','1','0','0' },
														  {'1','0','1','1','1' },
														  {'1','1','1','1','1' },
														  {'1', '0', '0', '1', '0'} };
	int maxRectSize = maximalRectangle(matrix);

    return 0;
}