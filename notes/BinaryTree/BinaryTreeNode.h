#ifndef BINARYTREENODE
#define BINARYTREENODE

struct BinaryTreeNode
{
	int mValue;
	BinaryTreeNode* pLeft;
	BinaryTreeNode* pRight;
	BinaryTreeNode() {}
	BinaryTreeNode(int val): mValue(val), pLeft(nullptr), pRight(nullptr) {}
};

#endif