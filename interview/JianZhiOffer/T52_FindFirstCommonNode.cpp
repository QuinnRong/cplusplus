#include <cstdio>

struct ListNode
{
	int mValue;
	ListNode* pNext;
	ListNode(int val): mValue(val), pNext(nullptr) {}
};

ListNode* FindFirstCommonNode(ListNode* pNode1, ListNode* pNode2)
{
	if (pNode1 == nullptr || pNode2 == nullptr) return nullptr;

	int len1 = 0, len2 = 0;
	ListNode *tmp1 = pNode1, *tmp2 = pNode2;
	while (tmp1 != nullptr)
	{
		++len1;
		tmp1 = tmp1->pNext;
	}
	while (tmp2 != nullptr)
	{
		++len2;
		tmp2 = tmp2->pNext;
	}
	tmp1 = pNode1;
	tmp2 = pNode2;
	if (len1 > len2)
		for (int i = 0; i < len1 - len2; ++i)
			tmp1 = tmp1->pNext;
	else
		for (int i = 0; i < len2 - len1; ++i)
			tmp2 = tmp2->pNext;
	while (tmp1 != nullptr && tmp1 != tmp2)
	{
		tmp1 = tmp1->pNext;
		tmp2 = tmp2->pNext;
	}
	return tmp1;
}

int main()
{
	ListNode myList[7] = {1,2,3,4,5,6,7};
	myList[0].pNext = &myList[1];
	myList[1].pNext = &myList[2];
	myList[2].pNext = &myList[5];
	myList[5].pNext = &myList[7];
	myList[3].pNext = &myList[4];
	myList[4].pNext = &myList[5];

	ListNode *commonNode = FindFirstCommonNode(&myList[0], &myList[3]);
	printf("%d\n", commonNode->mValue);
}