#include <cstdio>
#include <stack>

using namespace std;

struct BinaryTreeNode
{
	int mValue;
	BinaryTreeNode* pLeft;
	BinaryTreeNode* pRight;
	BinaryTreeNode(int val): mValue(val), pLeft(nullptr), pRight(nullptr) {}
};

void PrintPath(stack<BinaryTreeNode*> nodeStack)
{
	if (nodeStack.empty()) return;
	int value = nodeStack.top()->mValue;
	nodeStack.pop();
	PrintPath(nodeStack);
	printf("%d ", value);
}

void FindPathCore(stack<BinaryTreeNode*>& nodeStack, int target, int sum)
{
	if (nodeStack.empty()) return;

	BinaryTreeNode* pNode = nodeStack.top();
	sum += pNode->mValue;
	if (pNode->pLeft == nullptr && pNode->pRight == nullptr && sum == target)
	{
		PrintPath(nodeStack); printf("\n");
	}
	if (pNode->pLeft != nullptr)
	{
		nodeStack.push(pNode->pLeft);
		FindPathCore(nodeStack, target, sum);
	}
	if (pNode->pRight != nullptr)
	{
		nodeStack.push(pNode->pRight);
		FindPathCore(nodeStack, target, sum);
	}
	nodeStack.pop();
	sum -= pNode->mValue;
}

void FindPath(BinaryTreeNode* pRoot, int target)
{
	if (pRoot == nullptr) return;
	stack<BinaryTreeNode*> nodeStack;
	nodeStack.push(pRoot);
	int sum = 0;
	FindPathCore(nodeStack, target, sum);
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