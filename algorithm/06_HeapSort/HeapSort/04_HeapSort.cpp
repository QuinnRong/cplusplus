#include <iostream>
#include <cstdio>

#include "heap.h"

using namespace std;

/*
HEAPSORT(A)
BUILD-MAX-HEAP(A)
for i = A.length - 1 down to 1
	swap A[0] with A[i]
	A.heap-size = A.heap-size - 1
	MAX-HEAPIFY(A, 0)
*/

template <class T>
void HeapSort(T* arr, int len)
{	/*
	time: O(nlgn)
	*/
	BuildMaxHeap(arr, len);
	int size = len;
	for (int i = len - 1; i > 0; --i)
	{
		T tmp = arr[0];
		arr[0] = arr[i];
		arr[i] = tmp;
		--size;
		MaxHeapify(arr, size, 0);
	}
}

int main()
{
	freopen("04.txt", "r", stdin);
	int len;
	cin >> len;
	int* arr = new int[len];
	for (int i = 0; i < len; ++i)
		cin >> arr[i];

	HeapSort(arr, len);

	PrintHeap(arr, len);

	delete[] arr;
	fclose(stdin);
	return 0;
}