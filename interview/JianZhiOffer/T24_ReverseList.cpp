#include <cstdio>

struct ListNode
{
	int mValue;
	ListNode* pNext;
	ListNode(int val): mValue(val), pNext(nullptr) {}
};

ListNode* ReverseList(ListNode* pHead)
{
	if (pHead == nullptr) return nullptr;
	if (pHead->pNext == nullptr) return pHead;

	ListNode* pCurr = pHead->pNext;
	pHead->pNext = nullptr;
	ListNode* pNext = pCurr->pNext;
	while (pNext != nullptr)
	{
		pCurr->pNext = pHead;
		pHead = pCurr;
		pCurr = pNext;
		pNext = pNext->pNext;
	}
	pCurr->pNext = pHead;
	pHead = pCurr;
	pCurr = pNext;
	return pHead;
}

void PrintList(ListNode* pHead)
{
	while (pHead != nullptr)
	{
		printf("%d ", pHead->mValue);
		pHead = pHead->pNext;
	}
	printf("\n");
}

int main()
{
	ListNode myList[] = {1,2,3,4,5,6};
	for (int i = 0; i < sizeof(myList) / sizeof(myList[0]) - 1; ++i)
		myList[i].pNext = &myList[i + 1];
	PrintList(myList);
	ListNode* pReverse = ReverseList(myList);
	PrintList(pReverse);
}