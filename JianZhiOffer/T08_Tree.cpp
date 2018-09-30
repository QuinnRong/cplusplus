#include <cstdio>

struct BinaryTreeNode
{
	char value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	BinaryTreeNode* father;
	BinaryTreeNode() {};
	BinaryTreeNode(char val): value(val), left(nullptr), right(nullptr), father(nullptr) {};
};

BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
	if (pNode == nullptr) return nullptr;

	if (pNode->right != nullptr)
	{
		BinaryTreeNode* tmp = pNode->right;
		while (tmp->left != nullptr) tmp = tmp->left;
		return tmp;
	}
	else if (pNode->father == nullptr) return nullptr;
	else if (pNode->father->left == pNode) return pNode->father;
	else if (pNode->father->right == pNode)
	{
		BinaryTreeNode* tmp = pNode->father;
		while (tmp->father != nullptr && tmp->father->right == tmp) tmp = tmp->father;
		if (tmp->father == nullptr) return nullptr;
		else return tmp->father;
	}
	return nullptr;
}

int main()
{
	BinaryTreeNode tmp[9] = {'a','b','c','d','e','f','g','h','i'};
	tmp[0].left = &tmp[1]; tmp[0].right = &tmp[2];
	tmp[1].left = &tmp[3]; tmp[1].right = &tmp[4]; tmp[1].father = &tmp[0];
	tmp[2].left = &tmp[5]; tmp[2].right = &tmp[6]; tmp[2].father = &tmp[0];
	tmp[3].father = &tmp[1];
	tmp[4].left = &tmp[7]; tmp[4].right = &tmp[8]; tmp[4].father = &tmp[1];
	tmp[5].father = &tmp[2];
	tmp[6].father = &tmp[2];
	tmp[7].father = &tmp[4];
	tmp[8].father = &tmp[4];

	BinaryTreeNode* res = nullptr;
	for (int i = 0; i < 9; ++i)
	{
		res = GetNext(&tmp[i]);
		if (res != nullptr) printf("%c -> %c\n", tmp[i].value, res->value);
		else printf("%c -> %s\n", tmp[i].value, "nullptr");
	}
}
