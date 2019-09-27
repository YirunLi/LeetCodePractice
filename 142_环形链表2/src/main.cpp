/*
	Create by xiaorun on August th, 2019.
	给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。


*/

#include <iostream>
#include <unordered_map>
#include "ListNode.h"

using namespace std;

// 思路：

// 哈希表法
bool hasCycle(ListNode *head) {
	if (!head)
		return NULL;

	// 记录结点在之前是否出现过
	unordered_map<ListNode*, int> nodeMap;
	ListNode *node = head;
	while (node)
	{
		if (nodeMap.count(node))
			return node;
		else
		{
			nodeMap.insert(make_pair(node, 1));
			node = node->next;
		}

	}

	return NULL;
}

/*
	双指针法:由https://leetcode-cn.com/problems/linked-list-cycle-ii/solution/linked-list-cycle-ii-kuai-man-zhi-zhen-shuang-zhi-/
	中的题解：Linked List Cycle II （快慢指针，双指针法）证明，从快慢指针相遇的点和头结点一起走，就会在入口相遇
*/
ListNode* hasCycle2(ListNode *head) {
	if (!head)
		return NULL;

	ListNode* nodeFast = head;
	ListNode* nodeSlow = head;

	do
	{
		nodeSlow = nodeSlow->next;
		nodeFast = nodeFast->next;
		if (nodeFast)
			nodeFast = nodeFast->next;
		else
			break;
	} while (nodeFast && nodeFast != nodeSlow);

	ListNode* enterNode = NULL;
	if (nodeFast)
	{
		ListNode *nodeTmp = head;
		while (nodeFast != nodeTmp)
		{
			nodeFast = nodeFast->next;
			nodeTmp = nodeTmp->next;
		}
		enterNode = nodeTmp;
	}

	return enterNode;
}


// ==================== Test Code ====================

void Test()
{
	

}


int main(int argc, char* argv[])
{
	ListNode *node1 = new ListNode(3);
	ListNode *node2 = new ListNode(2);
	ListNode *node3 = new ListNode(0);
	ListNode *node4 = new ListNode(-4);

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	//node4->next = node2;

	ListNode *has = hasCycle2(node1);

    return 0;
}