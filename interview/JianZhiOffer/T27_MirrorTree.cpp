#include <cstdio>

struct BinaryTreeNode
{
	int mValue;
	BinaryTreeNode* pLeft;
	BinaryTreeNode* pRight;
	BinaryTreeNode(int val): mValue(val), pLeft(nullptr), pRight(nullptr) {}
};

BinaryTreeNode* MirrorTree(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr) return nullptr;

	MirrorTree(pRoot->pLeft);
	MirrorTree(pRoot->pRight);

	BinaryTreeNode* tmp = pRoot->pLeft;
	pRoot->pLeft = pRoot->pRight;
	pRoot->pRight = tmp;

	return pRoot;
}

void PreOrder(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr) return;
	printf("%d ", pRoot->mValue);
	PreOrder(pRoot->pLeft);
	PreOrder(pRoot->pRight);
}

int main()
{
	BinaryTreeNode myTree[] = {8,6,10,5,7,9,11};
	myTree[0].pLeft = &myTree[1]; myTree[0].pRight = &myTree[2];
	myTree[1].pLeft = &myTree[3]; myTree[1].pRight = &myTree[4];
	myTree[2].pLeft = &myTree[5]; myTree[2].pRight = &myTree[6];
	PreOrder(myTree); printf("\n");
	MirrorTree(myTree);
	PreOrder(myTree); printf("\n");
}