/*
	Create by xiaorun on August th, 2019.
	给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.

*/

#include <iostream>
#include "ListNode.h"

using namespace std;

// 思路：
ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode* p1 = head;
	ListNode* p2 = head;

	int cnt = 0;
	while (p1)
	{
		if (cnt < n)
		{
			p1 = p1->next;
			cnt++;
		}			
		else
		{
			if (!p1->next)
			{
				ListNode* tmpNode = p2->next;
				p2->next = tmpNode->next;
				delete tmpNode;	
				break;		
			}
			else
			{
				p1 = p1->next;
				p2 = p2->next;
			}
		}
	}

	if (!p1)
		head = head->next;

	return head;
}


// 在头结点前加入一个结点，使得删除头结点时无需特殊操作
ListNode* removeNthFromEnd2(ListNode* head, int n) {
	ListNode *newHead = new ListNode(0);
	newHead->next = head;
	ListNode *p1 = newHead;
	ListNode *p2 = newHead;

	for (size_t i = 0; i < n+1 ; i++)
		p1 = p1->next;

	while (p1)
	{
		p1 = p1->next;
		p2 = p2->next;
	}

	p2->next = p2->next->next;

	return newHead->next;

}

// ==================== Test Code ====================

void Test()
{
	

}


int main(int argc, char* argv[])
{
	ListNode* p1 = new ListNode(1);
	ListNode* p2 = new ListNode(2);
	ListNode* p3 = new ListNode(3);
	ListNode* p4 = new ListNode(4);
	ListNode* p5 = new ListNode(5);

	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;

	ListNode* p = removeNthFromEnd2(p1, 5);

    return 0;
}