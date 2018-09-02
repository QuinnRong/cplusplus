#include <cstdio>

struct BinaryTreeNode
{
	int mValue;
	BinaryTreeNode* pLeft;
	BinaryTreeNode* pRight;
	BinaryTreeNode(int val): mValue(val), pLeft(nullptr), pRight(nullptr) {}
};

void ConvertTreeToListCore(BinaryTreeNode* pRoot, BinaryTreeNode** pTail)
{
	if (pRoot == nullptr) return;

	ConvertTreeToListCore(pRoot->pLeft, pTail);

	pRoot->pLeft = *pTail;
	if (*pTail != nullptr) (*pTail)->pRight = pRoot;
	*pTail = pRoot;
	
	ConvertTreeToListCore(pRoot->pRight, pTail);
}

BinaryTreeNode* ConvertTreeToList(BinaryTreeNode* pRoot)
{
	BinaryTreeNode* pTail = nullptr;
	ConvertTreeToListCore(pRoot, &pTail);

	while (pTail != nullptr && pTail->pLeft != nullptr)
		pTail = pTail->pLeft;

	return pTail;
}

void PreOrder(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr) return;
	printf("%d ", pRoot->mValue);
	PreOrder(pRoot->pLeft);
	PreOrder(pRoot->pRight);
}

void PrintList(BinaryTreeNode* pHead)
{
	BinaryTreeNode* pLast = pHead;
	while (pHead != nullptr)
	{
		printf("%d ", pHead->mValue);
		pLast = pHead;
		pHead = pHead->pRight;
	}
	printf("\n");
	pHead = pLast;
	while (pHead != nullptr)
	{
		printf("%d ", pHead->mValue);
		pHead = pHead->pLeft;
	}
}

int main()
{
	BinaryTreeNode myTree[] = {10,6,14,4,8,12,16};
	myTree[0].pLeft = &myTree[1]; myTree[0].pRight = &myTree[2];
	myTree[1].pLeft = &myTree[3]; myTree[1].pRight = &myTree[4];
	myTree[2].pLeft = &myTree[5]; myTree[2].pRight = &myTree[6];
	PreOrder(myTree); printf("\n");
	PrintList(ConvertTreeToList(myTree));
}