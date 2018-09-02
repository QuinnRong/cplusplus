#include <cstdio>

struct ListNode
{
	int mValue;
	ListNode* pNext;
	ListNode(int val): mValue(val), pNext(nullptr) {}
};

int MaxCombinationCore(ListNode* pHead, bool inc)
{
	if (pHead == nullptr) return 0;
	if (inc) return pHead->mValue + MaxCombinationCore(pHead->pNext, false);
	else
	{
		int res1 = MaxCombinationCore(pHead->pNext, true);
		int res2 = MaxCombinationCore(pHead->pNext, false);
		return (res1 > res2)?res1:res2;
	} 
}

int MaxCombination(ListNode* pHead)
{
	if (pHead == nullptr) return -1;
	int res1 = MaxCombinationCore(pHead, true);
	int res2 = MaxCombinationCore(pHead, false);
	return (res1 > res2)?res1:res2;
}

int main()
{
	ListNode myList[] = {30,20,30,40};
	for (int i = 0; i < sizeof(myList) / sizeof(myList[0]) - 1; ++i)
		myList[i].pNext = &myList[i + 1];
	printf("%d\n", MaxCombination(myList));
}