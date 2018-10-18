#include <iostream>
#include <cstdio>
#include <stdexcept>	/* runtime_error */

#include "heap.h"

using namespace std;

/*
HEAP-MAXIMUM(A)
return A[0]
*/

template <class T>
T HeapMaximum(T* arr, int size)
{	/*
	time: O(1)
	*/
	return arr[0];
}

/*
HEAP-EXTRACT-MAX(A)
if A.heap-size < 1
	error "heap underflow"
max = A[0]
A[0] = A[A.heap-size - 1]
A.heap-size = A.heap-size - 1
MAX-HEAPIFY(A, 0)
*/

template <class T>
T HeapExtractMax(T* arr, int size)
{	/*
	time: O(lgn)
	*/
	if (size < 1) throw runtime_error("heap underflow");
	T max = arr[0];
	arr[0] = arr[size - 1];
	--size;
	MaxHeapify(arr, size, 0);
	return max;
}

/*
HEAP-INCREASE-KEY(A, i, key)
if key < A[i]
	error "new key is smaller than current key"
A[i] = key
while i > 0 and A[PARENT(i)] < A[i]
	swap A[i] with A[PARENT(i)]
	i = PARENT[i]
*/

template <class T>
void HeapIncreaseKey(T* arr, int i, T key)
{	/*
	time: O(lgn)
	*/
	if (key < arr[i]) throw runtime_error("new key is smaller than current key");
	arr[i] = key;
	while (i > 0 && arr[PARENT(i)] < arr[i])
	{
		T tmp = arr[i];
		arr[i] = arr[PARENT(i)];
		arr[PARENT(i)] = tmp;
		i = PARENT(i);
	}
}

/*
MAX-HEAP-INSERT(A, key)
A.heap-size = A.heap-size + 1
A[A.heap-size - 1] = -∞
HEAP_INCREASE_KEY(A, A.heap-size - 1, key)
*/

template <class T>
void MaxHeapInsert(T* arr, int size, T key)
{	/*
	time: O(lgn)
	*/
	++size;
	arr[size - 1] = 0x8fffffff;
	HeapIncreaseKey(arr, size - 1, key);
}

int main()
{
	freopen("05.txt", "r", stdin);
	int len;
	cin >> len;
	int* arr = new int[len];
	for (int i = 0; i < len; ++i)
		cin >> arr[i];

	int size = len;
	int i, key;
	cin >> i >> key;
	HeapIncreaseKey(arr, i, key); PrintHeap(arr, size);

	cout << HeapMaximum(arr, size) << endl;

	while (size > 0)
		cout << HeapExtractMax(arr, size--) << " ";
	cout << endl;

	for (int i = 0; i < len; ++i)
	{
		int key = i;
		MaxHeapInsert(arr, size++, key);
	}
	PrintHeap(arr, size);

	delete[] arr;
	fclose(stdin);
	return 0;
}
