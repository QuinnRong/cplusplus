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
	pPivot = LINKED-LIST-PARTITION(pBegin, pEnd)
	LINKED-LIST-QUICKSORT(pBegin, pPivot)
	LINKED-LIST-QUICKSORT(pPivot->next, pEnd)
*/

/*
LINKED-LIST-PARTITION(pBegin, pEnd)
x = pBegin->data
pBack = pBegin 						// back pointer
for pFront = pBack->next to pEnd 	// front pointer
	if pFront->data < x
		pBack = pBack->next
		swap pBack->data with pFront->data
swap pBack->data with pBegin->data
return pBack
*/

ListNode* LinkedListPartition(ListNode* pBegin, ListNode* pEnd)
{
	int x = pBegin->data;
	ListNode* pBack = pBegin;
	ListNode* pFront = pBack->next;
	while (pFront != pEnd->next)					// important! (pFront <= pEnd)
	{
		if (pFront->data < x)
		{
			pBack = pBack->next;
			Swap(pBack->data, pFront->data);
		}
		pFront = pFront->next;
	}
	Swap(pBack->data, pBegin->data);
	return pBack;
}

void LinkedListQuickSort(ListNode* pBegin, ListNode* pEnd)
{	
	if (pBegin != pEnd && pBegin != pEnd->next)		// important! (pBegin < pEnd)
	{
		ListNode* pPivot = LinkedListPartition(pBegin, pEnd);
		LinkedListQuickSort(pBegin, pPivot);
		LinkedListQuickSort(pPivot->next, pEnd);
	}
}

int main()
{
	freopen("05.txt", "r", stdin);
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

	PrintList(arr);

	LinkedListQuickSort(&arr[0], &arr[len - 1]);

	PrintList(arr);

	delete[] arr;
	fclose(stdin);
	return 0;
}
