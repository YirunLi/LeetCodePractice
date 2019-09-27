/*
	Create by xiaorun on August th, 2019.
	给定一个链表，判断链表中是否有环。

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
		return false;

	// 记录结点在之前是否出现过
	unordered_map<ListNode*, int> nodeMap;
	ListNode *node = head;
	while (node)
	{
		if (nodeMap.count(node))
			return true;
		else
		{
			nodeMap.insert(make_pair(node, 1));
			node = node->next;
		}
			
	}

	return false;
}

// 双指针法
bool hasCycle2(ListNode *head) {
	if (!head)
		return false;

	ListNode* nodeFast = head->next;
	ListNode* nodeSlow = head;

	while (nodeFast)
	{
		if (nodeFast == nodeSlow)
			return true;

		nodeSlow = nodeSlow->next;
		nodeFast = nodeFast->next;
		if (nodeFast)
			nodeFast = nodeFast->next;
		else
			break;
	}

	return false;
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
	node4->next = node2;

	bool has = hasCycle2(node1);

    return 0;
}