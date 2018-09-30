#include <cstdio>
#include <stdexcept>

struct BinarySearchTree
{
	int mValue;
	BinarySearchTree* pLeft;
	BinarySearchTree* pRight;
	BinarySearchTree(int val): mValue(val), pLeft(nullptr), pRight(nullptr) {}
};

BinarySearchTree* KthNodeCore(BinarySearchTree* pRoot, int &k)
{
	if (pRoot == nullptr) return nullptr;

	BinarySearchTree* res = nullptr;
	if (k != 0)
		res = KthNodeCore(pRoot->pLeft, k);
	if (k != 0)
	{
		--k;
		if (k == 0) res = pRoot;
		printf("%d ", pRoot->mValue);
	}
	if (k != 0)
		res = KthNodeCore(pRoot->pRight, k);
	return res;
}

BinarySearchTree* KthNode(BinarySearchTree* pRoot, int k)
{
	if (pRoot == nullptr) return nullptr;
	if (k <= 0) throw std::runtime_error("Invalid K!");
	return KthNodeCore(pRoot, k);
}

void InOrder(BinarySearchTree* pRoot)
{
	if (pRoot == nullptr) return;
	InOrder(pRoot->pLeft);
	printf("%d\n", pRoot->mValue);
	InOrder(pRoot->pRight);
}

int main()
{
	BinarySearchTree myTree[] = {5,3,7,2,4,6,8};
	myTree[0].pLeft = &myTree[1]; myTree[0].pRight = &myTree[2];
	myTree[1].pLeft = &myTree[3]; myTree[1].pRight = &myTree[4];
	myTree[2].pLeft = &myTree[5]; myTree[2].pRight = &myTree[6];

	for (int i = 1; i <= 7; ++i)
	{
		BinarySearchTree* res = KthNode(&myTree[0], i);
		printf("%d\n", res->mValue);
	}
	// InOrder(&myTree[0]);
}