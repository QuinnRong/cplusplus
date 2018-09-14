#include "BinaryTreeNode.h"
#include <cstdio>

void PreOrder(BinaryTreeNode* pRoot)
{
    if (pRoot == nullptr) return;
    printf("%d ", pRoot->mValue);
    PreOrder(pRoot->pLeft);
    PreOrder(pRoot->pRight);
}

void InOrder(BinaryTreeNode* pRoot)
{
    if (pRoot == nullptr) return;
    InOrder(pRoot->pLeft);
    printf("%d ", pRoot->mValue);
    InOrder(pRoot->pRight);
}

void PosOrder(BinaryTreeNode* pRoot)
{
    if (pRoot == nullptr) return;
    PosOrder(pRoot->pLeft);
    PosOrder(pRoot->pRight);
    printf("%d ", pRoot->mValue);
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

    PreOrder(&myTree[0]); printf("(preorder)\n");
    InOrder(&myTree[0]); printf("(inorder)\n");
    PosOrder(&myTree[0]); printf("(posorder)\n");
}
