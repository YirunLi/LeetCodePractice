/*
	Create by xiaorun on August th, 2019.
	给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
	在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
	找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

*/

#include <iostream>
#include <vector>

using namespace std;

// 思路：
int minNum(int a, int b)
{
	return a < b ? a : b;
}

int maxArea(vector<int>& height) {
	if (height.size() <= 0)
		return 0;
	int leftPtr = 0;
	int rightPtr = height.size() - 1;

	int maxS = 0;
	while (leftPtr < rightPtr)
	{
		int area = (rightPtr - leftPtr)*minNum(height[leftPtr], height[rightPtr]);
		if (area > maxS)
			maxS = area;

		if (height[leftPtr] < height[rightPtr])
			leftPtr++;
		else if (height[leftPtr] > height[rightPtr])
			rightPtr--;
		else
		{
			if (height[leftPtr + 1] > height[rightPtr - 1])
				leftPtr++;
			else
				rightPtr--;
		}
	}

	return maxS;
	
}


// ==================== Test Code ====================

void Test()
{
	

}


int main(int argc, char* argv[])
{
	

    return 0;
}