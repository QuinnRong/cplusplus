#include "BinaryTreeNode.h"
#include <cstdio>

void InOrder(BinaryTreeNode* pRoot)
{
    if (pRoot == nullptr) return;
    InOrder(pRoot->pLeft);
    printf("%d ", pRoot->mValue);
    InOrder(pRoot->pRight);
}

void InOrderToKthCore(BinaryTreeNode* pRoot, int& k)
{
    if (pRoot == nullptr) return;
    if (k != 0)
        InOrderToKthCore(pRoot->pLeft, k);
    if (k != 0)
    {
        --k;
        printf("%d ", pRoot->mValue);
    }
    if (k != 0)
        InOrderToKthCore(pRoot->pRight, k);
}

void InOrderToKth(BinaryTreeNode* pRoot, int k)
{
    if (pRoot == nullptr || k <= 0) return;
    InOrderToKthCore(pRoot, k);
}

BinaryTreeNode* InOrderTheKthCore(BinaryTreeNode* pRoot, int& k)
{
    if (pRoot == nullptr) return nullptr;
    BinaryTreeNode* res = nullptr;
    if (k != 0)
        res = InOrderTheKthCore(pRoot->pLeft, k);
    if (k != 0)
    {
        --k;
        if (k == 0) res = pRoot;
    }
    if (k != 0)
        res = InOrderTheKthCore(pRoot->pRight, k);
    return res;
}

BinaryTreeNode* InOrderTheKth(BinaryTreeNode* pRoot, int k)
{
    if (pRoot == nullptr || k <= 0) return nullptr;
    InOrderTheKthCore(pRoot, k);
}

int main()
{
    BinaryTreeNode myTree[] = {5,3,7,2,4,6,8};
    /***
            5(0)
       3(1)       7(2)
    2(3)  4(4) 6(5)  8(6)
    ***/
    printf("%s\n%7d\n%3d%8d\n%d%4d%4d%4d\n\n","Tree:",5,3,7,2,4,6,8);
    myTree[0].pLeft = &myTree[1]; myTree[0].pRight = &myTree[2];
    myTree[1].pLeft = &myTree[3]; myTree[1].pRight = &myTree[4];
    myTree[2].pLeft = &myTree[5]; myTree[2].pRight = &myTree[6];

    printf("inorder: ");
    InOrder(&myTree[0]);
    printf("\n\n");

    for (int k = 1; k <= 7; ++k)
    {
        printf("inorder to [%d]: ", k);
        InOrderToKth(&myTree[0], k);
        printf("\n");
    }

    printf("\n");

    for (int k = 1; k <= 7; ++k)
    {
        printf("inorder the [%d]: ", k);
        BinaryTreeNode* tmp = InOrderTheKth(&myTree[0], k);
        printf("%d\n", tmp->mValue);
    }
}