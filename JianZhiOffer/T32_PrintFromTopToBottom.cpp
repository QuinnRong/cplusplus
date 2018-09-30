#include <cstdio>
#include <queue>

using namespace std;

struct BinaryTreeNode
{
	int mValue;
	BinaryTreeNode* pLeft;
	BinaryTreeNode* pRight;
	BinaryTreeNode(int val): mValue(val), pLeft(nullptr), pRight(nullptr) {}
};

void PrintFromTopToBottomCore(queue<BinaryTreeNode*>& nodeQueue)
{
	int len = nodeQueue.size();
	if (len == 0) return;
	for (int i = 0; i < len; ++i)
	{
		BinaryTreeNode* tmp = nodeQueue.front();
		printf("%d ", tmp->mValue);
		if (tmp->pLeft != nullptr) nodeQueue.push(tmp->pLeft);
		if (tmp->pRight != nullptr) nodeQueue.push(tmp->pRight);
		nodeQueue.pop();
	}
	printf("\n");
	PrintFromTopToBottomCore(nodeQueue);
}

void PrintFromTopToBottom(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr) return;
	queue<BinaryTreeNode*> nodeQueue;
	nodeQueue.push(pRoot);
	PrintFromTopToBottomCore(nodeQueue);
	printf("\n");
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
	PrintFromTopToBottom(myTree);
}