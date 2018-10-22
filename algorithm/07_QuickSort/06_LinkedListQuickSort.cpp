#include <iostream>
#include <cstdio>

using namespace std;

struct ListNode
{
	int data;
	ListNode* next;
};

void PrintList(ListNode* head)
{
	while (head != nullptr)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

template <class T>
void Swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

/*
LINKED-LIST-QUICKSORT(pBegin, pEnd)
if pBegin != pEnd and pBegin != pEnd->next
	pNewBegin, pPivot, pNewEnd = LINKED-LIST-PARTITION(pBegin, pEnd)
	pLeftBegin = LINKED-LIST-QUICKSORT(pNewBegin, pPivot)
	pRightBegin = LINKED-LIST-QUICKSORT(pPivot->next, pNewEnd)
	pPivot->next = pRightBegin
	return pLeftBegin
*/

/*
LINKED-LIST-PARTITION(pBegin, pEnd)
x = pBegin->data
pPrev = pBegin
pCurr = pBegin->next
while pCurr != pEnd->next and pCurr->data >= x
	pPrev = pCurr
	pCurr = pCurr->next
if pCurr = pEnd
	return pBegin, pBegin, pEnd
pNewBegin = pCurr 		// pCurr->data < x
pLeftTail = pCurr
pRightTail = pPrev
while pCurr != pEnd->next
	pCurr = pCurr->next
	if pCurr->data < x
		pRightTail->next = pCurr
		pRightTail = pCurr
	else
		pLeftTail->next = pCurr
		pLeftTail = pCurr
pLeftTail->next = pBegin
pRightTail->next = NULL
return pNewBegin, pBegin, pRightTail
*/

ListNode* LinkedListPartition(ListNode* pBegin, ListNode* pEnd, ListNode** pNewBegin, ListNode** pNewEnd)
{
	cout << endl;
	PrintList(pBegin);
	cout << "[Partition] pBegin = " << pBegin->data << ", pEnd = " << pEnd->data << endl;
	int x = pBegin->data;
	ListNode* pPrev = nullptr;
	ListNode* pCurr = pBegin;
	while (pCurr != pEnd)
	{
		// cout << "pCurr = " << pCurr->data << endl;
		pPrev = pCurr;
		pCurr = pCurr->next;
		if (pCurr->data < x) break;
	}
	if (pCurr == pEnd)
	{
		*pNewBegin = pBegin;
		*pNewEnd = pEnd;
		cout << "pNewBegin = " << (*pNewBegin)->data << endl;
		cout << "pNewEnd = " << (*pNewEnd)->data << endl;
		return pBegin;
	}
	*pNewBegin = pCurr;
	cout << "pNewBegin = " << (*pNewBegin)->data << endl;
	ListNode* pLeftTail = pCurr;
	ListNode* pRightTail = pPrev;
	while (pCurr != pEnd)
	{
		pCurr = pCurr->next;
		if (pCurr->data < x)
		{
			pLeftTail->next = pCurr;
			pLeftTail = pCurr;
		}
		else
		{
			pRightTail->next = pCurr;
			pRightTail = pCurr;
		}
		cout << "pCurr = " << pCurr->data
		<< ", pLeftTail = " << pLeftTail->data << ", pRightTail = " << pRightTail->data << endl;
	}
	pLeftTail->next = pBegin;
	pRightTail->next = nullptr;
	*pNewEnd = pRightTail;
	cout << "pNewEnd = " << (*pNewEnd)->data << endl;
	return pBegin;
}

void LinkedListQuickSort(ListNode* pBegin, ListNode* pEnd, ListNode** pNewBegin, ListNode** pNewEnd)
{	
	if (pBegin != pEnd && pBegin != pEnd->next)		// important! (pBegin < pEnd)
	{
		*pNewBegin = nullptr;
		*pNewEnd = nullptr;
		ListNode* pPivot = LinkedListPartition(pBegin, pEnd, pNewBegin, pNewEnd);
		cout << "pPivot = " << pPivot->data << endl;
		ListNode* pLeftBegin = nullptr;
		ListNode* pLeftEnd = nullptr;
		LinkedListQuickSort(*pNewBegin, pPivot, &pLeftBegin, &pLeftEnd);
		ListNode* pRightBegin = nullptr;
		ListNode* pRightEnd = nullptr;
		LinkedListQuickSort(pPivot->next, *pNewEnd, &pRightBegin, &pRightEnd);
		// cout << pLeftEnd << " " << pLeftEnd->data << endl;
		// cout << pRightBegin << " " << pRightBegin->data << endl;
		pLeftEnd->next = pRightBegin;
	}
	else
	{
		*pNewBegin = pBegin;
		*pNewEnd = pEnd;
	}
}

int main()
{
	freopen("06.txt", "r", stdin);
	int len;
	cin >> len;
	ListNode* arr = new ListNode[len];
	for (int i = 0; i < len - 1; ++i)
	{
		cin >> arr[i].data;
		arr[i].next = &arr[i + 1];
	}
	cin >> arr[len - 1].data;
	arr[len - 1].next = nullptr;

	// PrintList(arr);

	ListNode *pHead, *pTail;
	LinkedListQuickSort(&arr[0], &arr[len - 1], &pHead, &pTail);

	PrintList(pHead);

	delete[] arr;
	fclose(stdin);
	return 0;
}
