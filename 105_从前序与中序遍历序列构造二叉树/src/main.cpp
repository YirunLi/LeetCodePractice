	/*
	Create by xiaorun on August th, 2019.
	根据一棵树的前序遍历与中序遍历构造二叉树。
*/

#include <iostream>
#include <vector>

#include "BinaryTree.h"

using namespace std;
using namespace BinaryTree;

// 思路：
	TreeNode* buildTreeCore(vector<int>& preorder, vector<int>& inorder, int preStartIdx, int preEndIdx, int inStartIdx, int inEndIdx) {
		if (preStartIdx > preEndIdx)
			return NULL;

		int root = preorder[preStartIdx];
		TreeNode *pNode = new TreeNode(root);

		int idx = inStartIdx;
		while (inorder[idx] != root && idx <= inEndIdx)
			idx++;

		int leftLength = idx - inStartIdx;
		int rightLength = inEndIdx - idx;

		pNode->left = buildTreeCore(preorder, inorder, preStartIdx + 1, preStartIdx + leftLength, inStartIdx, idx - 1);
		pNode->right = buildTreeCore(preorder, inorder, preStartIdx + 1 + leftLength, preEndIdx, idx + 1, inEndIdx);

		return pNode;
	}

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		TreeNode *pHead = NULL;
		if (preorder.size() <= 0 || inorder.size() != preorder.size())
			return pHead;

		pHead = buildTreeCore(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);

		return pHead;
	}


// ==================== Test Code ====================

void Test()
{
	

}


int main(int argc, char* argv[])
{
	vector<int> preorder = { 1, 2, 4, 8, 9, 5, 10, 11, 3, 6, 12, 13, 7, 14, 15 };
	vector<int> inorder = { 8, 4, 9, 2, 10, 5, 11, 1, 12, 6, 13, 3, 14, 7, 15 };

	TreeNode *pHead = buildTree(preorder, inorder);

    return 0;
}