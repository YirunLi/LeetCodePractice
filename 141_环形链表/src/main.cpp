/*
	Create by xiaorun on August th, 2019.
	����һ�������ж��������Ƿ��л���

	Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ���� ��� pos �� -1�����ڸ�������û�л���

*/

#include <iostream>
#include <unordered_map>
#include "ListNode.h"

using namespace std;

// ˼·��

// ��ϣ��
bool hasCycle(ListNode *head) {
	if (!head)
		return false;

	// ��¼�����֮ǰ�Ƿ���ֹ�
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

// ˫ָ�뷨
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