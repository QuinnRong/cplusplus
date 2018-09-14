#include "BinaryTreeNode.h"
#include <cstdio>
#include <vector>

int Height(BinaryTreeNode* pRoot)
{
    if (pRoot == nullptr) return -1;
    int left = Height(pRoot->pLeft);
    int right = Height(pRoot->pRight);
    return 1 + ((left > right) ? left : right);
}

void Height(BinaryTreeNode* pRoot, int& height)
{
    if (pRoot == nullptr)
    {
        height = -1;
        return;
    }
    int left, right;
    Height(pRoot->pLeft, left);
    Height(pRoot->pRight, right);
    height = 1 + ((left > right) ? left : right);
    return;
}

int WeightedHeight(BinaryTreeNode* pRoot)
{
    if (pRoot == nullptr) return 0;
    int left = WeightedHeight(pRoot->pLeft);
    int right = WeightedHeight(pRoot->pRight);
    return pRoot->mValue + ((left > right) ? left : right);
}

bool IsBanancedCore(BinaryTreeNode* pRoot, int& height)
{
    if (pRoot == nullptr)
    {
        height = -1;
        return true;
    }
    int left, right;
    if (IsBanancedCore(pRoot->pLeft, left) && IsBanancedCore(pRoot->pRight, right))
    {
        int diff = left - right;
        if (diff >= -1 && diff <= 1)
        {
            height = 1 + ((left > right) ? left : right);
            return true;
        }
    }
    return false;
}

bool IsBananced(BinaryTreeNode* pRoot)
{
    if (pRoot == nullptr) return true;
    int height;
    return IsBanancedCore(pRoot, height);
}

bool IsBSTCore(BinaryTreeNode* pRoot, int& max, int& min)
{
    if (pRoot == nullptr)
    {
        max = 0x80000000;
        min = 0x7fffffff;
        return true;
    }
    int leftMax, leftMin, rightMax, rightMin;
    if (IsBSTCore(pRoot->pLeft, leftMax, leftMin) && IsBSTCore(pRoot->pRight, rightMax, rightMin))
    {
        if (pRoot->mValue >= leftMax && pRoot->mValue <= rightMin)
        {
            max = (rightMax > pRoot->mValue) ? rightMax : pRoot->mValue;
            min = (leftMin < pRoot->mValue) ? leftMin : pRoot->mValue;
            return true;
        }
    }
    return false;
}

bool IsBST(BinaryTreeNode* pRoot)
{
    if (pRoot == nullptr) return true;
    int max, min;
    return IsBSTCore(pRoot, max, min);
}

void MaxBSTCore(BinaryTreeNode* pRoot, int& max, int& min, int& size, int& maxSize, BinaryTreeNode** res)
{
    if (pRoot == nullptr)
    {
        max = 0x80000000;
        min = 0x7fffffff;
        size = 0;
        return;
    }
    int leftMax, leftMin, leftSize, rightMax, rightMin, rightSize;
    MaxBSTCore(pRoot->pLeft, leftMax, leftMin, leftSize, maxSize, res);
    MaxBSTCore(pRoot->pRight, rightMax, rightMin, rightSize, maxSize, res);

    max = (rightMax > pRoot->mValue) ? rightMax : pRoot->mValue;
    min = (leftMin < pRoot->mValue) ? leftMin : pRoot->mValue;

    if (pRoot->mValue >= leftMax && pRoot->mValue <= rightMin)
    {
        size = 1 + leftSize + rightSize;
        if (size > maxSize)
        {
            maxSize = size;
            *res = pRoot;
        }
    }
    else
        size = 0;
}

int MaxBST(BinaryTreeNode* pRoot, BinaryTreeNode** res)
{
    if (pRoot == nullptr) return 0;
    int max, min, size;
    int maxSize = 0;
    MaxBSTCore(pRoot, max, min, size, maxSize, res);
    return maxSize;
}

void LongestPathFromRootCore(BinaryTreeNode* pRoot, std::vector<int>& tmp, std::vector<int>& res)
{
    if (pRoot == nullptr) return;
    tmp.push_back(pRoot->mValue);
    if (pRoot->pLeft == nullptr && pRoot->pRight == nullptr && tmp.size() > res.size())
    {
        res.clear();
        for (auto item : tmp)
            res.push_back(item);
    }
    LongestPathFromRootCore(pRoot->pLeft, tmp, res);
    LongestPathFromRootCore(pRoot->pRight, tmp, res);
    tmp.pop_back();
}

std::vector<int> LongestPathFromRoot(BinaryTreeNode* pRoot)
{
    std::vector<int> tmp, res;
    LongestPathFromRootCore(pRoot, tmp, res);
    return res;
}

void HeaviestPathFromRootCore(BinaryTreeNode* pRoot, std::vector<int>& tmp, std::vector<int>& res, int& sum, int& max)
{
    if (pRoot == nullptr) return;
    tmp.push_back(pRoot->mValue);
    sum += pRoot->mValue;
    if (pRoot->pLeft == nullptr && pRoot->pRight == nullptr && sum > max)
    {
        res.clear();
        for (auto item : tmp)
            res.push_back(item);
        max = sum;
    }
    HeaviestPathFromRootCore(pRoot->pLeft, tmp, res, sum, max);
    HeaviestPathFromRootCore(pRoot->pRight, tmp, res, sum, max);
    tmp.pop_back();
    sum -= pRoot->mValue;
}

std::vector<int> HeaviestPathFromRoot(BinaryTreeNode* pRoot)
{
    std::vector<int> tmp, res;
    int sum = 0, max = 0;
    HeaviestPathFromRootCore(pRoot, tmp, res, sum, max);
    return res;
}

void InOrder(BinaryTreeNode* pRoot)
{
    if (pRoot == nullptr) return;
    InOrder(pRoot->pLeft);
    printf("%d ", pRoot->mValue);
    InOrder(pRoot->pRight);
}

int main()
{
    /***
           1
       2       3
    4     5       16
        7            8
    ***/
    BinaryTreeNode myTree[] = {1,2,3,4,5,16,7,8};
    myTree[0].pLeft = &myTree[1]; myTree[0].pRight = &myTree[2];
    myTree[1].pLeft = &myTree[3]; myTree[1].pRight = &myTree[4];
    myTree[2].pRight = &myTree[5];
    myTree[4].pLeft = &myTree[6];
    myTree[5].pRight = &myTree[7];
    printf("\n%s\n%7d\n%3d%8d\n%d%4d%9d\n%4d%12d\n\n","Tree:",1,2,3,4,5,16,7,8);
    InOrder(&myTree[0]); printf("(inorder)\n\n");

    printf("Height is %d.\n", Height(&myTree[0]));
    std::vector<int> path = LongestPathFromRoot(&myTree[0]);
    printf("Longest path is: ");
    for (auto item : path)
        printf("%d ", item);
    printf("\n\n");

    printf("Weighted height is %d.\n", WeightedHeight(&myTree[0]));
    path = HeaviestPathFromRoot(&myTree[0]);
    printf("Heaviest path is: ");
    for (auto item : path)
        printf("%d ", item);
    printf("\n\n");

    printf("%s\n", IsBananced(&myTree[0])?"Balanced.":"Not bananced.");
    printf("%s\n", IsBST(&myTree[0])?"BST.":"Not BST.");
    BinaryTreeNode* bst = nullptr;
    printf("MaxBST size: %d\n", MaxBST(&myTree[0], &bst));
    printf("Root of the BST: %d\n", bst->mValue);

    /***
           5
       2       7
    1     4       8
        3            16
    ***/
    myTree[0].mValue = 5; myTree[1].mValue = 2; myTree[2].mValue = 7;
    myTree[3].mValue = 1; myTree[4].mValue = 4; myTree[5].mValue = 8;
    myTree[6].mValue = 3; myTree[7].mValue = 16;
    printf("\n%s\n%7d\n%3d%8d\n%d%4d%9d\n%4d%12d\n\n","Tree:",5,2,7,1,4,8,3,16);
    InOrder(&myTree[0]); printf("(inorder)\n\n");

    printf("Height is %d.\n", Height(&myTree[0]));
    path = LongestPathFromRoot(&myTree[0]);
    printf("Longest path is: ");
    for (auto item : path)
        printf("%d ", item);
    printf("\n\n");

    printf("Weighted height is %d.\n", WeightedHeight(&myTree[0]));
    path = HeaviestPathFromRoot(&myTree[0]);
    printf("Heaviest path is: ");
    for (auto item : path)
        printf("%d ", item);
    printf("\n\n");

    printf("%s\n", IsBananced(&myTree[0])?"Balanced.":"Not bananced.");
    printf("%s\n", IsBST(&myTree[0])?"BST.":"Not BST.");
    bst = nullptr;
    printf("MaxBST size: %d\n", MaxBST(&myTree[0], &bst));
    printf("Root of the BST: %d\n", bst->mValue);

    /***
           17
       2       7
    1     4       8
        3            16
    ***/
    myTree[0].mValue = 17;
    printf("\n%s\n%7d\n%3d%8d\n%d%4d%9d\n%4d%12d\n\n","Tree:",17,2,7,1,4,8,3,16);
    InOrder(&myTree[0]); printf("(inorder)\n\n");

    printf("Height is %d.\n", Height(&myTree[0]));
    path = LongestPathFromRoot(&myTree[0]);
    printf("Longest path is: ");
    for (auto item : path)
        printf("%d ", item);
    printf("\n\n");

    printf("Weighted height is %d.\n", WeightedHeight(&myTree[0]));
    path = HeaviestPathFromRoot(&myTree[0]);
    printf("Heaviest path is: ");
    for (auto item : path)
        printf("%d ", item);
    printf("\n\n");

    printf("%s\n", IsBananced(&myTree[0])?"Balanced.":"Not bananced.");
    printf("%s\n", IsBST(&myTree[0])?"BST.":"Not BST.");
    bst = nullptr;
    printf("MaxBST size: %d\n", MaxBST(&myTree[0], &bst));
    printf("Root of the BST: %d\n", bst->mValue);
}