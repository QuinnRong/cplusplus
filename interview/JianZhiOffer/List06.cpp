#include <cstdio>

struct ListNode
{
	int m_value;
	ListNode* m_next;
	ListNode() {};
	ListNode(int val): m_value(val), m_next(nullptr) {};
};

void PrintListReverse(ListNode* pHead)
{
	if (pHead == nullptr) return;
	PrintListReverse(pHead->m_next);
	printf("%d\t", pHead->m_value);
}

int main()
{
	ListNode *pHead, *pTail;
	pHead = new ListNode(0);
	pTail = new ListNode(1);
	pHead->m_next = pTail;
	PrintListReverse(pHead);
}