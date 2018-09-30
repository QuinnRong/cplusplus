#include <cstdio>

struct ListNode
{
	int mValue;
	ListNode* pNext;
	ListNode(int val): mValue(val), pNext(nullptr) {}
};

ListNode* FindKthToTail(ListNode* pHead, int k)
{
	if (pHead == nullptr || k < 1) return nullptr;
	ListNode* front = pHead;
	ListNode* back = pHead;
	for (int i = 0; i < k - 1; ++i)
	{
		if (front->pNext == nullptr) return nullptr;
		front = front->pNext;
	}
	while (front->pNext != nullptr)
	{
		front = front->pNext;
		back = back->pNext;
	}
	return back;
}

int main()
{
	ListNode myList[] = {1,2,3,4,5};
	for (int i = 0; i < sizeof(myList) / sizeof(myList[0]) - 1; ++i)
	{
		myList[i].pNext = &myList[i + 1];
	}
	for (int i = 1; i < 10; ++i)
	{
		ListNode* res = FindKthToTail(myList, i);
		if (res != nullptr)
			printf("%d\n", *res);
		else
			printf("nullptr\n");
	}
}