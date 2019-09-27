/*
	Create by xiaorun on August th, 2019.
	������Ӿ���Ĵ�С
	����һ�������� 0 �� 1 �Ķ�ά�����ƾ����ҳ�ֻ���� 1 �������Σ��������������

	ʾ��:

����:
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

// ˼·�������ⰴ�зֿ���ת��Ϊÿ�е���״ͼ��������

// ��״ͼ��������
// ����ÿ�����ӣ�Ȼ����±߼��������

//�����ǰջ�գ����ߵ�ǰ���Ӵ���ջ�����ӵĸ߶ȣ��ͽ���ǰ���ӵ��±���ջ
//��ǰ���ӵĸ߶�С��ջ�����ӵĸ߶ȡ���ô�Ͱ�ջ�����ӳ�ջ�������ⷨ����
//�ĵ�ǰҪ����������ӡ����ұߵ�һ��С�ڵ�ǰ���ӵ��±���ǵ�ǰ�ڱ��������ӣ���ߵ�һ��С�ڵ�ǰ���ӵ��±���ǵ�ǰ�µ�ջ����

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

// ʱ�临�Ӷȣ�O(N*M)
// NΪ������MΪ����������ջ��ÿ�е���״ͼ��������ʱ�临�Ӷ�ΪO(M)

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