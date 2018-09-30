#include <cstdio>
#include <stdexcept>

struct BinaryTreeNode
{
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
	BinaryTreeNode() {};
	BinaryTreeNode(int val): value(val), left(nullptr), right(nullptr) {};
};

void PreOrder(BinaryTreeNode* root)
{
	if (root == nullptr) return;
	printf("%d ", root->value);
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(BinaryTreeNode* root)
{
	if (root == nullptr) return;
	InOrder(root->left);
	printf("%d ", root->value);
	InOrder(root->right);
}

void PostOrder(BinaryTreeNode* root)
{
	if (root == nullptr) return;
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->value);
}

BinaryTreeNode* PartConstruct(int* preorder, int* inorder, int preLeft, int preRight, int inLeft, int inRight)
{
	if (preRight < preLeft) return nullptr;
	if (preRight == preLeft)
	{
		if (preorder[preLeft] != inorder[inLeft]) throw std::runtime_error("Invalid Input!");
		else
		{
			BinaryTreeNode* leaf = new BinaryTreeNode(preorder[preLeft]);
			return leaf;
		}
	}
	else
	{
		int split = inLeft;
		while (split <= inRight)
		{
			if (inorder[split] == preorder[preLeft])
			{
				BinaryTreeNode* root = new BinaryTreeNode(preorder[preLeft]);
				root->left = PartConstruct(preorder, inorder, preLeft + 1, preLeft + split - inLeft, inLeft, split - 1);
				root->right = PartConstruct(preorder, inorder, preLeft + split - inLeft + 1, preRight, split + 1, inRight);
				return root;
			}
			++split;
		}
		throw std::runtime_error("Invalid Input!");
	}
}

BinaryTreeNode* ConstructTree(int* preorder, int* inorder, int len)
{
	if (preorder == nullptr || inorder == nullptr || len <= 0) return nullptr;
	return PartConstruct(preorder, inorder, 0, len - 1, 0, len - 1);
}

int main()
{
	BinaryTreeNode tmp[8] = {1,2,4,7,3,5,6,8};
	tmp[0].left = &tmp[1];
	tmp[1].left = &tmp[2];
	tmp[2].right = &tmp[3];
	tmp[0].right = &tmp[4];
	tmp[4].left = &tmp[5];
	tmp[4].right = &tmp[6];
	tmp[6].left = &tmp[7];
	BinaryTreeNode* root = &tmp[0];
	PreOrder(root);	printf("\n");
	InOrder(root); printf("\n");
	PostOrder(root); printf("\n\n");
	
	int preorder[] = {1,2,4,7,3,5,6,8};
	int inorder[] = {4,7,2,1,5,3,8,6};
	root = ConstructTree(preorder, inorder, 8);
	PreOrder(root);	printf("\n");
	InOrder(root); printf("\n");
	PostOrder(root); printf("\n");
}