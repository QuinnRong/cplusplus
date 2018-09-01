#include <cstdio>

struct ListNode
{
	int mValue;
	ListNode* pNext;
	ListNode() {}
	ListNode(int val): mValue(val), pNext(nullptr) {}
};

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	ListNode Prev;
	Prev.pNext = nullptr;
	ListNode* pPrev = &Prev;
	while (pHead1 != nullptr || pHead2 != nullptr)
	{
		ListNode* tmp = new ListNode;
		tmp->pNext = nullptr;
		pPrev->pNext = tmp;
		pPrev = tmp;
		if (pHead1 == nullptr)
		{
			tmp->mValue = pHead2->mValue;
			pHead2 = pHead2->pNext;
		}
		else if (pHead2 == nullptr)
		{
			tmp->mValue = pHead1->mValue;
			pHead1 = pHead1->pNext;
		}
		else
		{
			if (pHead1->mValue > pHead2->mValue)
			{
				tmp->mValue = pHead2->mValue;
				pHead2 = pHead2->pNext;
			}
			else
			{
				tmp->mValue = pHead1->mValue;
				pHead1 = pHead1->pNext;
			}
		}
	}
	return Prev.pNext;
}

ListNode* MergeChange(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == nullptr) return pHead2;
	if (pHead2 == nullptr) return pHead1;

	ListNode* pMerge = nullptr;
	if (pHead1->mValue > pHead2->mValue)
	{
		pMerge = pHead2;
		pMerge->pNext = MergeChange(pHead1, pHead2->pNext);
	}
	else
	{
		pMerge = pHead1;
		pMerge->pNext = MergeChange(pHead1->pNext, pHead2);
	}
	return pMerge;
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
	ListNode myList1[] = {1,3,5,7};
	for (int i = 0; i < sizeof(myList1) / sizeof(myList1[0]) - 1; ++i)
		myList1[i].pNext = &myList1[i + 1];
	printf("List1: "); PrintList(myList1);
	ListNode myList2[] = {2,4,6,8};
	for (int i = 0; i < sizeof(myList2) / sizeof(myList2[0]) - 1; ++i)
		myList2[i].pNext = &myList2[i + 1];
	printf("List2: "); PrintList(myList2);

	ListNode* pMerge = Merge(myList1, myList2);
	printf("\nMerge: "); PrintList(pMerge);
	printf("List1: "); PrintList(myList1);
	printf("List2: "); PrintList(myList2);

	pMerge = MergeChange(myList1, myList2);
	printf("\nMerge: "); PrintList(pMerge);
	printf("List1: "); PrintList(myList1);
	printf("List2: "); PrintList(myList2);
}