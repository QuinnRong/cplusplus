#include <cstdio>

struct ListNode
{
	int mValue;
	ListNode* pNext = nullptr;
	ListNode(int val): mValue(val), pNext(nullptr) {}
};

ListNode* NodeInLoop(ListNode* pHead)
{
	ListNode* slow = pHead;
	ListNode* fast = pHead;
	while (fast != nullptr && fast->pNext != nullptr)
	{
		fast = fast->pNext->pNext;
		slow = slow->pNext;
		if (fast == slow) return slow;
	}
	return nullptr;
}

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	ListNode* pInLoop = NodeInLoop(pHead);
	if (pInLoop == nullptr) return nullptr;

	ListNode* pNext = pInLoop->pNext;
	int LoopSize = 1;
	while (pNext != pInLoop)
	{
		LoopSize++;
		pNext = pNext->pNext;
	}

	ListNode* pEntry = pHead;
	pNext = pHead;
	for (int i = 0; i < LoopSize; ++i)
		pNext = pNext->pNext;
	while (pEntry != pNext)
	{
		pEntry = pEntry->pNext;
		pNext = pNext->pNext;
	}
	
	return pEntry;
}

int main()
{
	ListNode myList[] = {1,2,3,4,5,6};
	for (int i = 0; i < 5; ++i)
		myList[i].pNext = &myList[i + 1];
	myList[5].pNext = &myList[2];

	ListNode* res = EntryNodeOfLoop(myList);
	if (res == nullptr)
		printf("No loop!\n");
	else
		printf("%d\n", res->mValue);
}