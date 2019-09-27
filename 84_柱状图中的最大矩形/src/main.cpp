/*
	Create by xiaorun on August th, 2019.
	给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。

以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。

图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。

示例:

输入: [2,1,5,6,2,3]
输出: 10
*/

#include <iostream>

using namespace std;

// 思路：

// 柱状图的最大面积
// 遍历每个柱子，然后分下边几种情况。

//如果当前栈空，或者当前柱子大于栈顶柱子的高度，就将当前柱子的下标入栈
//当前柱子的高度小于栈顶柱子的高度。那么就把栈顶柱子出栈，当做解法四中
//的当前要求面积的柱子。而右边第一个小于当前柱子的下标就是当前在遍历的柱子，左边第一个小于当前柱子的下标就是当前新的栈顶。
//
// 4.升序栈（根据高度找宽）：对于每个高度来说，往左右两个方向寻找第一个比它矮的柱子，决定矩形的宽。
// 所以用高度升序栈保存索引，遇到减小的，表示找到右边界。计算这中间每个柱子的最大矩形，计算一个即出栈，这样方便每次从栈顶取索引。
// 时间复杂度：O(n)， n个数字每个会被压栈弹栈各一次。
// 空间复杂度：O(n)。用来存放栈中元素。

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


// ==================== Test Code ====================

void Test()
{
	

}


int main(int argc, char* argv[])
{
	

    return 0;
}