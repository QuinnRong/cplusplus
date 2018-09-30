#include <cstdio>

struct ListNode
{
	int mValue;
	ListNode* pNext = nullptr;
	ListNode() {}
	ListNode(int val): mValue(val), pNext(nullptr) {}
};

void DeleteNode(ListNode** pHead, ListNode* pDelete)
{
	if (pHead == nullptr || *pHead == nullptr || pDelete == nullptr) return;
	if (pDelete->pNext != nullptr)
	{
		pDelete->mValue = pDelete->pNext->mValue;
		pDelete->pNext = pDelete->pNext->pNext;
		delete pDelete->pNext;
	}
	else
	{
		if (*pHead == pDelete)
		{
			delete *pHead;
			pDelete = nullptr;
			*pHead = nullptr;
		}
		else
		{
			ListNode* pCurr = *pHead;
			while (pCurr->pNext != pDelete) pCurr = pCurr->pNext;
			pCurr->pNext = nullptr;
			delete pDelete;
			pDelete == nullptr;
		}
	}
}

void PrintList(ListNode* root)
{
	while (root != nullptr)
	{
		printf("%d ", root->mValue);
		root = root->pNext;
	}
	printf("\n");
}

int main()
{
	ListNode myList[6] = {0,1,2,3,4,5};
	for (int i = 0; i < 5; ++i)
		myList[i].pNext = &myList[i + 1];
	ListNode* pRoot = myList;
	ListNode** root = &pRoot;
	PrintList(*root);
	DeleteNode(root, &myList[1]);
	PrintList(*root);
	DeleteNode(root, &myList[5]);
	PrintList(*root);
	DeleteNode(root, &myList[0]);
	PrintList(*root);
}