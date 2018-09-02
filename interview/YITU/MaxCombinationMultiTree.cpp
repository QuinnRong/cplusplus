#include <cstdio>
#include <vector>

using namespace std;

struct TreeNode
{
	int mValue;
	vector<TreeNode*> pChilds;
	TreeNode(int val): mValue(val) {}
};

int MaxCombinationCore(TreeNode* pRoot, bool inc)
{
	if (pRoot == nullptr) return 0;
	if (inc)
	{
		int res = pRoot->mValue;
		for (auto child : pRoot->pChilds)
			res += MaxCombinationCore(child, false);
		return res;
	}
	else
	{
		int res = 0;
		for (auto child : pRoot->pChilds)
		{
			int res1 = MaxCombinationCore(child, true);
			int res2 = MaxCombinationCore(child, false);
			res += (res1 > res2)?res1:res2;
		}
		return res;
	} 
}

int MaxCombination(TreeNode* pRoot)
{
	if (pRoot == nullptr) return -1;
	int res1 = MaxCombinationCore(pRoot, true);
	int res2 = MaxCombinationCore(pRoot, false);
	return (res1 > res2)?res1:res2;
}

void PreOrder(TreeNode* pRoot)
{
	if (pRoot == nullptr) return;
	printf("%d ", pRoot->mValue);
	for (auto child : pRoot->pChilds)
		PreOrder(child);
}

int main()
{
	TreeNode myTree[6] = {30,40,60,50,70,20};
	myTree[0].pChilds.push_back(&myTree[1]);
	myTree[0].pChilds.push_back(&myTree[2]);
	myTree[0].pChilds.push_back(&myTree[3]);
	myTree[2].pChilds.push_back(&myTree[4]);
	myTree[2].pChilds.push_back(&myTree[5]);
	PreOrder(myTree); printf("\n");
	printf("%d\n", MaxCombination(myTree));
}