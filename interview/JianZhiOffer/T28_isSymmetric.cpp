#include <cstdio>

struct BinaryTreeNode
{
	int mValue;
	BinaryTreeNode* pLeft;
	BinaryTreeNode* pRight;
	BinaryTreeNode(int val): mValue(val), pLeft(nullptr), pRight(nullptr) {}
};

bool isSymmetric(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	if (pRoot1 == nullptr && pRoot2 == nullptr) return true;
	if (pRoot1 == nullptr || pRoot2 == nullptr) return false;
	if (pRoot1->mValue != pRoot2->mValue) return false;
	return isSymmetric(pRoot1->pLeft, pRoot2->pRight) &&
			isSymmetric(pRoot1->pRight, pRoot2->pLeft);
}

bool isSymmetric(BinaryTreeNode* pRoot)
{
	return isSymmetric(pRoot, pRoot);
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
	BinaryTreeNode myTree1[] = {8,6,6,5,7,7,5};
	myTree1[0].pLeft = &myTree1[1]; myTree1[0].pRight = &myTree1[2];
	myTree1[1].pLeft = &myTree1[3]; myTree1[1].pRight = &myTree1[4];
	myTree1[2].pLeft = &myTree1[5]; myTree1[2].pRight = &myTree1[6];
	PreOrder(myTree1); printf("\n");
	printf("%s\n", isSymmetric(myTree1)?"yes":"no");

	BinaryTreeNode myTree2[] = {8,6,9,5,7,7,5};
	myTree2[0].pLeft = &myTree2[1]; myTree2[0].pRight = &myTree2[2];
	myTree2[1].pLeft = &myTree2[3]; myTree2[1].pRight = &myTree2[4];
	myTree2[2].pLeft = &myTree2[5]; myTree2[2].pRight = &myTree2[6];
	PreOrder(myTree2); printf("\n");
	printf("%s\n", isSymmetric(myTree2)?"yes":"no");

	BinaryTreeNode myTree3[] = {7,7,7,7,7,7};
	myTree3[0].pLeft = &myTree3[1]; myTree3[0].pRight = &myTree3[2];
	myTree3[1].pLeft = &myTree3[3]; myTree3[1].pRight = &myTree3[4];
	myTree3[2].pLeft = &myTree3[5];
	PreOrder(myTree3); printf("\n");
	printf("%s\n", isSymmetric(myTree3)?"yes":"no");
}