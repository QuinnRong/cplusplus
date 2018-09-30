#include <cstdio>

struct BinaryTreeNode
{
	double mValue;
	BinaryTreeNode* pLeft;
	BinaryTreeNode* pRight;
	BinaryTreeNode(double val): mValue(val), pLeft(nullptr), pRight(nullptr) {}
};

bool Equal(double x, double y)
{
	double MIN = 0.0000001;
	if (x - y < MIN && x - y > -MIN) return true;
	else return false;
}

bool IsSubTree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	if (pRoot2 == nullptr) return true;
	if (pRoot1 == nullptr) return false;

	if (!Equal(pRoot1->mValue, pRoot2->mValue)) return false;
	else
	{
		return IsSubTree(pRoot1->pLeft, pRoot2->pLeft) &&
				IsSubTree(pRoot1->pRight, pRoot2->pRight);
	}
}

bool DoesTree1HasTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	if (pRoot2 == nullptr) return true;
	if (pRoot1 == nullptr) return false;

	if (IsSubTree(pRoot1, pRoot2)) return true;
	else
	{
		return DoesTree1HasTree2(pRoot1->pLeft, pRoot2) ||
				DoesTree1HasTree2(pRoot1->pRight, pRoot2);
	}
}

int main()
{
	BinaryTreeNode myTree1[] = {8,8,7,9,2,4,7};
	myTree1[0].pLeft = &myTree1[1]; myTree1[0].pRight = &myTree1[2];
	myTree1[1].pLeft = &myTree1[3]; myTree1[1].pRight = &myTree1[4];
	myTree1[4].pLeft = &myTree1[5]; myTree1[4].pRight = &myTree1[6];

	BinaryTreeNode myTree2[] = {8,9,2};
	myTree2[0].pLeft = &myTree2[1]; myTree2[0].pRight = &myTree2[2];

	printf("%s\n", DoesTree1HasTree2(myTree1, myTree2)?"yes":"no");
}