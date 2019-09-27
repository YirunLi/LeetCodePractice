/*
	Create by xiaorun on August th, 2019.
	给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

	请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

	你可以假设 nums1 和 nums2 不会同时为空。

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 思路：构建一个最大堆，存储小于中位数的数，构建一个最小堆存储大于中位数的数，插入的过程中时刻保证两堆相等或最大堆比最小堆多一个元素
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	priority_queue<int, vector<int>, greater<int> > minHeap;
	priority_queue<int, vector<int>, less<int> > maxHeap;

	if (nums1.size())
	{
		for (size_t i = 0; i < nums1.size(); i++)
		{
			if (minHeap.empty() && maxHeap.empty())
			{
				maxHeap.push(nums1[i]);
				continue;
			}				

			if (nums1[i] <= maxHeap.top())
			{
				maxHeap.push(nums1[i]);
				if (maxHeap.size() == minHeap.size()+2)
				{
					int tmp = maxHeap.top();
					maxHeap.pop();
					minHeap.push(tmp);
				}
			}
			else
			{
				minHeap.push(nums1[i]);
				if (minHeap.size() == maxHeap.size() + 1)
				{
					int tmp = minHeap.top();
					minHeap.pop();
					maxHeap.push(tmp);
				}
			}
		}
	}

	if (nums2.size())
	{
		for (size_t i = 0; i < nums2.size(); i++)
		{
			if (minHeap.empty() && maxHeap.empty())
			{
				maxHeap.push(nums2[i]);
				continue;
			}

			if (nums2[i] <= maxHeap.top())
			{
				maxHeap.push(nums2[i]);
				if (maxHeap.size() == minHeap.size() + 2)
				{
					int tmp = maxHeap.top();
					maxHeap.pop();
					minHeap.push(tmp);
				}
			}
			else
			{
				minHeap.push(nums2[i]);
				if (minHeap.size() == maxHeap.size() + 1)
				{
					int tmp = minHeap.top();
					minHeap.pop();
					maxHeap.push(tmp);
				}
			}
		}
	}

	return  (nums1.size() + nums2.size()) & 1 ? (double)maxHeap.top() : (double)((minHeap.top() + maxHeap.top())) / 2.f;

}


// ==================== Test Code ====================

void Test()
{
	

}


int main(int argc, char* argv[])
{
	vector<int> nums1 = { 1,3 };
	vector<int> nums2 = { 2 };

	double mediam1 = findMedianSortedArrays(nums1, nums2);

	vector<int> nums3 = { 1,2 };
	vector<int> nums4= { 3,4 };

	double mediam2 = findMedianSortedArrays(nums3, nums4);

    return 0;
}