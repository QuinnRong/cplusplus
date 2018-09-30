#include <cstdio>
#include <vector>

using namespace std;

struct BinaryTreeNode
{
	int mValue;
	BinaryTreeNode* pLeft;
	BinaryTreeNode* pRight;
	BinaryTreeNode(int val): mValue(val), pLeft(nullptr), pRight(nullptr) {}
};

void PrintPath(vector<int>& valueVector)
{
	for (const auto value : valueVector)
		printf("%d ", value);
}

void FindPathCore(BinaryTreeNode*pRoot, vector<int>& valueVector, int target, int& sum)
{
	if (pRoot == nullptr) return;

	valueVector.push_back(pRoot->mValue);
	sum += pRoot->mValue;

	if (pRoot->pLeft == nullptr && pRoot->pRight == nullptr && sum == target)
		PrintPath(valueVector); printf("\n");
	
	if (pRoot->pLeft != nullptr)
		FindPathCore(pRoot->pLeft, valueVector, target, sum);
	if (pRoot->pRight != nullptr)
		FindPathCore(pRoot->pRight, valueVector, target, sum);
	
	valueVector.pop_back();
	sum -= pRoot->mValue;
}

void FindPath(BinaryTreeNode* pRoot, int target)
{
	if (pRoot == nullptr) return;
	vector<int> valueVector;
	int sum = 0;
	FindPathCore(pRoot, valueVector, target, sum);
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
	BinaryTreeNode myTree[] = {10,5,12,4,7};
	myTree[0].pLeft = &myTree[1]; myTree[0].pRight = &myTree[2];
	myTree[1].pLeft = &myTree[3]; myTree[1].pRight = &myTree[4];
	PreOrder(myTree); printf("\n");
	FindPath(myTree, 22);
}