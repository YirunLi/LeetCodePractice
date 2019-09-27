/*
	Create by xiaorun on August th, 2019.
	合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6

*/

#include <iostream>
#include <vector>
#include <queue>
#include"ListNode.h"
#include "BinaryTree.h"

using namespace std;

// 思路1：分治法
// 时间复杂度分析：k个链表，共n个结点
// 每两个链表合并需要n/pow(2,x), 此时共剩下pow(2,x)个链表，所以每次合并的时间复杂度为O(n)
// 一共会执行log k次，因此时间复杂度为O(nlogk)
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
	if (!list1)
		return list2;
	if (!list2)
		return list1;

	ListNode* newHead = new ListNode(0);
	ListNode* pNode = newHead;
	ListNode* p1 = list1;
	ListNode* p2 = list2;
	while (p1 && p2)
	{
		if (p1->val < p2->val)
		{
			pNode->next = p1;
			pNode = pNode->next;
			p1 = p1->next;
		}
		else
		{
			pNode->next = p2;
			pNode = pNode->next;
			p2 = p2->next;
		}		
	}
	if (p1)
		pNode->next = p1;
	if (p2)
		pNode->next = p2;

	return newHead->next;
}

ListNode* mergeKLists1(vector<ListNode*>& lists) {
	if (lists.size() <= 0)
		return NULL;
	if (lists.size() == 1)
		return lists[0];

	ListNode* mergedHead;
	int gap = 1;
	while (gap < lists.size())
	{
		for (int i = 0; i < lists.size() - gap; i+=2*gap)
			lists[i] = mergeTwoLists(lists[i], lists[i + gap]);
		
		gap *= 2;
	}
	
	return lists[0];
}

bool cmp(const ListNode* a, const ListNode* b)
{
	return a->val > b->val;
}

// 思路二：用每个链表的第一列构成优先队列，每次将最小值的结点弹出，将其的next压入
// 弹出时间复杂度O(1), 压入时间复杂度O(logk),因此总时间复杂度O(Nlogk)
ListNode* mergeKLists(vector<ListNode*>& lists) {
	if (lists.size() <= 0)
		return NULL;
	if (lists.size() == 1)
		return lists[0];

	vector<ListNode*> nodesHeap;
	for (size_t i = 0; i < lists.size(); i++)
		nodesHeap.push_back(lists[i]);

	make_heap(nodesHeap.begin(), nodesHeap.end(), cmp);
	
	ListNode* newHead = new ListNode(0);
	ListNode* node = newHead;

	while (!nodesHeap.empty())
	{
		node->next = nodesHeap.front();
		node = node->next;
		pop_heap(nodesHeap.begin(), nodesHeap.end(), cmp);
		nodesHeap.pop_back();

		if (node->next)
		{
			nodesHeap.push_back(node->next);
			push_heap(nodesHeap.begin(), nodesHeap.end(), cmp);
		}
	}

	return newHead->next;
}


// ==================== Test Code ====================

void Test()
{
	

}


int main(int argc, char* argv[])
{
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(4);
	ListNode* n3 = new ListNode(5);
	n1->next = n2;
	n2->next = n3;

	ListNode* n4 = new ListNode(1);
	ListNode* n5 = new ListNode(3);
	ListNode* n6 = new ListNode(4);
	n4->next = n5;
	n5->next = n6;

	ListNode* n7 = new ListNode(2);
	ListNode* n8 = new ListNode(6);
	n7->next = n8;

	vector<ListNode*> lists;
	lists.push_back(n1);
	lists.push_back(n4);
	lists.push_back(n7);

	ListNode* mergedList = mergeKLists(lists);

    return 0;
}