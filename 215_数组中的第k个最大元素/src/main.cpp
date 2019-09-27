/*
	Create by xiaorun on August th, 2019.
	��δ������������ҵ��� k ������Ԫ�ء���ע�⣬����Ҫ�ҵ������������ĵ� k ������Ԫ�أ������ǵ� k ����ͬ��Ԫ�ء�
*/

#include <iostream>
#include <vector>

using namespace std;

// ˼·��
void Swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int Partition(vector<int> &nums, int startIdx, int endIdx)
{
	//int randomIdx = rand() % (endIdx - startIdx) + startIdx;
	int randomIdx = (startIdx + endIdx) / 2;
	Swap(nums[randomIdx], nums[endIdx]);

	int bigIdx = startIdx;
	for (int i = startIdx; i < endIdx; i++)
	{
		if (nums[i] > nums[endIdx])
		{
			if(bigIdx != i)
				Swap(nums[bigIdx], nums[i]);
			bigIdx++;
		}
			
	}

	Swap(nums[bigIdx], nums[endIdx]);
	return bigIdx;
}

void QuickSort(vector<int>& nums, int startIdx, int endIdx)
{
	if (startIdx >= endIdx)
		return;

	int idx = Partition(nums, startIdx, endIdx);
	QuickSort(nums, startIdx, idx - 1);
	QuickSort(nums, idx + 1, endIdx);
}

int KthLargest;

void findKthLargestCore(vector<int>& nums, int k, int startIdx, int endIdx) {
	int idx = Partition(nums, startIdx, endIdx);
	if (idx == k)
	{
		KthLargest = nums[k];
		return;
	}		
	else
	{
		if (idx > k)
			findKthLargestCore(nums, k, startIdx, idx-1);
		else
			findKthLargestCore(nums, k, idx+1, endIdx);
	}
}

int findKthLargest(vector<int>& nums, int k) {
	findKthLargestCore(nums, k-1, 0, nums.size() - 1);
	return KthLargest;
}


// ==================== Test Code ====================

void Test()
{
	

}


int main(int argc, char* argv[])
{
	vector<int> array = { 3,2,1,5,6,4 };
	//QuickSort(array, 0, array.size() - 1);

	int kth = findKthLargest(array, 2);

    return 0;
}