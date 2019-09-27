/*
	Create by xiaorun on August th, 2019.
	
*/

#include <iostream>
#include "ListNode.h"

using namespace std;

// 思路：
// 时间复杂度分析：
ListNode* reserveList(ListNode* head) 
{
	if (!head)
		return NULL;

	ListNode* next = NULL;
	ListNode* pre = NULL;

	while (head)
	{
		next = head->next;
		head->next = pre;
		pre = head;
		head = next;
	}

	return pre;
}

// 思路：先找到需要反转的前后结点，再利用前面的方法反转
// 时间复杂度不高，因为需要扫描两次链表
ListNode* reverseBetween2(ListNode* head, int m, int n) {
	int len = 0;
	ListNode *node = head;
	ListNode *preNode = NULL;
	ListNode *nextNode = NULL;

	while (node)
	{
		if (len == m - 2)
			preNode = node;
		if (len == n)
			nextNode = node;

		node = node->next;
		++len;
	}

	if (preNode)
		node = preNode->next;
	else
		node = head;

	ListNode *pre = nextNode;
	ListNode  *next = NULL;
	while (node != nextNode)
	{
		next = node->next;
		node->next = pre;
		pre = node;
		node = next;
	}
	ListNode *newHead;
	if (preNode)
	{
		preNode->next = pre;
		newHead = head;
	}
	else
		newHead = pre;

	return newHead;
}

ListNode* reverseBetween(ListNode* head, int m, int n)
{
	ListNode* newHead = new ListNode(0);
	ListNode* preNode = newHead;
	newHead->next = head;
	
	for (int i = 0; i < m - 1; i++)
		preNode = preNode->next;

	ListNode* currNode = preNode->next;

	for (int i = m; i < n; i++)
	{
		ListNode* nodeToSwap = currNode->next;
		currNode->next = nodeToSwap->next;
		nodeToSwap->next = preNode->next;
		preNode->next = nodeToSwap;
	}

	return newHead->next;
}

// ==================== Test Code ====================

void Test()
{
	

}


int main(int argc, char* argv[])
{
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);
	ListNode* node4 = new ListNode(4);
	ListNode* node5 = new ListNode(5);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	//ListNode* newHead = reserveList(node1);
	ListNode* newHead = reverseBetween(node1, 1, 5);

    return 0;
}